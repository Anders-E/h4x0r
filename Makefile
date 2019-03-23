CC	?= gcc
SDIR	= src
ODIR	= obj
OUT	= h4x0r
CFLAGS	:= $(CFLAGS) $(shell pkg-config --cflags ncurses) \
	-Os -Wall -Wextra -pedantic -std=c11
LFLAGS	:= $(LFLAGS) $(shell pkg-config --libs ncurses)

_OBJS = h4x0r.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(ODIR) $(OUT)

.PHONY: all clean

.SUFFIXES:

