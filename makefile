CC = gcc
SRCS = aniascii.c example.c
ICNS = aniascii.h

out: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o out -lncurses
	@echo "Build done, run \"make run\" to execute."

.PHONY: run
run:
	@clear
	@./out

.PHONY: clean
clean:
	@rm out

