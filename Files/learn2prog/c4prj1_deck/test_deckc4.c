#include "deck.c"
#include "cards.c"

/*
unsigned count_value(deck_t * hand, size_t target_idx){
  unsigned counter = 0;
  for(size_t i=0; i<hand->n_cards; i++) {
    if (value_letter(*hand->cards[i]) == value_letter(*hand->cards[target_idx])){
      counter++;
    }
  } 
  return counter;
}

unsigned * get_match_counts(deck_t * hand){
  print_hand(hand);
  printf("\n");

  unsigned * counts = calloc(hand->n_cards, sizeof(*counts));
  
  for(size_t i=0; i<hand->n_cards; i++){
    counts[i] = count_value(hand, i);
    printf("%u ", counts[i]);
  }
  printf("\n");
  return counts;
}
*/

deck_t * make_random_deck(size_t size){
  deck_t * d = malloc(sizeof(*d));
  d->cards = malloc(sizeof(d->cards));
  size_t i = 0;

  for (i=0; i<size; i++){
    int n = rand() %52;
    card_t * c = malloc(sizeof(*c));
    //printf("Random card : '%d'\n", n);
    *c = card_from_num(n);
    d->cards = realloc(d->cards, (i+1)*sizeof(d->cards));
    d->cards[i] = c;
    c = NULL;
  }
  d->n_cards = i;
  return d;
}

int main(void){

  deck_t * d = calloc(1, sizeof(*d));
  d->cards = calloc(6, sizeof(d->cards));
  d->n_cards = 6;
  
  card_t * c1 = malloc(sizeof(*c1));
  *c1 = card_from_num(12);
  d->cards[0] = c1;

  card_t * c2 = malloc(sizeof(*c2));
  *c2 = card_from_num(25);
  d->cards[1] = c2;

  card_t * c3 = malloc(sizeof(*c3));
  *c3 = card_from_num(11);
  d->cards[2] = c3;

  card_t * c4 = malloc(sizeof(*c4));
  *c4 = card_from_num(24);
  d->cards[3] = c4;

  card_t * c5 = malloc(sizeof(*c5));
  *c5 = card_from_num(37);
  d->cards[4] = c5;

  card_t * c6 = malloc(sizeof(*c6));
  *c6 = card_from_num(7);
  d->cards[5] = c6;
  
  get_match_counts(d);
 
  
  
  //deck_t * d1 = make_random_deck(7);
  //deck_t * d2 = make_random_deck(2);
 
  /*
  card_t c1 = card_from_num(51);
  card_t c2 = card_from_num(13);
  add_card_to(d1, c1);
  add_card_to(d1, c2);
  */
 
  //add_empty_card(d1);
  
  //make_deck_exclude(d1);

  //deck_t ** hands[2] = {&d1, &d2};

  // print_hand(*hands[0]);
  //printf("\n");
  //print_hand(*hands[1]);
  //printf("\n");
  
  //build_remaining_deck(*hands, 2);

  //free_deck(d1);
  return EXIT_SUCCESS;
}
