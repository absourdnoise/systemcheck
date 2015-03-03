CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o system_check main.c
stable:clean
	$(CC) $(CFLAGS) -o system_check main.c
clean:
	rm -vfr *~ system_check
