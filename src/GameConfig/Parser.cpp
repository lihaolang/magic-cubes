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

	inline void parse_item(ConfigMap & cm,bpt::ptree & pt){
		using namespace bpt;
		std::string type=pt.get<std::string>("<xmlattr>.type","None");
		std::string tag=pt.get<std::string>("<xmlattr>.tag","None");
		if (tag=="None"){
			std::cerr<<"在配置文件中没有标识符"<<std::endl;
			std::exit(0);
		}
		if (type=="string"){
			cm.insert(ConfigPair(tag,pt.get_value<std::string>()));
		}else if (type=="int"){
			cm.insert(ConfigPair(tag,pt.get_value<int>()));
		}else if (type=="bool"){
			cm.insert(ConfigPair(tag,pt.get_value<bool>()));
		}
	}

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
		read_xml(filename,pt);
		ptree  child=pt.get_child("GameConfig");
		ptree::iterator it=child.begin();
		for (;it!=child.end();++it){
			if ((*it).first=="Item"){
				ptree & ip=(*it).second;
				parse_item(cm,ip);
			}
		}

	}

}
}