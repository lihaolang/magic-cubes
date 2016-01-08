#include "GameConfig.h"

int main(int argc,char * argv[]){
	using namespace game::config;

	GameConfig gc(argc,argv);
	std::cout<<boost::any_cast<std::string>(gc.getConfig("ImagesDir"))<<
		std::endl<<boost::any_cast<std::string>(gc.getConfig("ShadersDir"))
		<<std::endl;

	std::cout<<std::boolalpha<<boost::any_cast<bool>
		(gc.getConfig("GLProfileCore"))<<std::endl;
}