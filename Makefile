OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Ciudad.o Cjt_productos.o Cjt_rios.o Barco.o
	g++ -o program.exe program.o Ciudad.o Cjt_productos.o Cjt_rios.o Barco.o
	rm -f *.o

program.o: program.cc Barco.hh Cjt_productos.hh Ciudad.hh Cjt_rios.hh
	g++ -c program.cc $(OPCIONS) 

Barco.o: Barco.cc Barco.hh
	g++ -c Barco.cc $(OPCIONS)

Cjt_productos.o:Cjt_productos.cc Cjt_productos.hh
	g++ -c Cjt_productos.cc $(OPCIONS)

Ciudad.o: Ciudad.cc Ciudad.hh
	g++ -c Ciudad.cc $(OPCIONS)

Cjt_rios.o: Cjt_rios.cc Cjt_rios.hh
	g++ -c Cjt_rios.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
