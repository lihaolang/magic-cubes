#ifndef __GAME__CONFIG__HEAD__H__
#define __GAME__CONFIG__HEAD__H__

#include <map>
#include "GameConfig.h"

namespace game{
namespace config{

	typedef std::map<std::string,boost::any> ConfigMap;
	typedef std::pair<std::string,boost::any>  ConfigPair;

	/*
	*命令分析函数
	*@pragam [int] argc
	*@pragam [char * *] cm
	*/
	std::string 	parse_cmd(int argc,char * argv []);
	/*
	*选项
	* --help/-h 	显示帮助
	*--version/-v 	显示版本
	*--file/-f 	指定配置文件
	*/

	/*
	*配置分析函数
	*@pragam [std::string] filename 配置文件路径
	*@pragam [ConfigMap&] cm 	 配置信息
	*/
	void	parse_config_file(std::string filename,ConfigMap & cm);
	/*
	*配置信息：
	*GameName	游戏名称	std::string
	*ImagesDir	图片库路径	std::string
	*AudiosDir	音频库路径	std::string
	*ModelsDir	模型库路径	std::string
	*ShadersDir	着色器路径	std::string
	*/

}
}

#endif