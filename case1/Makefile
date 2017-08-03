case1 : main.o sub_case.o
	g++ -o case1 main.o sub_case.o

main.o : main.cpp sub_case.h
	g++ -c main.cpp

sub_case.o : sub_case.cpp
	g++ -c sub_case.cpp

clean : 
	rm case1 *.o 
