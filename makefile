CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = aniascii.c
ICNS = aniascii.h

aniascii.o: $(SRCS) $(INCS)
	@$(CC) -c $(SRCS) -o aniascii.o $(CCFLAGS)
	@echo "Build process done, run \"make run\" to execute."

.PHONY: build
build:
	@ar crs libaniascii.a aniascii.o
	@sudo mkdir -p /opt/aniascii/
	@sudo mv libaniascii.a /opt/aniascii/
	@echo "Library has been generated use \"-laniascii\"."

.PHONY: clean
clean:
	@rm *.o
	@echo "Object files have been removed."