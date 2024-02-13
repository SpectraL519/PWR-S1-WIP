all: zad1

zad1: main pal 
	clang -o zad1 l3z1_main.o l3z1_pal.o

main: l3z1_main.c 
	clang -c l3z1_main.c 

pal: l3z1_pal.c 
	clang -c l3z1_pal.c 

clean:
	rm -f zad1 *.o *~