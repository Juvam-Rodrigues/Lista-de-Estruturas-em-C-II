OBJS = exe\main.o exe\turma.o
MAIN = src\main.c
INCLUDE = include\aluno.h include\turma.h
TURMA = src\turma.c

exec: $(OBJS)
	gcc -o exe\exec $(OBJS)

exe\main.o: $(MAIN)
	gcc -c $(MAIN) -o exe\main.o

exe\turma.o: $(TURMA) $(INCLUDE)
	gcc -c src/turma.c -o exe/turma.o

run: exec
	.\exe\exec

clean:
	cmd /C "del /Q exe\*.exe exe\*.o"