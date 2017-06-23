crear: ./src/pruebaLista.c ./include/miLista.h ./lib/libfunciones.so ./obj/pruebaLista.o
	gcc -I./include -L./lib -Wall ./src/pruebaLista.c -o ./prueba
./lib/libfunciones.so: ./src/funciones.c ./include/miLista.h
	gcc -shared -Fpic ./src/funciones.c -o ./lib/libfunciones.so
./obj/pruebaLista.o: ./src/pruebaLista.c
	gcc -c -Wall -Fpic ./src/funciones.c -o ./obj/pruebaLista.o

clean:
	rm ./obj/*
	rm ./lib/*
	rm ./prueba
	
