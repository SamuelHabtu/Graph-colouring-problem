cc = gcc
flags = -Wall -std=c99 -g

gcp: main.o graph.o
	$(cc) $(flags) $^ -o $@

main.o: main.c graph.h
	$(cc) $(flags) -c $< -o $@

graph.o: graph.c graph.h
	$(cc) $(flags) -c $< -o $@

.PHONEY: clean
clean: gcp
	rm -r -f *.o
