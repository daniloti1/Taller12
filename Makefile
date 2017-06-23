crear: ./src/pruebaLista.c ./include/miLista.h ./lib/libmilista.so ./obj/pruebaLista.o
	gcc -I./include -L./lib -Wall ./src/pruebaLista.c -o ./prueba
./lib/libmilista.so: ./src/Lista_*.c ./include/miLista.h
	gcc -shared -Fpic -I./include ./src/Lista_*.c -o ./lib/libmilista.so
./obj/pruebaLista.o: ./src/pruebaLista.c
	gcc -c -Wall -Fpic ./src/pruebaLista.c -o ./obj/pruebaLista.o
./src/Lista_Anterior.c:
	gcc -Wall -I./include ./src/Lista_Anterior.c -fPIC -c -o ./obj/Lista_Anterior.o
./src/Lista_Buscar.c:
	gcc -Wall -I./include ./src/Lista_Buscar.c -fPIC -c -o ./obj/Lista_Buscar.o
./src/Lista_Conteo.c:
	gcc -Wall -I./include ./src/Lista_Conteo.c -fPIC -c -o ./obj/Lista_Conteo.o
./src/Lista_Inicializar.c:
	gcc -Wall -I./include ./src/Lista_Inicializar.c -fPIC -c -o ./obj/Lista_Inicializar.o
./src/Lista_InsertarAntes.c:
	gcc -Wall -I./include ./src/Lista_InsertarAntes.c -fPIC -c -o ./obj/Lista_InsertarAntes.o
./src/Lista_InsertarDespues.c:
	gcc -Wall -I./include ./src/Lista_InsertarDespues.c -fPIC -c -o ./obj/Lista_InsertarDespues.o
./src/Lista_InsertarFin.c:
	gcc -Wall -I./include ./src/Lista_InsertarFin.c -fPIC -c -o ./obj/Lista_InsertarFin.o
./src/Lista_InsertarInicio.c:
	gcc -Wall -I./include ./src/Lista_InsertarInicio.c -fPIC -c -o ./obj/Lista_InsertarInicio.o
./src/Lista_Primero.c:
	gcc -Wall -I./include ./src/Lista_Primero.c -fPIC -c -o ./obj/Lista_Primero.o
./src/Lista_Sacar.c:
	gcc -Wall -I./include ./src/Lista_Sacar.c -fPIC -c -o ./obj/Lista_Sacar.o
./src/Lista_SacarTodos.c:
	gcc -Wall -I./include ./src/Lista_SacarTodos.c -fPIC -c -o ./obj/Lista_SacarTodos.o
./src/Lista_Siguiente.c:
	gcc -Wall -I./include ./src/Lista_Siguiente.c -fPIC -c -o ./obj/Lista_Siguiente.o
./src/Lista_Ultimo.c:
	gcc -Wall -I./include ./src/Lista_Ultimo.c -fPIC -c -o ./obj/Lista_Ultimo.o
./src/Lista_Vacia.c:
	gcc -Wall -I./include ./src/Lista_Vacia.c -fPIC -c -o ./obj/Lista_Vacia.o


clean:
	rm ./obj/*
	rm ./lib/*
	rm ./prueba
	
