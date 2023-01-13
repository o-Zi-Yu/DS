// ==================================================================================
// Implement all functions that you listed by prototype in deck.h
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// NOTE: These are standalone functions, not part of a class.
// ==================================================================================

#include <iostream>
#include <cassert>
#include <random>
#include <cstdlib>
#include "playing_card.h"
#include "node.h"
#include "deck.h"

// ==================================================================================

int DeckSize(Node* &head){
    Node *h = head;
    int len = 0;
    while(h != NULL){
        len++;
        h = h->after;
    }
    return len;
}

Node* CopyDeck(Node* &head){
	Node* h = head;
	Node* c_deck = new Node(*h);
	c_deck->before = NULL;
	Node* card = c_deck;
	while (h->after != NULL){
		card->after = new Node(* h->after);
		card->after->before = card;
		card = card->after;
		h = h->after;
	}
	card->after = NULL;

	if (c_deck->sorted_next || c_deck->sorted_prev ) { //copy pointers of sort
		SortHand(c_deck);
	}
	return c_deck;
}

void DeleteAllCards(Node* &head) {
    if (head == NULL){}
    else{
        if (head->after == NULL) {
            delete head;
            head = NULL;
            return;
        }
    }
    DeleteAllCards(head->after);
    delete head;
    head = NULL;
}

/*the function takes in 3 Node pointer and a mode. It cuts the input deck o
into t in top and b in bottom.
*/
void CutDeck(Node* o, Node* &t, Node* &b, const std::string &mode){
	int a = DeckSize(o);
	std::default_random_engine generator; //random generator
	std::uniform_int_distribution<int> distribution(-3,3); //from -3 to 3
	int dice_roll = distribution(generator);
	if (mode == "perfect"){
		dice_roll = 0;
	}
	t = o;
	t->before = NULL;
	for(int i = 0; i < a/2 + dice_roll; i++){ //change the cut position
		o = o->after;
	}
	o->before->after = NULL;
	b = o;
	b->before = NULL;
}

//takes in top and bottom deck and shuffle 2 decks in 1 in a, with 2 modes.
Node* Shuffle(Node* &t, Node* &b, const std::string &mode) {
	Node* top_ptr = t;
	Node* h = t;
	Node* bottom_ptr = b;
	int shuffle_num = 1;
	int dice_roll = rand() % 5; //random from 0 to 5
	if(mode != "random" && mode != "perfect") {return t;}
	if(mode == "perfect") {
		dice_roll = 0;
	}
	while(1){
		//step through the top deck
		for (int i = 0; i < shuffle_num + dice_roll; i++) {
			if(top_ptr->after != NULL) {
				top_ptr = top_ptr->after;
			}
			else{ //no top left
				if(bottom_ptr != NULL) {
					top_ptr->after = bottom_ptr;
					bottom_ptr->before = top_ptr;
				}
				return t;
			}
		}
		//step through the bottom deck
		for (int i = 0; i < shuffle_num + dice_roll; i++) {
			if(bottom_ptr->after != NULL) {
				bottom_ptr = bottom_ptr->after;
				h = top_ptr->before;
				h->after = bottom_ptr->before;
				bottom_ptr->before->after = top_ptr;
				bottom_ptr->before->before = h;
				top_ptr->before = bottom_ptr->before;
			}
			else{ //no bottom left
				h = top_ptr->before;
				h->after = bottom_ptr;
				bottom_ptr->after = top_ptr;
				bottom_ptr->before = h;
				top_ptr->before = bottom_ptr;
				return t;
			}
		}
	}
}

//check 2 decks have same cards from frontward
bool SamePrimaryOrder(Node* &fst, Node* &snd){
	Node* i = fst;
	Node* j = snd;
	int a = DeckSize(i);
	int b = DeckSize(j);
	if(a != b){return false;}
	while(i->after != NULL){
		if(i->getCard() != j->getCard()) {return false;}
		i = i->after;
		j = j->after;
	}
	return true;
}

//check 2 decks have same cards from backward
bool ReversePrimaryOrder(Node* &fst, Node* &snd){
	Node* i = fst;
	Node* j = snd;
	int a = DeckSize(i);
	int b = DeckSize(j);
	if(a != b){return false;}
	while(j->after != NULL){
		j = j->after;
	}
	while(i->after != NULL){
		if(i->getCard() != j->getCard()) {return false;}
		i = i->after;
		j = j->before;
	}
	return true;
}

