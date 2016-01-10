#ifndef __GLWINDOW__H__
#define __GLWINDOW__H__

#include "StdAfx.h"

namespace game{

namespace config{
	class GameConfig;
}

namespace window{

	class GLWindow{
	public:
		GLWindow(game::config::GameConfig &);
		~GLWindow();
	private:
		class GLWindowImpl;
		GLWindowImpl * m_pGLWindowImpl;

	private:
		GLWindow & operator = (const GLWindow&);
		GLWindow(const GLWindow &);
	};

}
}

#endif