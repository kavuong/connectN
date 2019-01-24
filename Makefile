connectn.out: board.o inputValidation.o main.o move.o win.o
	gcc -g -Wall -Werror -o connectn.out board.o inputValidation.o main.o move.o win.o

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

inputValidation.o: inputValidation.c inputValidation.h
	gcc -g -Wall -Werror -c inputValidation.c

main.o: main.c board.h move.h inputValidation.h
	gcc -g -Wall -Werror -c main.c

move.o: move.c board.h inputValidation.h move.h win.h
	gcc -g -Wall -Werror -c move.c

win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -f *.o *.out