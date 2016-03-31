CXX=g++
CPPFLAGS=-std=c++11

volimg:	volimage.o driver.o
	$(CXX) -o huffencode driver.o volimage.o $(CPPFLAGS)

volimage.o: volimage.cpp volimage.h
	$(CXX) -c -o volimage.o volimage.cpp $(CPPFLAGS)

driver.o: driver.cpp volimage.h
	$(CXX) -c -o driver.o driver.cpp $(CPPFLAGS)

clean:
	@rm -f *.o huffencode