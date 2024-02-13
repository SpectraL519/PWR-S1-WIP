all: zad2

zad2: main f sol 
	clang -o zad2 l3z2_main.o l3z2_f.o l3z2_sol.o -lm 

main: l3z2_main.c 
	clang -c l3z2_main.c 

f: l3z2_f.c 
	clang -c l3z2_f.c 

rozw: l3z2_sol.c 
	clang -c l3z2_sol.c 

clean:
	rm -f zad2 *.o *~