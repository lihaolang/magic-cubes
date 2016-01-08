#include "GameConfig.h"

int main(int argc,char * argv []){
	using namespace game::config;

	GameConfig gc(argc,argv);

	std::cout<<as<std::string>(gc.getConfig("ImagesDir"))<<std::endl;
}