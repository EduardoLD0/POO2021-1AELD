#
VIEW := View
CONTROLLER := Controller
MODEL := Model

debug := -ggdb3

all: programa
programa: main view controllerJuego controllerInicializador controllerCombate character heroe enemigo item pocion pocionVida pocionDefensa pocionDebilitadora pocionAtaque arma ataque ataqueComun ataqueDebilitador ataqueResistencia ataqueCuracion ataqueParalizador posicion mazmorra
	g++ ${debug} -o  ejecutable.exe main.o view.o controllerJuego.o controllerInicializador.o controllerCombate.o character.o heroe.o enemigo.o item.o pocion.o pocionVida.o pocionDefensa.o pocionDebilitadora.o pocionAtaque.o arma.o ataque.o ataqueComun.o ataqueDebilitador.o ataqueResistencia.o ataqueCuracion.o ataqueParalizador.o posicion.o mazmorra.o
main: main.cpp
	g++ -c ${debug} main.cpp
view: ${VIEW}/view.cpp ${VIEW}/view.h
	g++ -c ${debug} ${VIEW}/view.cpp
controllerJuego: ${CONTROLLER}/controllerJuego.cpp ${CONTROLLER}/controllerJuego.h
	g++ -c ${debug} ${CONTROLLER}/controllerJuego.cpp
controllerInicializador: ${CONTROLLER}/controllerInicializador.cpp ${CONTROLLER}/controllerInicializador.h
	g++ -c ${debug} ${CONTROLLER}/controllerInicializador.cpp
controllerCombate: ${CONTROLLER}/controllerCombate.cpp ${CONTROLLER}/controllerCombate.h
	g++ -c ${debug} ${CONTROLLER}/controllerCombate.cpp
character: ${MODEL}/character.cpp ${MODEL}/character.h
	g++ -c ${debug} ${MODEL}/character.cpp
heroe: ${MODEL}/heroe.cpp ${MODEL}/heroe.h
	g++ -c ${debug} ${MODEL}/heroe.cpp
enemigo: ${MODEL}/enemigo.cpp ${MODEL}/enemigo.h
	g++ -c ${debug} ${MODEL}/enemigo.cpp
item: ${MODEL}/item.cpp ${MODEL}/item.h
	g++ -c ${debug} ${MODEL}/item.cpp
pocion: ${MODEL}/pocion.cpp ${MODEL}/pocion.h
	g++ -c ${debug} ${MODEL}/pocion.cpp
pocionVida: ${MODEL}/pocionVida.cpp ${MODEL}/pocionVida.h
	g++ -c ${debug} ${MODEL}/pocionVida.cpp
pocionDefensa: ${MODEL}/pocionDefensa.cpp ${MODEL}/pocionDefensa.h
	g++ -c ${debug} ${MODEL}/pocionDefensa.cpp
pocionDebilitadora: ${MODEL}/pocionDebilitadora.cpp ${MODEL}/pocionDebilitadora.h
	g++ -c ${debug} ${MODEL}/pocionDebilitadora.cpp
pocionAtaque: ${MODEL}/pocionAtaque.cpp ${MODEL}/pocionAtaque.h
	g++ -c ${debug} ${MODEL}/pocionAtaque.cpp
arma: ${MODEL}/arma.cpp ${MODEL}/arma.h
	g++ -c ${debug} ${MODEL}/arma.cpp
ataque: ${MODEL}/ataque.cpp ${MODEL}/ataque.h
	g++ -c ${debug} ${MODEL}/ataque.cpp
ataqueComun: ${MODEL}/ataqueComun.cpp ${MODEL}/ataqueComun.h
	g++ -c ${debug} ${MODEL}/ataqueComun.cpp
ataqueDebilitador: ${MODEL}/ataqueDebilitador.cpp ${MODEL}/ataqueDebilitador.h
	g++ -c ${debug} ${MODEL}/ataqueDebilitador.cpp
ataqueResistencia: ${MODEL}/ataqueResistencia.cpp ${MODEL}/ataqueResistencia.h
	g++ -c ${debug} ${MODEL}/ataqueResistencia.cpp
ataqueParalizador: ${MODEL}/ataqueParalizador.cpp ${MODEL}/ataqueParalizador.h
	g++ -c ${debug} ${MODEL}/ataqueParalizador.cpp
ataqueCuracion: ${MODEL}/ataqueCuracion.cpp ${MODEL}/ataqueCuracion.h
	g++ -c ${debug} ${MODEL}/ataqueCuracion.cpp
posicion: ${MODEL}/posicion.cpp ${MODEL}/posicion.h
	g++ -c ${debug} ${MODEL}/posicion.cpp
mazmorra: ${MODEL}/mazmorra.cpp ${MODEL}/mazmorra.h
	g++ -c ${debug} ${MODEL}/mazmorra.cpp