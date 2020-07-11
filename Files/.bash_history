cd learn2prog/26_tests_matrix_input/
ls
emacs read_error.txt
./run_all.sh 
fg
./run_all.sh 
fg
./run_all.sh 
fg
./run_all.sh 
fg
./run_all.sh 
cat tests.txt
fg
./run_all.sh 
fg
./run_all.sh 
fg
./run_all.sh 
fg
./run_all.sh 
fg
emacs read_error.txt
./run_all.sh 
touch input0.txt input1.txt input2.txt input3.txt input4.txt
ls
emacs input0.txt
emacs input1.txt
emacs input2.txt
emacs input3.txt
fg
emacs input4.txt
fg
emacs input5.txt
fg
emacs tests.txt
./run_all.sh 
fg
ls
cp read_error.txt eof.txt
rm read_error.txt
emacs tests.txt
emacs eof.txt 
fg
./run_all.sh 
fg
./run_all.sh 
fg
ls
rm input*
ls
rm *~
ls
fg
git add .
git commit -m '26'
git push
grade
cat grade.txt 
fg
cd learn2prog/27_matrix_input/
emacs rotateMatrix.c
make
./rotateMatrix tests.txt 
fg
make
fg
make
./rotateMatrix tests.txt 
fg
make
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
cd learn2prog/27_matrix_input/
ls
emacs rotateMatrix.c
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
man fgets
fg
make
./rotateMatrix tests.txt 
fg
make
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
man fgets
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
man fgets
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
./rotateMatrix tests.txt 
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
./rotateMatrix tests.txt 
fg
cd learn2prog/27_matrix_input/
ls
emacs rotateMatrix.c
fg
make
./rotateMatrix tests.txt 
./rotateMatrix sample.txt
cat sample.txt
cat README 
./rotateMatrix sample.txt
fg
make
fg
make
./rotateMatrix sample.txt
cat sample.out
fg
make
./rotateMatrix sample.txt
./rotateMatrix sample.txt > test1.out
diff -y sample.out test1.out
fg
./rotateMatrix eof.txt
cat eof.txt
./rotateMatrix nine_lines.txt 
./rotateMatrix nine_numbers.txt 
ls
fg
git add .
git commit -m '27'
git push
grade
cat grade.txt
fg
ls
./rotateMatrix nine_numbers.txt 
emacs nine_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
./rotateMatrix nine_numbers.txt 
fg
mak
make
fg
make
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
cat ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
fg
make
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
make
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
fg
./rotateMatrix eleven_numbers.txt 
fg
make
./rotateMatrix ten_numbers.txt 
./rotateMatrix eleven_numbers.txt 
./rotateMatrix nine_numbers.txt 
./rotateMatrix nine_lines.txt 
fg
make
./rotateMatrix nine_lines.txt 
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
./rotateMatrix eleven_numbers.txt 
./rotateMatrix ten_lines.txt 
ls
./rotateMatrix eleven_lines.txt 
fg
make
fg
make
./rotateMatrix eleven_lines.txt 
./rotateMatrix nine_numbers.txt 
./rotateMatrix ten_numbers.txt 
./rotateMatrix nine_numbers.txt 
git add .
git commit -m '27'
git push
grade
cat grade
cat grade.txt
fg
cd learn2prog/28_fix_vg_encr/
ls
emacs broken.c
gcc -0 broken broken.c -pedantic -Wall -Werror -std=gnu99 -ggdb3 -fsanitize=address
gcc -o broken broken.c -pedantic -Wall -Werror -std=gnu99 -ggdb3 -fsanitize=address
ls
./broken
valgrind ./broken
fg
gcc -o broken broken.c -std=gnu99 -Wall -Werror -pedantic -ggdb3
valgrind ./broken
emacs broken.c
emacs Makefile
ls
cp Makefile MakefileBak
fg
emacs Makefile
make
valgrind ./broken
fg
valgrind ./broken
make
valgrind ./broken
fg
make
fg
make
valgrind ./broken
fg
make
valgrind ./broken
fg
make
valgrind ./broken
valgrind --leak-check=full ./broken
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./broken
fg
cd learn2prog/29_outname/
ls ../
ls
cat README 
cd ../30_sort_lines/
ls
cd README 
cat README 
cd learn2prog/31_minesweeper/
ls
cat README 
emacs minesweeper.c 
fg
ls
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
ls
./minesweeper 
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
emacs minesweeper.c
make
fg
make
fg
make
fg
make
fg
make
man calloc
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
cd learn2prog/31_minesweeper/
ls
emacs minesweeper.c
make
./minesweeper 10 10 10
cd learn2prog/31_minesweeper/
./minesweeper 10 10 10
cd learn2prog/31
cd learn2prog/31_minesweeper/
./minesweeper 10 10 10
cd learn2prog/31_minesweeper/
cat README 
emacs minesweeper.c
fg
make
fg
make
./minesweeper 10 10 10
cat README 
fg
make
./minesweeper 10 10 10
fg
./minesweeper 10 10 5
fg
make
fg
make
./minesweeper 10 10 5
fg
cat README 
fg
make
./minesweeper 10 10 5
fg
cat README 
./minesweeper 10 10 5
fg
cat README 
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
cat README 
fg
./minesweeper 10 10 5
fg
./minesweeper 10 10 5
fg
cat README 
fg
make
fg
make
valgrind ./minesweeper 10 10 5
fg
valgrind ./minesweeper 10 10 5
fg
make
valgrind ./minesweeper 10 10 5
fg
ls ../
ls ../25
ls ../25_break_encr/
cat ../25_break_encr/breaker.c
fg
make
valgrind ./minesweeper 10 10 5
fg
make
valgrind ./minesweeper 10 10 5
fg
make
valgrind ./minesweeper 10 10 5
fg
make
valgrind ./minesweeper 10 10 5
fg
cd learn2prog/31_minesweeper/
emacs minesweeper.c
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
fg
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
cat README 
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
cat README 
ls
fg
make
./minesweeper 10 10 10
fg
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
valgrind ./minesweeper 10 10 10
fg
make
fg
make
valgrind ./minesweeper 10 10 10
./minesweeper 10 10 10
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
valgrind ./minesweeper 10 10 10
make
fg
make
valgrind ./minesweeper 10 10 10
fg
make
fg
make
valgrind ./minesweeper 10 10 10
fg
make
fg
make
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
fg
make
fg
make
fg
make
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
valgrind --leak-check=full ./minesweeper 10 10 10
valgrind --leak-check=full --show-leak-kinds=all ./minesweeper 10 10 10
fg
cat README 
fg
make
valgrind --leak-check=full --show-leak-kinds=all ./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
fg
make
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
cat README 
fg
make
fg
make
./minesweeper 10 10 10
fg
cat README 
fg
make
fg
make
./minesweeper 10 10 10
cat README 
fg
make
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
make
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
fg
make
valgrind ./minesweeper 10 10 10
cat README 
fg
make
valgrind ./minesweeper 10 10 10
fg
cat README 
fg
make
fg
make
valgrind ./minesweeper 10 10 10
./minesweeper 10 10 10
fg
make
./minesweeper 10 10 10
fg
cd learn2prog/31_minesweeper/
emacs minesweeper.c
make
./minesweeper 10 10 10
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
cat ../25_break_encr/breaker.c
man ctype
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
cat README 
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
cat README 
fg
make
./minesweeper 10 10 50
./minesweeper 10 10 80
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
make
fg
make
fg
make
./minesweeper 10 10 5
5
fg
make
./minesweeper 10 10 5
./minesweeper 10 10 10
fg
cat README 
fg
make
./minesweeper 10 10 5
fg
make
1
./minesweeper 10 10 5
fg
valgrind ./minesweeper 10 10 5
fg
./minesweeper 10 10 5
fg
make
./minesweeper 10 10 5
cat README 
valgrind ./minesweeper 10 10 5
git add .
git commit -m '31'
git push
grade
cat grade.txt 
fg
cd learn2prog/31_minesweeper/
emacs minesweeper.c
make
git add .
git commit -m '31'
git push
grade
cat grade.txt
fg
make
git add .
git commit -m '31'
git push
grade
ls
rm vg*
ls
fg
make
git add .
git commit -m '31'
git push
grade
cat grade.txt 
fg
cd learn2prog/32_kvs/
emacs kv.c
cd learn2prog/32_kvs/
ls
rm vg*
ls
emacs kv.c
fg
emacs kv.c
cat Makefile 
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
emacs kv.c
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
ls
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
./myTests test.txt
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
man calloc
fg
man malloc
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
cat kv.h
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
emacs kv.h
fg
emacs myTests.c
cat kv.h
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
cat README 
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
emacs kv.c
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
cat kv.h
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -pedantic -Werror -std=gnu99 -ggdb3
fg
cd learn2prog/32_kvs/
emacs kv.c
gcc -o kv kv.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
man strncpy
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
fg$
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
cd learn2prog/32_kvs/
ls
rm vg*
ls
cat README 
cat kv.h
emacs kv.h
emacs #kv.c#
emacs kv.c
man strncpy
emacs kv.c
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
cat myTests.c
emacs myTests.c
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
./myTests test.txt
fg
emacs myTests.c
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
emacs myTests.c
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
emacs myTests.c
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
cat kv.h
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
emacs myTests.c
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
cd learn2prog/32_kvs/
emacs kv.c
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
./myTests test.txt
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
emacs myTests.c
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
fg
emacs myTests.c
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind ./myTests test.txt
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
gcc -o myTests myTests.c -Wall -Werror -pedantic -std=gnu99 -ggdb3
valgrind --leak-check=full ./myTests test.txt
fg
cat README 
cd learn2prog/33_counts/
ls
emacs counts.h
emacs counts.c
cat counts_test.c 
fg
cat ../32_kvs/kv.c
fg
man strcpy
fg
ls
emacs counts_test.c 
fg
make
fg
make
fg
make
fg
emacs counts_test.c 
make
fg
man strlen
fg
make
fg
emacs counts_test.c 
fg
make
fg
make
fg
make
cat counts.h
emacs counts.h
fg
make
fg
emacs counts.h
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
ls
./counts_test 
fg
make
fg
make
fg
make
./counts_test 
fg
make
man typeof
fg
emacs counts.h
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
./counts_test 
fg
make
fg
make
fg
make
./counts_test 
fg
emacs counts_test.c
make
./counts_test 
fg
emacs counts_test.c
make
./counts_test 
fg
make
./counts_test 
fg
valgrind ./counts_test 
fg
make
valgrind ./counts_test 
fg
emacs counts_test.c
fg
make
valgrind ./counts_test 
fg
ls
emacs counts_test
emacs counts_test.c
fg
make
valgrind ./counts_test 
fg
emacs counts_test.c
fg
ls
git add .
git commit -m '33'
git push
grade
cd learn2prog/34_put_together/
ls
cat README 
cat list1a.txt
cat list1b.txt
cat list2b.txt
fg
cat main.c
cat list2b.txt.ans
ls
cat list1a.txt.ans
cd learn2prog/34_put_together/
ls
emacs counts.c
emacs main.c
cat counts.c
fg
cd learn2prog/34_put_together/
emacs main.c
cat count.c
cat counts.c
fg
man strcat
fg
man strcat
fg
manstrcpy
man strcpy
fg
cat counts.h
fg
cat counts.c
fg
make
fg
make
./count_values kvs1.txt list1a.txt
valgrind ./count_values kvs1.txt list1a.txt
ls
cat list1a.txt.ans 
fg
cat README 
fg
valgrind ./count_values kvs1.txt list1a.txt
ls
fg
man strlen
fg
make
fg
make
fg
make
fg
make
valgrind ./count_values kvs1.txt list1a.txt
fg
make
./count_values kvs1.txt list1a.txt
fg
make
./count_values kvs1.txt list1a.txt
fg
ls
cat list1a.txt.counts 
cat list1a.txt.ans
fg
cat counts.c
fg
./count_values kvs1.txt list1a.txt
make
./count_values kvs1.txt list1a.txt
fg
cat counts.c
fg
cd learn2prog/
ls
cd c4prj1_deck/
ls
cat README 
cd learn2prog/c4prj1_deck/
ls
emacs deck.c
fg
emacs test_deckc4.c
make
cat cards.c
fg
make
fg
./test_deckc4 
fg
make
fg
emacs test_deckc4
fg
emacs test_deckc4.c
make
./test_deckc4 
valgrind ./test_deckc4 
fg
man random
fg
man rand
fg
make
fg
make
fg
make
cat deck.c
fg
make
fg
make
fg
make
fg
make
fg
make
./test_deckc4 
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
fg
make
valgrind ./test_deckc4 
fg
cat deck.c
fg
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
valgrind ./test_deckc4 
fg
make
./test_deckc4 
fg
make
fg
rm test_deckc4
make
./test_deckc4 
emacs test_deckc4
emacs test_deckc4.c
ls
cat deck.c
fg
make
fg
make
fg
cat cards.c
fg
cat deck.c
fg
make
fg
make
fg
make
fg
make
fg
./test_deckc4 
fg
make
./test_deckc4 
fg
make
./test_deckc4 
fg
emacs test_deckc4
emacs test_deckc4.c
make
fg
make
./test_deckc4 
fg
make
./test_deckc4 
rm test_deckc4
./test_deckc4 
make
./test_deckc4 
fg
make
rm test_deckc4
make
./test_deckc4 
fg
rm test_deckc4
make
./test_deckc4 
fg
make
rm test_deckc4
make
./test_deckc4 
fg
cat test_deckc4
cat test_deckc4.c
fg
rm test_deckc4
make
./test_deckc4 
fg
emacs test_deckc4.c
cat deck.c
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
./test_deckc4 
valgrind ./test_deckc4 
fg
cat cards.c
fg
make
rm test_deckc4
make
valgrind ./test_deckc4 
fg
cat cards.c
fg
make
rm test_deckc4
valgrind ./test_deckc4 
make
valgrind ./test_deckc4 
fg
cd learn2prog/c4prj1_deck/
ls
emacs test_deckc4.c
make
./test_deckc4 
fg
emacs deck.c
emacs test_deckc4.c
fg
make
ls
cat deck.h
fg
make
./test_deckc4 
fg
emacs test_deckc4.c
fg
make
ls
rm test_deckc4
make
./test_deckc4 
fg
rm test_deckc4
make
fg
make
./test_deckc4 
fg
make
rm test_deckc4
make
./test_deckc4 
fg
rm test_deckc4
make
./test_deckc4 
fg
rm test_deckc4
make
./test_deckc4 
fg
rm test_deckc4
make
./test_deckc4 
fg
emacs test_deckc4.c
fg
emacs test_deckc4.c
fg
emacs test_deckc4.c
fg
rm test_deckc4.c
make
fg
ls
cp test_deckc4.c~ test_deckc4.c
cp test_deckc4.c~ test_deckc4.c.bak
make
fg
rm test_deckc4
make
./test_deckc4 
fg
emacs test_deckc4.c
valgrind ./test_deckc4 
fg
rm test_deckc4
make
valgrind ./test_deckc4 
fg
emacs test_deckc4.c
fg
rm test_deckc4
make
valgrind ./test_deckc4 
fg
rm test_deckc4
make
fg
make
fg
make
fg
make
valgrind ./test_deckc4 
fg
rm test_deckc4
make
fg
make
fg
emacs test_deckc4.c
fg
make
fg
emac test_deckc4.c
emacs test_deckc4.c
fg
make
fg
make
fg
make
valgrind ./test_deckc4 
fg
rm test_deckc4
make
valgrind ./test_deckc4 
fg
emacs test_deckc4.c
fg
cd learn2prog/c4prj1_deck/
emacs test_deckc4.c
fg
emacs deck.c
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
make
rm test_deckc4
make
fg
rm test_deckc4
make test_deckc4.c
make
fg
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
valgrind --track-origins=yes ./test_deckc4
fg
man calloc
fg
make
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
fg
make
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
fg
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
fg
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
fg
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
emacs test_deckc4.c
make
fg
make
fg
make
valgrind --track-origins=yes ./test_deckc4
fg
make
rm test_deckc4
make
valgrind --track-origins=yes ./test_deckc4
fg
emacs test_deckc4
emacs test_deckc4.c
make
valgrind ./test_deckc4
fg
make
rm test_deckc4
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
rm test_deckc4
make
valgrind ./test_deckc4
fg
emacs test_deckc4.c
make
fg
emacs deck.c
make
rm test_deckc4
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
fg
make
valgrind ./test_deckc4
fg
make
rm test_deckc4
make
valgrind ./test_deckc4
fg
make
rm test_deckc4
make
fg
make
fg
make
fg
make
fg
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
make
rm test_deckc4
make
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
rm test_deckc4
make
valgrind ./test_deckc4
fg
cd learn2prog/c4prj1_deck/
ls
rm vgcore*
ls
emacs eval.c
emacs test_deckc4.c
make
fg
make
fg
./test_deckc4
fg
make
./test_deckc4
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
fg
make
./test_deckc4
fg
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
valgrind ./test_deckc4
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
make
fg
make
./test_deckc4
fg
make
fg
make
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
cat cards.c
fg
cat cards.c
fg
make
fg
make
fg
make
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
make
./test_deckc4
fg
make
fg
make
fg
make
./test_deckc4
fg
emacs eval.c
fg
emacs eval.c
fg
emacs eval.c
fg
ls
emacs cards.c
emacs deck.c
cd learn2prog/c4prj1_deck/
git add .
git commit -m 'c4pr1'
git push
grade
git add ../c3prj1_deck/deck.c
git add ../c3prj2_eval/eval.c
git commit -m 'c4pr1'
git push
grade
