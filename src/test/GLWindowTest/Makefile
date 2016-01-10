test1.out:test1.cpp libgameconfig.a libglwindow.a
	g++ test1.cpp libgameconfig.a libglwindow.a\
		-lSDL2 -lGLEW -lGL -lGLU -lpthread\
		-lboost_system -lboost_filesystem -lboost_program_options\
		-I../../../include -std=c++11 -o test1.out

libgameconfig.a:gameconfig.o parser.o
	ar -rv libgameconfig.a gameconfig.o parser.o
gameconfig.o:../../GameConfig/GameConfig.cpp
	g++ -c ../../GameConfig/GameConfig.cpp -o gameconfig.o -I../../../include
parser.o:../../GameConfig/Parser.cpp
	g++ -c ../../GameConfig/Parser.cpp -o parser.o -I../../../include

libglwindow.a:glwindowimpl.o glwindow.o
	ar -rv libglwindow.a glwindowimpl.o glwindow.o

glwindowimpl.o:../../GLWindow/GLWindowImpl.cpp
	g++ -c ../../GLWindow/GLWindowImpl.cpp -o glwindowimpl.o\
		-I../../../include
glwindow.o:../../GLWindow/GLWindow.cpp
	g++ -c ../../GLWindow/GLWindow.cpp -o glwindow.o\
		-I../../../include
