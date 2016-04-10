CXX=g++
CPPFLAGS=-std=c++11

testRun: huffencode.o unittest.o
	$(CXX) huffencode.o unittest.o -o testRun $(CPPFLAGS)

huffencode.o: ../huffencode.cpp ../huffencode.h
	$(CXX) -c ../huffencode.cpp $(CPPFLAGS)

unittest.o: unittest.cpp unittest.h
	$(CXX) -c unittest.cpp $(CPPFLAGS)	

clean:
	@rm -f *.o testRun
