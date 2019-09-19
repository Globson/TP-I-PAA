all: main.c
	gcc main.c -o EXEC

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
