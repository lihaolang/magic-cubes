SOURCE_PATH=../../GameConfig
INCLUDE_PATH=../../../include
RESOURCE_PATH=../../../res

TEST_NEED=${SOURCE_PATH}/GameConfig.cpp ${INCLUDE_PATH}/GameConfig.h\
	${SOURCE_PATH}/GameConfigHead.h ${SOURCE_PATH}/Parser.cpp
COMPILE_NEED=${SOURCE_PATH}/GameConfig.cpp \
	${SOURCE_PATH}/Parser.cpp\
	-lboost_program_options -lboost_system -lboost_filesystem\
	-I${INCLUDE_PATH}/ -std=c++11
CPP_COMPILE=g++

TEST_ARGS=--file=${RESOURCE_PATH}/config.xml

mtest1:${TEST_NEED} test1.cpp
	${CPP_COMPILE} -o test1 test1.cpp ${COMPILE_NEED}

mtest2:${TEST_NEED} test2.cpp
	${CPP_COMPILE} -o test2 test2.cpp ${COMPILE_NEED}

testsuit1:test1
	./test1 ${TEST_ARGS}

testsuit2:test2
	./test2 ${TEST_ARGS}