#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


void free_deck(deck_t * deck){
  for(size_t i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t * d = calloc(1, sizeof(*d));
  d->cards = calloc(1, sizeof(d->cards));
  size_t counter = 0;
  for(size_t hand=0; hand<n_hands; hand++){
    for(size_t card=0; card<hands[hand]->n_cards; card++){
      //print_card(*hands[hand]->cards[card]);
      card_t * c = malloc(sizeof(*c));
      *c = *hands[hand]->cards[card];
      add_card_to(d, *c);
      counter++;
    }
  }

  d->n_cards = counter;

  deck_t * remaining_deck = make_deck_exclude(d);
  //printf("\n");
  //print_hand(remaining_deck);
  //printf("\n");
  
  return remaining_deck;
}


deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t * d = calloc(1, sizeof(*d));
  d->cards = calloc(1, sizeof(d->cards));
  
  size_t counter = 0;
  
  for(size_t i=0; i<52; i++){  
    card_t c = card_from_num(i);
    if (!deck_contains(excluded_cards, c)){
      add_card_to(d, c);
      counter++;
    }
  }

  d->n_cards = counter;
  //print_hand(d);
  //printf("\n");
  //print_hand(excluded_cards);
  //printf("\n");
  return d;
}

card_t * add_empty_card(deck_t * d){
  card_t * c = malloc(sizeof(c));
 
  c->value = 0;
  c->suit = 0;
  d->cards = realloc(d->cards, (d->n_cards+1)*sizeof(d->cards));
  d->cards[d->n_cards] = c;
  d->n_cards = d->n_cards+1;
 
  return c;
}

void add_card_to(deck_t * d, card_t c){
  d->cards = realloc(d->cards, (d->n_cards+1) * sizeof(d->cards));
  card_t * card = malloc(sizeof(*card));
  *card = c;
  d->cards[d->n_cards] = card;
  d->n_cards = d->n_cards+1;
}

void print_hand(deck_t * hand){
  for (size_t i=0; i<(*hand).n_cards; i++){
    print_card(*(*hand).cards[i]);
    printf(" ");
  }
}


int deck_contains(deck_t * d, card_t c) {
  for (size_t i=0; i<(*d).n_cards; i++){
    if ( (value_letter(*(*d).cards[i]) == value_letter(c)) &&
	 (suit_letter(*(*d).cards[i]) == suit_letter(c)) ) {
      return 1;
    }   
  }
  return 0;
}


void swap_cards(card_t * c0, card_t * c1){
  card_t temp;

  temp = *c0;
  *c0 = *c1;
  *c1 = temp;
}

void shuffle(deck_t * d){
  size_t n = (*d).n_cards;
  int random = 0;
  card_t * p0 = NULL;
  card_t * p1 = NULL; 

  for (size_t i=0; i<n; i++){
    random = rand() %n;
    p0 = (*d).cards[random];

    random = rand() %n;
    p1 = (*d).cards[random];

    swap_cards(p0, p1);
  }
}

void assert_full_deck(deck_t * d) {
  assert((*d).n_cards == 52);
  card_t c;
  for (unsigned i = 0; i<52; i++){
    c = card_from_num(i);
    assert(deck_contains(d,c) == 1);
  }
}

