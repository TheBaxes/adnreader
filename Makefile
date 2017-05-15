CXXFLAGS=-std=c++11 -O3

geneExtractor: main.o graph.o scanner.o
	$(CXX) ${CXXFLAGS} -o $@ $^

main.o: main.cpp graph.h scanner.h

graph.o: graph.cpp graph.h

scanner.o: scanner.cpp scanner.h

clean:
	rm -f *.o
	rm -f geneExtractor
