CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

sspapp: sspapp.o minpriority.o graph.o
	$(CXX) -o sspapp sspapp.o minpriority.o graph.o

sspapp.o : sspapp.cpp sspapp.h graph.h minpriority.h

graph.o: graph.cpp graph.h sspapp.h minpriority.h

minpriority.o : minpriority.cpp minpriority.h sspapp.h graph.h



clean:
	rm -f *.o sspapp
