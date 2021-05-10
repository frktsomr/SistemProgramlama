CFLAGS = -O3 -Iinclude
LIBS = lib/libfdr.a

all: lib/libfdr.a \
	 yap

OBJS = obj/dllist.o obj/fields.o obj/jval.o obj/jrb.o

lib/libfdr.a: $(OBJS)
	ar ru lib/libfdr.a $(OBJS)
	ranlib lib/libfdr.a

yap: main
	 

clean:
	find . -maxdepth 1 ! -name "makefile" ! -name ".kilit" ! -name "giris_metin" ! -name "Readme"  ! -name "main.c" -type f -exec rm -f {} \; 
	rm -f obj/* lib/* bin/*

obj/fields.o: src/fields.c include/fields.h
	gcc $(CFLAGS) -c -o obj/fields.o src/fields.c

obj/jval.o: src/jval.c include/jval.h
	gcc $(CFLAGS) -c -o obj/jval.o src/jval.c

obj/dllist.o: src/dllist.c include/dllist.h include/jval.h
	gcc $(CFLAGS) -c -o obj/dllist.o src/dllist.c

obj/jrb.o: src/jrb.c include/jrb.h include/jval.h
	gcc $(CFLAGS) -c -o obj/jrb.o src/jrb.c

main: main.c $(LIBS)
	gcc $(CFLAGS) -g  -Wall -o main main.c lib/libfdr.a

