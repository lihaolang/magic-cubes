#include <thread>
#include <chrono>
#include "GameConfig.h"
#include "GLWindow.h"

int main(int argc,char * argv[]){
	game::config::GameConfig gc(argc,argv);
	game::window::GLWindow win(gc);
	std::this_thread::sleep_for(std::chrono::seconds(1));
}