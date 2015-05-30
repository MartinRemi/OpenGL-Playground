LIBS=-lsfml-system -lsfml-window -lsfml-graphics -framework OpenGL

all: 
	rm -f *.o main
	g++ -c *.cpp
	g++ -o main *.o $(LIBS)