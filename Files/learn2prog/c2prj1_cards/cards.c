#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  // check if card value is between 2 and VALUE_ACE inclusive
  assert(c.value >= 2);
  assert(c.value <= VALUE_ACE);
  
  // check if card suit is between SPADES and CLUBS inclusive 
  //assert(c.suit >= SPADES);
  assert(c.suit <= CLUBS);
}


const char * ranking_to_string(hand_ranking_t r) {
  // convert hand_ranking_t enumerated value passed in to a string that describes it
  assert(r <= NOTHING);
  switch(r){
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
    case FULL_HOUSE: return "FULL_HOUSE";
    case FLUSH: return "FLUSH";
    case STRAIGHT: return "STRAIGHT";
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
    case TWO_PAIR: return "TWO_PAIR";
    case PAIR: return "PAIR";
    case NOTHING: return "NOTHING";
    }
  return "";
}


char value_letter(card_t c) {
  // return the character that textually represents the value off the passed-in card
  assert(c.value >= 2);
  assert(c.value <= 14);
  if(c.value >= 2 && c.value <= 9){
    return c.value + 48;
  }
  switch(c.value){
  case 10 : return '0';
  case 11 : return 'J';
  case 12 : return 'Q';
  case 13 : return 'K';
  case 14 : return 'A';
  default : return '?';
  }
}


char suit_letter(card_t c) {
  // return the letter that textually represents the suit of the card passed in
  assert(c.suit <= CLUBS);
  switch(c.suit){
  case SPADES   : return 's';
  case HEARTS   : return 'h';
  case DIAMONDS : return 'd';
  case CLUBS    : return 'c';
  default       : return '?';
  }
}


void print_card(card_t c) {
  // print the textual representation of the card ex: As, Kh, 3c
  printf("%c%c", value_letter(c), suit_letter(c));
}


card_t card_from_letters(char value_let, char suit_let) {
  // make and return a card_t whose value and suit correspond to the letters passed in
  // verify if the values are valid  

  card_t temp;

  // Card value
  switch(value_let){
  case '0'  : temp.value = 10; break;
  case 'J'  : temp.value = 11; break;
  case 'Q' : temp.value = 12; break;
  case 'K' : temp.value = 13; break;
  case 'A' : temp.value = 14; break;
  default  : temp.value = -1;
  }
  
  if(value_let >= '2' && value_let <= '9'){
    temp.value = value_let-48;
  }

  // Card suit
  switch(suit_let){
  case 's' : temp.suit = SPADES; break;
  case 'h' : temp.suit = HEARTS; break;
  case 'd' : temp.suit = DIAMONDS; break;
  case 'c' : temp.suit = CLUBS; break;
  default  : temp.suit = -1;
  }
  
  assert_card_valid(temp);
  return temp;
}


card_t card_from_num(unsigned c) { 
  assert(c>=0);
  assert(c<52);

  card_t temp;
  temp.value  = c%13 +2;
  temp.suit = c/13;

  assert_card_valid(temp);
  return temp;
}

