compile:
	@gcc -o fork fork.c
run: compile
	@./fork
clean:
	rm -f fork *o
