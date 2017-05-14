CXXFLAGS=-std=c++11 -O3

geneExtractor: main.o graph.o
	$(CXX) ${CXXFLAGS} -o $@ $^

main.o: main.cpp

graph.o: graph.cpp graph.h

clean:
	rm -f *.o
	rm -f geneExtractor
