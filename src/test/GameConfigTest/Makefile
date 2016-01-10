SOURCE_PATH=../../GameConfig
INCLUDE_PATH=../../../include
RESOURCE_PATH=../../../res

TEST_NEED=${SOURCE_PATH}/GameConfig.cpp ${INCLUDE_PATH}/GameConfig.h\
	${SOURCE_PATH}/GameConfigHead.h ${SOURCE_PATH}/Parser.cpp
COMPILE_NEED=${SOURCE_PATH}/GameConfig.cpp \
	${SOURCE_PATH}/Parser.cpp\
	-lboost_program_options -lboost_system -lboost_filesystem\
	-I${INCLUDE_PATH}/ -std=c++11 -g
CPP_COMPILE=g++

TEST_ARGS=--file=${RESOURCE_PATH}/config.xml

test1.out:${TEST_NEED} test1.cpp
	${CPP_COMPILE} -o test1.out test1.cpp ${COMPILE_NEED}

test2.out:${TEST_NEED} test2.cpp
	${CPP_COMPILE} -o test2.out test2.cpp ${COMPILE_NEED}

testsuit1:test1.out
	./test1.out ${TEST_ARGS}

testsuit2:test2.out
	./test2.out ${TEST_ARGS}