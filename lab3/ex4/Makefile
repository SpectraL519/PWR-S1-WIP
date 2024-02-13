all: zad4

zad4: main newagent north south east west distance
	clang -o zad4 l3z4_main.o l3z4_newagent.o l3z4_north.o l3z4_south.o l3z4_east.o l3z4_west.o l3z4_distance.o -lm 

main: l3z4_main.c 
	clang -c l3z4_main.c 

newagent: l3z4_newagent.c 
	clang -c l3z4_newagent.c

north: l3z4_north.c 
	clang -c l3z4_north.c 

south: l3z4_south.c 
	clang -c l3z4_south.c 

east: l3z4_east.c 
	clang -c l3z4_east.c 

west: l3z4_west.c 
	clang -c l3z4_west.c 

distance: l3z4_distance.c 
	clang -c l3z4_distance.c 

clean:
	rm -f zad4 *.o *~