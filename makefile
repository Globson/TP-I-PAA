all: main.c Sources/Funcs.c
	gcc main.c -o EXEC Sources/Funcs.c

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
