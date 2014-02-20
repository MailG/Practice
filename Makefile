
C_SRC_FILE=$(wildcard *.c)
OUT_FILE=$(C_SRC_FILE:.c=.o)

ALL:$(OUT_FILE)

%.o : %.c
	gcc -o $(@F) $< 

clean:
	rm *.o

