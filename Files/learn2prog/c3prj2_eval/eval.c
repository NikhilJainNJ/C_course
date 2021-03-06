#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int card_ptr_comp(const void * vp1, const void * vp2) {
  const card_t * const * cp1 = vp1;
  const card_t * const * cp2 = vp2;
 
  if ((**cp1).value == (**cp2).value) {
    return (**cp2).suit - (**cp1).suit;
  }
  return (**cp2).value - (**cp1).value;
}


suit_t flush_suit(deck_t * hand) {
  int spades=0, hearts=0, diamonds=0, clubs=0;
  
  for ( size_t i=0; i<(*hand).n_cards; i++){
    switch(suit_letter(*(*hand).cards[i])){
    case 's'   : spades++  ; break;
    case 'h'   : hearts++  ; break;
    case 'd'   : diamonds++; break;
    case 'c'   : clubs++   ; break;
    default    : NULL; 
    }
  }

  if (spades >= 5) { return SPADES; }
  if (hearts >= 5) { return HEARTS; }
  if (diamonds >= 5) { return DIAMONDS; }
  if (clubs >= 5) { return CLUBS; }
  
  return NUM_SUITS;
}


unsigned get_largest_element(unsigned * arr, size_t n) {  
  unsigned * largest = arr;
  for (size_t i=0; i<n; i++){
    if (arr[i] > *largest){
      largest = &arr[i];
    }
  }
  return *largest;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  for (size_t i=0; i<n; i++){
    if(match_counts[i] == n_of_akind){
      return i;
    }
  } 
  return 0;
}

ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {
  
  size_t n = (*hand).n_cards;
  for (size_t i=0; i<n; i++){
    if(match_counts[i]>1 && value_letter(*(*hand).cards[i]) != value_letter(*(*hand).cards[match_idx])) {
      return i;
    }
  }
  return -1;
}


int is_n_length_straight_at(deck_t * hand, size_t index, suit_t fs, int n){
  suit_t expected_suit = fs;
  card_t last_card = *(*hand).cards[index];
  card_t card = *(*hand).cards[index];
  int count = 1;
  int maxCount = 1;
  size_t idx = index;

  // If looking for flush suit, set last_card to first card of expected suit
  if (expected_suit != NUM_SUITS){
    for (size_t i=index; i<(*hand).n_cards; i++){
      last_card = *(*hand).cards[i];
      if(card.suit == expected_suit){
	idx = i;
        break;
      }
    }
  }

  for (size_t i=idx+1; i<(*hand).n_cards; i++){
    card = *(*hand).cards[i];
    
    // if no expected suit, set expected_suit to current card suit
    if (fs == NUM_SUITS){
      expected_suit = card.suit;
    }
    
    if (last_card.value == card.value+1  && card.suit == expected_suit){
      last_card = card;
      count++;
      if(count > maxCount){
        maxCount = count;
      }
    } 
    else if (last_card.value > card.value+1){
      count = 1;
    }
  }
  
  if(maxCount >= n) {
    //printf("Straight at index %zu, maxCount = %d, n = %d\n", index, maxCount, n);
    return 1;
  }
  //printf("No straight at index %zu, maxCount = %d, n = %d\n", index, maxCount, n);
  return 0;
}

int is_ace_low_straight_at(deck_t * hand, size_t index, suit_t fs){
  suit_t expected_suit = fs;
  card_t card;
  size_t idx_of_5 = -1;  
  int is_ace = -1;
  int ans = 0;

  // find a 5
  for (size_t i=index; i<(*hand).n_cards; i++){
    card = *(*hand).cards[i];
    
    if( fs == NUM_SUITS){
      expected_suit = card.suit;
    }
      
    if (card.value == 5 && card.suit == expected_suit){
      idx_of_5 = i;
      break;
    }
  }
  
  // find an A
  for (size_t i=index; i<(*hand).n_cards; i++){
    card = *(*hand).cards[i];
      
    if( fs == NUM_SUITS){
      expected_suit = card.suit;
    }
    if (card.value == 14 && card.suit == expected_suit) {
      is_ace = 1;
      break;
    }
  }

  
  // if 5 and A, find a 4 length straight from 5
  if (idx_of_5 != -1 && is_ace != -1){
    ans = is_n_length_straight_at(hand, idx_of_5, fs, 4);
    if (ans == 1) {
      return -1;
    }
  }
  return 0; 
}


int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  int ans = 0;
  ans = is_n_length_straight_at(hand, index, fs, 5);
  if (ans == 0){
    ans = is_ace_low_straight_at(hand, index, fs);
  }
  return ans;
}

