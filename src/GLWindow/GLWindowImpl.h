#ifndef __GLWINDOWIMPL__H__
#define __GLWINDOWIMPL__H__

#include "GLWindowConfig.h"

namespace game{
namespace window{

	class GLWindow::GLWindowImpl
	{
	public:
		GLWindowImpl(game::config::GameConfig & gc);
		~GLWindowImpl();
	
	private:

		SDL_Window * m_pWindow;
		SDL_GLContext     m_stContext;	
	};

}
}

#endif