CLASSDIR = Libfdr
INCLUDE = -I$(CLASSDIR)/include
CFLAGS = $(INCLUDE)
LIBS = $(CLASSDIR)/lib/libfdr.a


calistir:main
		
clean:
	rm -f kripto

cleanall: clean
	find . -maxdepth 1 ! -name "makefile" ! -name "README"  ! -name "main.c" -type f -exec rm -f {} \;

run: clean \
	calistir \
	execute

main:	main.c $(LIBS)
	gcc $(CFLAGS) -g -Wall -o kripto main.c $(LIBS)

execute:
			./kripto -e giris_metin encrypted
			./kripto -d encrypted decrypted

