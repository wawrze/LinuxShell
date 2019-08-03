FILES = shell.o commands.o history.o reader.o executor.o signals.o time.o

all: shell

shell: $(FILES)
	gcc $(FILES) -o shell

$(FILES): shell.c

.PHONY: clean

clean:
	rm -f *.o
	rm -f shell