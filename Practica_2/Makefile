DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRMAIN := ./
DIRMATERIAL := material/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi -pthread -std=c++11
LDLIBS := -lpthread -lrt
CC := g++

all : dirs SSOOIIGLE Organizer Thread_Structure Result_Structure

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

SSOOIIGLE: 
	$(CC) -o $(DIROBJ)SSOOIIGLE.o $(DIRSRC)SSOOIIGLE.cpp $(CFLAGS)

Organizer:
	$(CC) -o $(DIROBJ)Organizer.o $(DIRSRC)Organizer.cpp $(CFLAGS)

Thread_Structure:
	$(CC) -o $(DIROBJ)Thread_Structure.o $(DIRSRC)Thread_Structure.cpp $(CFLAGS)

Result_Structure:
	$(CC) -o $(DIROBJ)Result_Structure.o $(DIRSRC)Result_Structure.cpp $(CFLAGS)

main:
	$(CC) -o $(DIREXE)SSOOIIGLE $(DIROBJ)SSOOIIGLE.o $(DIROBJ)Organizer.o $(DIROBJ)Thread_Structure.o $(DIROBJ)Result_Structure.o -pthread -std=c++11

test:
    #SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>
	./$(DIREXE)SSOOIIGLE $(DIRMATERIAL)"17 LEYES DEL TRABAJO EN EQUIPO.txt" Nelson 2

test2:
    #SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>
	./$(DIREXE)SSOOIIGLE $(DIRMATERIAL)"21 LEYES DEL LIDERAZGO - JOHN C. MAXWELL.txt" Nelson 2

test3:
    #SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>
	./$(DIREXE)SSOOIIGLE $(DIRMATERIAL)"25 MANERAS DE GANARSE A LA GENTE - .txt" escrito 2
	
error_max_threads:
    #SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>
	./$(DIREXE)SSOOIIGLE $(DIRMATERIAL)"25 MANERAS DE GANARSE A LA GENTE - .txt" escrito 17

error_min_threads:
    #SSOOIIGLE <nombre_fichero> <palabra> <numero_hilos>
	./$(DIREXE)SSOOIIGLE $(DIRMATERIAL)"25 MANERAS DE GANARSE A LA GENTE - .txt" escrito -1

clean : 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
