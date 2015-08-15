main: test.cpp Trixel.o Cartesian.o
	g++ -o test test.cpp Cartesian.o Trixel.o
Trixel.o: Trixel.h Constants.h Trixel.cpp Cartesian.o
	g++ -c Trixel.cpp
Cartesian.o: Cartesian.h Cartesian.cpp
	g++ -c Cartesian.cpp
clean:
	rm *.o test
