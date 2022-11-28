all: exe-target
CC := gcc

exe-target:
	@echo "Building the executable..." 
	@${CC} -c aniascii.c
	@${CC} -c example.c
	@${CC} aniascii.o example.o
	@echo "Done."

run:
	@./a.out

clean:
	@rm *.o a.out
