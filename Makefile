CC=gcc
CFLAGS="-Wall"

DEPS = linked_list.h macros.h kartei_karte.h
OBJ = main.o linked_list.o kartei_karte.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) -g
sys_prog_2_5: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
clean:
	rm -vfr *~ sys_prog_2_5
