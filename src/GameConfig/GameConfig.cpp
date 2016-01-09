/**
*@defgroup 	GameConfig 	游戏配置模块的实现
*@author	lihaolang
*@version	1.0
*@date		2015
*@{
*/

#include "GameConfigHead.h"

namespace game{
namespace config{

	class GameConfig::GameConfigImpl{
	public:

		GameConfigImpl(int argc,char * argv[]);
		~GameConfigImpl();

		boost::any getConfig(std::string name){
			ConfigMap::iterator ret=m_stConfigMap.find(name);
			if (ret==m_stConfigMap.end()){
				std::cerr<<"没有此配置，退出。"<<std::endl;
				std::exit(0);
			}
			return ret->second;
		}
	private:
		ConfigMap m_stConfigMap;
	};

	GameConfig::GameConfig(int argc,char * argv[]){
		m_pGameConfigImpl=new GameConfigImpl(argc,argv);
	}

	GameConfig::~GameConfig(){
		delete m_pGameConfigImpl;
	}

	boost::any GameConfig::getConfig(std::string name){
		return m_pGameConfigImpl->getConfig(name);
	}

	GameConfig::GameConfigImpl::GameConfigImpl(int argc,char * argv []){
		std::string filename=parse_cmd(argc,argv);
		m_stConfigMap.insert(ConfigPair("filename",filename));
		parse_config_file(filename,m_stConfigMap);
	}

	GameConfig::GameConfigImpl::~GameConfigImpl(){

	}

}
}

/**@}*/