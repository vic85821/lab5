lab5:main.o lab5.o
	g++ -o lab5 main.o lab5.o
lab2.o:lab5.cpp lab5.h
	g++ -c lab2.cpp
main.o:main.cpp lab5.h
	g++ -c main.cpp
clean:
	rm *.o


