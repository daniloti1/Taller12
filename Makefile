crear: ./src/pruebaLista.c ./include/miLista.h ./lib/libmilista.so ./obj/pruebaLista.o
	gcc -I./include -L./lib -Wall ./src/pruebaLista.c ./lib/libmilista.so -o ./prueba
./lib/libmilista.so: ./obj/Lista_Anterior.o ./obj/Lista_Buscar.o ./obj/Lista_Conteo.o ./obj/Lista_Inicializar.o ./obj/Lista_InsertarAntes.o ./obj/Lista_InsertarDespues.o ./obj/Lista_InsertarFin.o ./obj/Lista_InsertarInicio.o ./obj/Lista_Primero.o ./obj/Lista_Sacar.o ./obj/Lista_SacarTodos.o ./obj/Lista_Siguiente.o ./obj/Lista_Ultimo.o ./obj/Lista_Vacia.o ./include/miLista.h
	gcc -shared -Fpic -I./include ./obj/Lista_*.o -o ./lib/libmilista.so
./obj/pruebaLista.o: ./src/pruebaLista.c
	gcc -c -Wall -I./include -Fpic ./src/pruebaLista.c -o ./obj/pruebaLista.o
./obj/Lista_Anterior.o:
	gcc -Wall -I./include ./src/Lista_Anterior.c -fPIC -c -o ./obj/Lista_Anterior.o
./obj/Lista_Buscar.o:
	gcc -Wall -I./include ./src/Lista_Buscar.c -fPIC -c -o ./obj/Lista_Buscar.o
./obj/Lista_Conteo.o:
	gcc -Wall -I./include ./src/Lista_Conteo.c -fPIC -c -o ./obj/Lista_Conteo.o
./obj/Lista_Inicializar.o:
	gcc -Wall -I./include ./src/Lista_Inicializar.c -fPIC -c -o ./obj/Lista_Inicializar.o
./obj/Lista_InsertarAntes.o:
	gcc -Wall -I./include ./src/Lista_InsertarAntes.c -fPIC -c -o ./obj/Lista_InsertarAntes.o
./obj/Lista_InsertarDespues.o:
	gcc -Wall -I./include ./src/Lista_InsertarDespues.c -fPIC -c -o ./obj/Lista_InsertarDespues.o
./obj/Lista_InsertarFin.o:
	gcc -Wall -I./include ./src/Lista_InsertarFin.c -fPIC -c -o ./obj/Lista_InsertarFin.o
./obj/Lista_InsertarInicio.o:
	gcc -Wall -I./include ./src/Lista_InsertarInicio.c -fPIC -c -o ./obj/Lista_InsertarInicio.o
./obj/Lista_Primero.o:
	gcc -Wall -I./include ./src/Lista_Primero.c -fPIC -c -o ./obj/Lista_Primero.o
./obj/Lista_Sacar.o:
	gcc -Wall -I./include ./src/Lista_Sacar.c -fPIC -c -o ./obj/Lista_Sacar.o
./obj/Lista_SacarTodos.o:
	gcc -Wall -I./include ./src/Lista_SacarTodos.c -fPIC -c -o ./obj/Lista_SacarTodos.o
./obj/Lista_Siguiente.o:
	gcc -Wall -I./include ./src/Lista_Siguiente.c -fPIC -c -o ./obj/Lista_Siguiente.o
./obj/Lista_Ultimo.o:
	gcc -Wall -I./include ./src/Lista_Ultimo.c -fPIC -c -o ./obj/Lista_Ultimo.o
./obj/Lista_Vacia.o:
	gcc -Wall -I./include ./src/Lista_Vacia.c -fPIC -c -o ./obj/Lista_Vacia.o


clean:
	rm ./obj/*
	rm ./lib/*
	rm ./prueba
	