/*inputs deck and an array that has number of players with a mode and how many
cards should a player have. After the function, the deck should contain the
remaining cards as the hands should contain certain cards each player should
have. 
*/
void Deal(Node* &deck, Node** hands, int player, 
  const std::string &mode, int card){
	Node* c = deck;
	int count = 1;
	if (mode == "one-at-a-time") {
		//if card is fewer than player
		if (player > DeckSize(deck)) {
			int i;
			for (i = 0; i < player && c != NULL; i++) {
				hands[i] = c;
				c = c->after;
				hands[i]->after = NULL;
				hands[i]->before = NULL;
			}
			for (int j = i; j < player; j++) {
				hands[j] = NULL;
			}
			deck = c;
			return;
		}
		//initialize the array with cards
		for (int i = 0; i < player; i++) {
			c = c->after;
			c->before->after = NULL;
			hands[i] = c->before;
		}
		for (int i = 0; i < player; i++) {
			hands[i]->before = NULL;
		}
		//check if the cards can be dealt to players 
		//and the card number is within they should have
		while(multiaftercheck(c, player) && count < card) {
			count += 1;
			for (int i = 0; i < player; i++) { //deal cards to each player
				if(c->after!=NULL){
					c = c->after;
					c->before->after = NULL;
					hands[i]->after = c->before;
					c->before->before = hands[i];
					hands[i] = hands[i]->after;
				}
				else{
					hands[i]->after = c;
					c->before = hands[i];
					hands[i] = hands[i]->after;
				}
			}
		}
		//give cards to players if the cards have left and player doesn't have
		//enough cards
		while(c && count < card) {
			for (int i = 0; i < player; i++) {
				if(c){
					hands[i]->after = c;
					c->before = hands[i];
					c = c->after;
					hands[i] = hands[i]->after;
				}
			}
		}
		for (int i = 0; i < player; i++) {
			hands[i]->after = NULL;
		}
		//let the pointer of each player in hands go to the begining
		for (int i = 0; i < player; i++) {
			while(hands[i]->before != NULL) {
				hands[i] = hands[i]->before;
			}
		}
		//set the deck to the remaining card, or NULL is nothing left
		if(!c){deck = NULL;}
		else{deck = c->after;}
		if (deck != NULL) {
			deck = deck->before;
			deck->before = NULL;
		}
  	}
}

//take in a deck and check if the card is enough to deal to each player
bool multiaftercheck(Node* a, int player) {
	for (int i = 0; i < player; i++) {
		if (a != NULL) {a = a->after;}
		else {return false;}
	}
	return true;
}

/*sort the deck in sequence from spade A to heart 2, the function adds 
sorted_next and sorted_prev to link the deck.
*/
Node* SortHand(Node* deck) {
	Node*current = deck;
	Node*correspond = deck;
	current = current->after;
	while(current != NULL) { 
		if(current->getCard() > correspond->getCard()){ //put in the end
			correspond->sorted_next = current;
			current->sorted_prev = correspond;
			correspond = correspond->sorted_next;
		}
		else{
			while(correspond != NULL) {
				if(current->getCard() > correspond->getCard()) {
					correspond->sorted_next->sorted_prev = current;
					current->sorted_next = correspond->sorted_next;
					current->sorted_prev = correspond;
					correspond->sorted_next = current;
					break;
				}
				if(correspond->sorted_prev != NULL) { //put in the head
					correspond = correspond->sorted_prev;
				}
				else {
					correspond->sorted_prev = current;
					current->sorted_next = correspond;
					break;
				}
			}
		}
		if(current->after != NULL) { //next card
			current = current->after;
		}
		else {break;} //has no cards left
		//goes to head for the next sort
		while(correspond->sorted_next != NULL) { 
			correspond = correspond->sorted_next;
		}
	}
	while(correspond->sorted_prev != NULL) { //sort goes to head to return
		correspond = correspond->sorted_prev;
	}
	return correspond;
}

//print the deck in sorted way
void PrintDeckSorted(const std::string &description, Node* deck) {
  std::cout << description;
  Node *tmp = deck;
  while (tmp != NULL) {
    std::cout << " " << tmp->getCard().getString(); 
    tmp = tmp->sorted_next;
  }
  std::cout << std::endl;
}