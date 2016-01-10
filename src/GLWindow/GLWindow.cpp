#include "GLWindowConfig.h"
#include "GLWindowImpl.h"

namespace game{
namespace window{

	GLWindow::GLWindow(game::config::GameConfig & gc){
		m_pGLWindowImpl=new GLWindowImpl(gc);
	}

	GLWindow::~GLWindow(){
		if (m_pGLWindowImpl)
			delete m_pGLWindowImpl;
	}

}
}