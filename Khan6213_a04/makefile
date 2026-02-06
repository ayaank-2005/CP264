# -----------------------------
# Makefile (C project)
# -----------------------------
CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJS = myrecord.o mysort.o

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
