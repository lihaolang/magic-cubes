SOURCE_PATH=../../GameConfig
INCLUDE_PATH=../../../include
RESOURCE_PATH=../../../res

mtest1:${SOURCE_PATH}/GameConfig.cpp ${INCLUDE_PATH}/GameConfig.h test1.cpp\
	${SOURCE_PATH}/GameConfigHead.h ${SOURCE_PATH}/Parser.cpp
	g++ ${SOURCE_PATH}/GameConfig.cpp  test1.cpp\
		${SOURCE_PATH}/Parser.cpp\
		-o test1 -lboost_program_options -lboost_system -lboost_filesystem\
		-I${INCLUDE_PATH}/ -std=c++11

testsuit1:test1
	./test1 --file=${RESOURCE_PATH}/config.xml