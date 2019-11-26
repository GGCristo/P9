programa: G2CNF.o Fichero.o CFG.o Produccion.o 
	g++ G2CNF.o Fichero.o CFG.o Produccion.o -o G2CNF 
	./G2CNF input.gra output.gra
CNF2DFA.o: G2CNF.cpp
	g++ -c G2CNF.cpp
Fichero.o: Fichero.cpp
	g++ -c Fichero.cpp
CFG.o: CFG.cpp
	g++ -c CFG.cpp
Produccion.o: Produccion.cpp
	g++ -c Produccion.cpp
depurar: 
	g++ G2CNF.cpp Fichero.cpp CFG.cpp Produccion.cpp -Wall -g -o G2CNF 

clean: 
	rm -R *.o output.gra G2CNF 
   
