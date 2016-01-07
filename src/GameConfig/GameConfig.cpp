/**
*@defgroup 	GameConfig 	游戏配置模块的实现
*@author	lihaolang
*@version	1.0
*@date		2015
*@{
*/
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>
#include <boost/any.hpp>
#include <map>
#include "GameConfig.h"

namespace game{
namespace config{

	namespace bp=boost::program_options;
	namespace bf=boost::filesystem;
	namespace bpt=boost::property_tree;

	typedef std::map<std::string,boost::any> ConfigMap;
	typedef std::pair<std::string,boost::any>  ConfigPair;

	static inline std::string 	parse_cmd(int argc,char * argv []);
	static inline void	parse_config_file(std::string filename,ConfigMap & cm);

	class GameConfig::GameConfigImpl{
	public:

		GameConfigImpl(int argc,char * argv[]);
		~GameConfigImpl();
	private:
		ConfigMap m_stConfigMap;
	};

	GameConfig::GameConfig(int argc,char * argv[]){
		m_pGameConfigImpl=new GameConfigImpl(argc,argv);
	}

	GameConfig::~GameConfig(){
		delete m_pGameConfigImpl;
	}

	GameConfig::GameConfigImpl::GameConfigImpl(int argc,char * argv []){
		std::string filename=parse_cmd(argc,argv);
		m_stConfigMap.insert(ConfigPair("filename",filename));
		parse_config_file(filename,m_stConfigMap);
	}

	GameConfig::GameConfigImpl::~GameConfigImpl(){

	}

	static inline std::string parse_cmd(int argc,char * argv []){

		using namespace bp;

		variables_map vm;
		options_description opts("Magic-Cubes游戏");
		opts.add_options()
			("version,v","显示版本")
			("help,h","显示帮助")
			("file,f",value<std::string>()
				->default_value("../res/config.xml")
				->implicit_value("../res/config.xml")
				,"指定配置文件");

		store(parse_command_line(argc,argv,opts),vm);

		if (vm.count("help")){
			std::cout<<opts<<std::endl;
			std::exit(0);
		}

		if (vm.count("version")){
			std::cout<<"Version:1.0"<<std::endl;
			std::exit(0);
		}

		return vm["file"].as<std::string>();

	}	

	static inline void parse_config_file(std::string filename,ConfigMap & cm){
		using namespace bpt;

		ptree pt;
		bf::path p(filename);
		bf::path resdir=p.parent_path();
		if (!bf::exists(resdir)){
			std::cerr<<"无此路径，退出。"<<std::endl;
			std::exit(0);
		}
		read_xml(filename,pt);

		bf::path resp=resdir;
		resp/=pt.get<std::string>("GameConfig.ImageResDir","images");
		if (!bf::exists(resp)){
			std::cerr<<"无此路径："<<resp<<"，退出。"<<std::endl;
			std::exit(0);
		}else{
			cm.insert(ConfigPair("ImagesDir",resp.string()));
		}
	}

}
}

/**@}*/