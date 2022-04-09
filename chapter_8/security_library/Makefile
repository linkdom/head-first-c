encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c
checksum.o: checksum.c checksum.h
	gcc -c checksum.c
test_code: encrypt.o checksum.o
	gcc test_code.c encrypt.o checksum.o -o test_code
