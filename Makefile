CC = gcc
NOWARN = -Wno-parentheses -Wno-sign-compare -Wno-unused-result
CFLAGS = -std=c89 -O4 -Wall -Werror -Wextra -pedantic $(NOWARN)
LDFLAGS = -lm -lGL -lGLU -lglut
IDIRS = include
INCLUDE = $(patsubst %, -I%, $(IDIRS))
MODULES = cam chunk kbd map rng terrain ugl util
MODULES_BIN = $(patsubst %, bin/%.o, $(MODULES))
MODULES_BIN_PROF = $(patsubst %, bin/prof/%.o, $(MODULES))
MODULES_BIN_MF = $(patsubst %, bin/mf/%.o, $(MODULES));

all: dirs main

dirs:
	mkdir -p bin bin/prof bin/mf assets/map

prof: src/main.c $(MODULES_BIN_PROF)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -pg -o $@ $^

mf: src/main.c $(MODULES_BIN_MF)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -fmudflap -lmudflap -o $@ $^

main: src/main.c $(MODULES_BIN)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -o $@ $^

bin/prof/%.o: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -pg -c -o $@ $<

bin/mf/%.o: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -fmudflap -lmudflap -c -o $@ $<

bin/%.o: src/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDE) -c -o $@ $<

install:
	@echo "make: install not supported"

clean:
	rm -f \
		main prof mf gmon.out \
		$(MODULES_BIN) $(MODULES_BIN_PROF) $(MODULES_BIN_MF)
