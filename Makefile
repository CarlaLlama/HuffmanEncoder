CXX=g++
CPPFLAGS=-std=c++11

huffencode:	huffencode.o driver.o
	$(CXX) -o huffencode driver.o huffencode.o $(CPPFLAGS)

huffencode.o: huffencode.cpp huffencode.h
	$(CXX) -c -o huffencode.o huffencode.cpp $(CPPFLAGS)

driver.o: driver.cpp huffencode.h
	$(CXX) -c -o driver.o driver.cpp $(CPPFLAGS)

clean:
	@rm -f *.o huffencode