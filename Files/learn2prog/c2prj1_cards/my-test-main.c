#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

void test_card_from_num(){
  printf("Testing card_from_num()\n");
  card_from_num(0);
  card_from_num(1);
  card_from_num(12);
  card_from_num(13);
  card_from_num(14);
  card_from_num(26);
  card_from_num(39);
  card_from_num(51);
  // card_from_num(52);
}

void test_card_from_letters(){
  printf("Testing card_from_letters()\n");
  card_from_letters('A', 's');
  card_from_letters('9', 'h');
  card_from_letters('0', 'd');
  card_from_letters('2', 'c');
  //card_from_letters('1', 'h');
  //card_from_letters('Z', 'h');
  //card_from_letters('<', 'h');
  //card_from_letters('A', 'b');
}

void test_print_card(){
  printf("Testing print_card()\n");

  card_t test;
  test.value = 2;
  test.suit = 0;
  
  print_card(test);

  test.value = 7;
  test.suit = 0;
  print_card(test);

  test.value = 9;
  test.suit = 0;
  print_card(test);

  test.value = 11;
  test.suit = 0;
  print_card(test);

  test.value = 14;
  test.suit = 0;
  print_card(test);

  test.value = 14;
  test.suit = 1;
  print_card(test);

  test.value = 14;
  test.suit = 2;
  print_card(test);

  test.value = 14;
  test.suit = 3;
  print_card(test);
  printf("\n");
}

void test_suit_letter(){
  printf("Testing suit_letter()\n");

  card_t test;
  test.value = 2;
  test.suit = 0;

  printf("Value letter : %c\n", suit_letter(test));

  test.suit = 1;
  printf("Value letter : %c\n", suit_letter(test));

  test.suit = 2;
  printf("Value letter : %c\n", suit_letter(test));

  test.suit = 3;
  printf("Value letter : %c\n", suit_letter(test));

  //test.suit = -1;
  //printf("Value letter : %c\n", suit_letter(test));
}

void test_value_letter(){
  printf("Testing value_letter()\n");

  card_t test;
  test.value = 2;
  test.suit = 0;

  printf("Value letter : %c\n", value_letter(test));

  test.value = 5;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 9;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 10;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 11;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 12;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 13;
  printf("Value letter : %c\n", value_letter(test));

  test.value = 14;
  printf("Value letter : %c\n", value_letter(test));

  // test.value = 25;
  //printf("Value letter : %c\n", value_letter(test));
}

void test_ranking_to_string(){
  printf("Testing ranking_to_string()\n");
  
  const char * rts;
  hand_ranking_t rank = FLUSH;
  rts = ranking_to_string(rank);
  printf("Ranking_to_string : %s\n", rts);

  rank = FULL_HOUSE;
  rts = ranking_to_string(rank);
  printf("Ranking_to_string : %s\n", rts);

  rts = ranking_to_string(0);
  printf("Ranking_to_string : %s\n", rts);

  rts = ranking_to_string(5);
  printf("Ranking_to_string : %s\n", rts);

  rts = ranking_to_string(8);
  printf("Ranking_to_string : %s\n", rts);

  //rts = ranking_to_string(-1);
  //printf("Ranking_to_string : %s\n", rts);
}

void test_assert_card_valid(){
  printf("Testing assert_card_valid()\n");

  card_t test;
  test.value = 2;
  test.suit = 0;

  assert_card_valid(test);

  test.suit = 1;
  assert_card_valid(test);
 
  test.suit = 2;
  assert_card_valid(test);

  test.suit = 3;
  assert_card_valid(test);

  test.value = 2;
  assert_card_valid(test);

  test.value = 14;
  assert_card_valid(test);
}

int main(void) {
  printf("Testing cards.c ...\n");
  test_assert_card_valid();
  test_ranking_to_string();
  test_value_letter();
  test_suit_letter();
  test_print_card();
  test_card_from_letters();
  test_card_from_num();
  return EXIT_SUCCESS;
}
