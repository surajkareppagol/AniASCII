CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = aniascii.c example.c
ICNS = aniascii.h

example: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o example $(CCFLAGS) -lncurses
	@echo "Build process done, run \"make run\" to execute."

.PHONY: clean
clean:
	@rm example
	@echo "Object files have been removed."

.PHONY: run
run:
	@clear && ./example