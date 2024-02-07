CC := g++

CFLAGS := --std=c++11

HDRS := PegSoliter.h BoardGame2D.h

SRCS := main.cpp PegSoliter.cpp

OBJS := $(SRCS:.c=.o)

EXEC := run

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC)

.PHONY: all clean