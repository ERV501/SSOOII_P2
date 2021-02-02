Enrique Rodriguez Villafranca

Manual de usuario:

-Mediante el uso del makefile proporcionado:

	1)Ejecutar "make" en nuestra terminal
	2)Ejecutar "make main"
	3)Ejecutar cuaalquiera de los siguientes comandos que se proporcionan:
		"make test" = buscar en "17 LEYES DEL TRABAJO EN EQUIPO.txt" la palabra "Nelson" lanzando 2 hilos
		"make test2" = buscar en "21 LEYES DEL LIDERAZGO - JOHN C. MAXWELL.txt" la palabra "Nelson" lanzando 2 hilos
		"make test3" = buscar en "25 MANERAS DE GANARSE A LA GENTE - .txt" la palabra "escrito" lanzando 2 hilos

		"make error_max_threads" = comprobar error debido a un número demasiado alto de hilos con respecto a los soportados por nuestro HW
		"make error_min_threads" = comprobar debido a la introduccion de un numero incorrecto de hilos (nagativo o 0)

-Si se desea compilar y ejecutar sin uso del Makefile proporcionado:
	1) Copiar los archivos dentro de ./exec y colocar en su exterior, de tal modo que se encuentren junto a la carpeta ./include
	2) Hacer lo mismo con el material proporcionado en ./material
	3) Compilacion:
		g++ *.cpp -o SSOOIIGLE -pthread -std=c++11 -I ./include
	
	4) Ejecucion:
		./SSOOIIGLE <"nombre_archivo.txt"> <palabra> <numero_hilos>
	
		Ej: ./SSOOIIGLE "17 LEYES DEL TRABAJO EN EQUIPO.txt" Nelson 4





Diseño:

 Consta de 4 archivos: SSOOIIGLE, Organizer, Thread_structure, Result_structure
	
	SSOOIIGLE se encarga de comprobar que todos los argumentos sean correctos para un funcionamiento apropiado,
	de crear y de repartir el trabajo a cada hilo (así como de controlar su terminación) y de imprimir los resultados
	en el orden correspondiente, mediante la lectura de cada hilo almacenado en un vector (se usa un vector 
	y no un array ya que de esta forma, su tamaño es dinámico).

	Organizer es ejecutado por cada uno de los hilos creados por SSOOIIGLE y se encarga de abrir el archivo correspondiente, de desplazarse
	a la línea inicial de ese hilo y de analizar ese fragmento de texto. Todos los hilos mantienen un semáforo de tipo mutex,
	para asegurar el acceso exclusivo a la lista de resultados (mediante lock_guard).
	
	Thread_structure almacena la informacion correspondiente a cada hilo (linea de inicio, linea final, palabra a buscar, archivo,
	su número de hilo y el resultado que se imprimirá)
	Cada hilo mantiene una lista de resultados individual debido a que cada uno de ellos puede encontrar más de un resultado 
	en su fragmento de texto. Se trata de una lista dado que así podremos añadir en la última posición y extraer de la primera posición
	para mantener el orden a la hora de imprimir.
	
	Este resultado es de tipo Result_structure, y corresponde a nuestra estructura de datos, que contiene la información a imprimir.
	Es decir: la palabra anterior, la objetivo, la posterior y la linea en la que se encuentra.
	
