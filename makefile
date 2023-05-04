CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = aniascii.c example.c
ICNS = aniascii.h

example: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o example $(CCFLAGS)
	@echo "Build Done, run \"make run\" to execute."

.PHONY: clean
clean:
	rm example
	@echo "Cleaning Done."

.PHONY: run
run:
	@clear && ./example