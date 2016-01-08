#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>
#include "GameConfigHead.h"

namespace game{
namespace config{

	namespace bp=boost::program_options;
	namespace bf=boost::filesystem;
	namespace bpt=boost::property_tree;


	std::string parse_cmd(int argc,char * argv []){

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

	void parse_config_file(std::string filename,ConfigMap & cm){
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

		resp=resdir;
		resp/=pt.get<std::string>("GameConfig.AudiosResDir","audios");
		if (!bf::exists(resp)){
			std::cerr<<"无此路径："<<resp<<"，退出。"<<std::endl;
			std::exit(0);
		}else{
			cm.insert(ConfigPair("AudiosDir",resp.string()));
		}

		resp=resdir;
		resp/=pt.get<std::string>("GameConfig.ShadersResDir","shaders");
		if (!bf::exists(resp)){
			std::cerr<<"无此路径："<<resp<<"，退出。"<<std::endl;
			std::exit(0);
		}else{
			cm.insert(ConfigPair("ShadersDir",resp.string()));
		}

		cm.insert(ConfigPair("GameName",pt.get<std::string>
			("GameConfig.GameName","Magic-Cubes游戏")));

	}

}
}