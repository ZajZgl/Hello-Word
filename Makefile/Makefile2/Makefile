SRCDIR = ./src
OBJDIR = $(shell pwd)/obj
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))
CC = gcc
CFLAGS = -c -g -Wall -I /home/linux/MAKEFILE/Makefile2/include/ 

export CC CFLAGS OBJDIR OBJ 

all:$(SRCDIR) ECHO test
$(SRCDIR):ECHO 
	make -C $@
ECHO:
	@echo $(SRCDIR)
	@echo "开始..."

test:$(OBJ)
	$(CC) $^ -o $@

.PHONY:clean
clean:
	$(RM) *.o