int next_largest(deck_t * hand, int index, unsigned first_n_value, unsigned second_n_value){
  card_t * card = (*hand).cards[0];
  for (int i=index+1; i<(*hand).n_cards; i++){
    card = (*hand).cards[i];
    if( (*card).value != first_n_value && (*card).value != second_n_value ){
      return i;
    }
  }
  return -1;
}

hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {
  assert(n<5);
  
  hand_eval_t ans;
  ans.ranking = what;
  card_t * card = (*hand).cards[0];
  size_t pos = 0;

  // extract the n first cards
  for (size_t i=idx; i<idx+n; i++){
    card = (*hand).cards[i];
    ans.cards[pos] = card;
    pos++;
  }

  if (n==0 || n==1){
    // fill all places with the 5 first cards
    for (size_t i=0; i<5; i++){
      ans.cards[i] = (*hand).cards[i];
    }
    return ans;
  }
  
  unsigned first_n_value = (*card).value;
  unsigned second_n_value = 1;
  int first = -1;
  int second = -1;
  int third = -1;
  card_t * last_card = (*hand).cards[0];
  size_t sec_idx = -1;
  
  if (n==2 || n==3){
    // find the index of a secondary pair
    for (size_t i=1; i<(*hand).n_cards; i++){
      card = (*hand).cards[i];
      if ( (*card).value != first_n_value && (*card).value == (*last_card).value ) {
        sec_idx = i-1;
        second_n_value = (*card).value;
        break;
      }
      last_card = card;
    }
    
    // if there is a secondary pair, copy secondary pair
    if (sec_idx != -1 ){
      for (size_t i=sec_idx; i<sec_idx+2; i++){
        card = (*hand).cards[i];
        ans.cards[pos] = card;
        pos++;
      }
      // if secondary pair & n==2, find the largest non-n_of_a_kind card, return ans
      if (n==2){
        first = next_largest(hand, -1, first_n_value, second_n_value);
        ans.cards[pos] = (*hand).cards[first];
	return ans;
      }
      // else if secondary pair & n==3, return ans
      return ans;
    }

    // if no secondary pair
    // if n=2, find the 3 remaining cards, return ans
    if (n==2) {
      first = next_largest(hand, -1, first_n_value, second_n_value);
      second = next_largest(hand, first, first_n_value, second_n_value);
      third = next_largest(hand, second, first_n_value, second_n_value);
      ans.cards[2] = (*hand).cards[first];
      ans.cards[3] = (*hand).cards[second];
      ans.cards[4] = (*hand).cards[third];
      return ans;
    }

    // else if n=3, find the 2 remaining cards, return ans
    first = next_largest(hand, -1, first_n_value, second_n_value);
    second = next_largest(hand, first, first_n_value, second_n_value);
    ans.cards[3] = (*hand).cards[first];
    ans.cards[4] = (*hand).cards[second];  
    return ans;
      
  }
  // else if n==4, find the 1 remaining card, return ans
  else {
    first = next_largest(hand, -1, first_n_value, second_n_value);
    ans.cards[pos] = (*hand).cards[first];
    return ans;
  }
} 


int compare_hands(deck_t * hand1, deck_t * hand2) {
  qsort((*hand1).cards, (*hand1).n_cards, sizeof(card_t), card_ptr_comp);
  qsort((*hand2).cards, (*hand2).n_cards, sizeof(card_t), card_ptr_comp);
   
  hand_eval_t eval1 = evaluate_hand(hand1);
  hand_eval_t eval2 = evaluate_hand(hand2);

  /*
  printf("Hand 1 : \n");
  print_hand(hand1);
  printf("Hand 2 : \n");
  print_hand(hand2);
  
  printf("%s | ", ranking_to_string(eval1.ranking));
  printf("%s\n", ranking_to_string(eval2.ranking));
  */
  
  if(eval1.ranking > eval2.ranking){
    return -1;
  }
  else if(eval2.ranking > eval1.ranking){
    return 1;
  }
  else{
    card_t * card1 = eval1.cards[0];
    card_t * card2 = eval2.cards[0];
    for (size_t i=0; i<5; i++){
      card1 = eval1.cards[i];
      card2 = eval2.cards[i];
      if((*card1).value > (*card2).value){
	return 1;
      }
      else if ((*card1).value < (*card2).value){
	return -1;
      }
    }
    return 0;
  }
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.

//unsigned * get_match_counts(deck_t * hand) ;

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
  // print_hand(hand);
  //printf("\n");

  unsigned * counts = calloc(hand->n_cards, sizeof(*counts));

  for(size_t i=0; i<hand->n_cards; i++){
    counts[i] = count_value(hand, i);
    //printf("%u ", counts[i]);
  }
  //printf("\n");
  return counts;
}




// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
