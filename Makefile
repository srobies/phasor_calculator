CC=gcc
CPPFLAGS=-Wall -Werror
OBJDIR=obj
objects=phasor.o main.o calculator.o
phasor_files=phasor.cpp main.cpp
calculator_files= $(phasor_files) + calculator.cpp

make:
	g++ -Wall -Werror -g -c $(calculator_files)
	g++ -g -o calculator $(objects)

phasor:
	g++ -Wall -Werror -c $(phasor_files)
	g++ -g -o phasor phasor.o main.o
