mtest1:../../GameConfig/GameConfig.cpp ../../../include/GameConfig.h test1.cpp
	g++ ../../GameConfig/GameConfig.cpp  test1.cpp\
		-o test1 -lboost_program_options -lboost_system -lboost_filesystem\
		-I../../../include/ -std=c++11

run1:test1
	./test1 --file=../../../res/config.xml