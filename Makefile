# Makefile - build script

VER := "0.1.0"

# ----- COMPILER OPTIONS -----

CC := gcc
CC_OPTS := \
	-Wall \
	-Werror \
	-Isrc

# ----- MANIFEST -----

HEADER_ONLY_FILES := \
	src/core.h
OBJS := \
	build/obj/argvp.o \
	build/obj/chbuf.o \
	build/obj/err.o \
	build/obj/statout.o

# ----- REAL TARGETS -----

build/bin/koko: src/main.c ${OBJS} ${HEADER_ONLY_FILES}
	@mkdir -p build/bin
	@${CC} ${CC_OPTS} -o $@ ${OBJS} $<
	@echo "Built $@"

build/obj/%.o: src/%.c src/%.h
	@mkdir -p build/obj
	@${CC} ${CC_OPTS} -c -o $@ $<

# ----- PHONY TARGETS -----

.PHONY: \
	all \
	clean

all: build/bin/koko
	@echo "Built all targets"
	@python3 script/genver.py "koko" ${VER}
	@echo "Build number: " $$(cat .buildno)

clean:
	@rm -rf build
	@echo "Cleaned all build artifacts"

