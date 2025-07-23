BUILD_DIR=./.bin
SRC_DIR=sources

SRC_C=$(shell find ${SRC_DIR} -type f -name '*.c')
SRC_O=${SRC_C:%=${BUILD_DIR}/%.o}
SRC_D=${SRC_C:%=${BUILD_DIR}/%.d}

INC_DIR=$(shell find ${SRC_DIR} -type d)
INC_FLAGS=$(addprefix -I,${INC_DIR})

CC=gcc
CFLAGS=-g -Wall -Wextra -MMD -MP ${INC_FLAGS} -DEXTRA

TARGET=main

.PHONY:all
all: ${TARGET}

${TARGET}:${SRC_O}
	${CC} ${CFLAGS} $^ -o $@

${BUILD_DIR}/%.c.o:%.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

.PHONY:clean
clean:
	rm -f main
	rm -rf ${BUILD_DIR}

-include ${SRC_D}
