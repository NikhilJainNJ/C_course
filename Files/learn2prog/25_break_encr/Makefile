breaker : breaker.c 
	gcc -o breaker breaker.c -pedantic -std=gnu99 -Wall -Werror -ggdb3

encrypt : 
	gcc -o encrypt encryption.c -Wall -Werror -pedantic -std=gnu99

NUMBERS = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 35 43 52 -2 -6 -10
encrypted :
	$(foreach var,$(NUMBERS), ./encrypt $(var) ./original-file.txt > ./files/encrypted$(var).txt;)

