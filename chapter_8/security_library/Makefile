encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c
checksum.o: checksum.c checksum.h
	gcc -c checksum.c
libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a checksum.o encrypt.o
test_code: test_code.c libhfsecurity.a
	gcc test_code.c -I . -L . -lhfsecurity -o test_code
