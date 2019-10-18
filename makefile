all: main.c Sources/menu.c Sources/labirinto.c Sources/dados.c Sources/gerador.c
	gcc main.c -o EXEC Sources/menu.c Sources/labirinto.c Sources/dados.c Sources/gerador.c

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC
