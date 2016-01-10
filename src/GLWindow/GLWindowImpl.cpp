#include "GLWindowImpl.h"

namespace game{
namespace window{

	GLWindow::GLWindowImpl::GLWindowImpl(game::config::GameConfig & gc){
		if (SDL_Init(SDL_INIT_VIDEO)<0){
			std::cerr<<"初始化视频系统失败。"<<std::endl;
			std::exit(0);
		}
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,
			gc.get<int>("GLVersionMajor"));
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,
			gc.get<int>("GLVersionMinor"));
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			(gc.get<bool>("GLProfileCore"))?
			SDL_GL_CONTEXT_PROFILE_CORE:
			SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
		m_pWindow=SDL_CreateWindow(gc.get<std::string>("GLWindowTitle").c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			gc.get<int>("GLWindowWidth"),gc.get<int>("GLWindowHeight"),
			 SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (m_pWindow==0){
			std::cerr<<"创建窗口失败，退出。"<<std::endl;
			SDL_Quit();
			std::exit(0);
		}
		m_stContext=SDL_GL_CreateContext(m_pWindow);
		if (m_stContext==0){
			std::cerr<<"无法创建OpenGL上下文，退出。"<<std::endl;
			SDL_Quit();
			std::exit(0);
		}
		glewExperimental=GL_TRUE;
		if (glewInit()!=GLEW_OK){
			std::cerr<<"初始化GLEW失败，退出。"<<std::endl;
			SDL_Quit();
			std::exit(0);
		}
		if (SDL_GL_SetSwapInterval( 1 ) <0){
			std::cerr<<"无法绑定上下文，退出。"<<std::endl;
			SDL_Quit();
			std::exit(0);
		}
	}

	GLWindow::GLWindowImpl::~GLWindowImpl(){
		SDL_DestroyWindow(m_pWindow);
		m_pWindow=0;
		m_stContext=0;
	}

}
}