test : maxSeq.o test-subseq.o
	gcc -o test maxSeq.o test-subseq.o

maxSeq.o : maxSeq.c
	gcc -o maxSeq.o -c maxSeq.c -std=gnu99 -pedantic -Wall -Werror

test-subseq.o : test-subseq.c
	gcc -o test-subseq.o -c test-subseq.c -std=gnu99 -Wall -Werror
