all: zad3

zad3: main phi prime
	clang -o zad3 l3z3_main.o l3z3_phi.o l3z3_prime.o -lm 

main: l3z3_main.c 
	clang -c l3z3_main.c 

phi: l3z3_phi.c 
	clang -c l3z3_phi.c 

prime: l3z3_prime.c 
	clang -c l3z3_prime.c 

clean:
	rm -f zad3 *.o *~
