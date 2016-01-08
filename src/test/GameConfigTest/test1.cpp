#include "GameConfig.h"

int main(int argc,char * argv[]){
	using namespace game::config;

	GameConfig gc(argc,argv);
	std::cout<<boost::any_cast<std::string>(gc.getConfig("ImagesDir"));
}