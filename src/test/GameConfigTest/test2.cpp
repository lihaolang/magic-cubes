#include "GameConfig.h"

int main(int argc,char * argv []){
	using namespace game::config;

	GameConfig gc(argc,argv);

	std::cout<<gc.get<std::string>("ImagesDir")<<std::endl;
}