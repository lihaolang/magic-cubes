/**
*@defgroup 	GameConfig 	游戏配置模块
*@author	lihaolang
*@version	1.0
*@date		2015
*@{
*/

#ifndef __GAME__CONFIG__H__
#define __GAME__CONFIG__H__

#include <boost/any.hpp>
#include "StdAfx.h"

/*
*@name GameConfig
*@{
*/

namespace game{
namespace config{

	class GameConfig
	{
	public:
		/*
		*构造函数，接受命令行，或空
		*@pargam [int] argc 命令行数量
		*@pargam [char * * argv 命令行数组
		*/
		GameConfig(int argc,char * argv []);
		/*
		*析构函数
		*/
		~GameConfig();

		template <typename Type>
		inline Type get(std::string tag){
			return boost::any_cast<Type>(getConfig(tag));
		}

	private:

		boost::any getConfig(std::string name);
	
	private:

		/*
		*@name GameConfig::GameConfigImpl
		*@{
		*/
		class GameConfigImpl;
		/**@}*/

		GameConfigImpl * m_pGameConfigImpl;

	};

}
}

/**@}*/

#endif

/** @} */