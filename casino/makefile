#
VIEW := View
CONTROLLER := Controller
MODEL := Model

debug := -ggdb3

all: programa
programa: Casino Juego Mayor13 DosColores Slots Jugador Vista Controlador main
	g++ ${debug} -o  a.exe main.o Casino.o Juego.o Mayor13.o DosColores.o Slots.o Jugador.o View.o Controller.o
Casino: ${MODEL}/Casino.cpp ${MODEL}/Casino.h ${MODEL}/Juego.h
	g++ -c ${debug} ${MODEL}/Casino.cpp
Juego: ${MODEL}/Juego.cpp ${MODEL}/Juego.h ${MODEL}/Jugador.h
	g++ -c ${debug} ${MODEL}/Juego.cpp
Mayor13: ${MODEL}/Mayor13.cpp ${MODEL}/Mayor13.h ${MODEL}/Juego.h
	g++ -c ${debug} ${MODEL}/Mayor13.cpp
DosColores: ${MODEL}/DosColores.cpp ${MODEL}/DosColores.h ${MODEL}/Juego.h
	g++ -c ${debug} ${MODEL}/DosColores.cpp
Slots: ${MODEL}/Slots.cpp ${MODEL}/Slots.h ${MODEL}/Juego.h
	g++ -c ${debug} ${MODEL}/Slots.cpp
Jugador: ${MODEL}/Jugador.cpp ${MODEL}/Jugador.h
	g++ -c ${debug} ${MODEL}/Jugador.cpp
Vista: ${VIEW}/View.cpp ${VIEW}/View.h ${CONTROLLER}/Controller.h
	g++ -c ${debug} ${VIEW}/View.cpp
Controlador: ${CONTROLLER}/Controller.cpp ${CONTROLLER}/Controller.h ${MODEL}/Jugador.h ${MODEL}/Casino.h
	g++ -c ${debug} ${CONTROLLER}/Controller.cpp
main: main.cpp ${VIEW}/View.h
	g++ -c ${debug} main.cpp