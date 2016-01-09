#include "GameConfig.h"

int main(int argc,char * argv[]){
	using namespace game::config;

	GameConfig gc(argc,argv);
	std::cout<<gc.get<std::string>("ShaderResDir")<<
		gc.get<std::string>("ModelResDir")<<std::endl;

	std::cout<<std::boolalpha<<gc.get<bool>("GLProfileCore")<<std::endl;
}