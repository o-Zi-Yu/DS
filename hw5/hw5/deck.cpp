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
	int sort_counter = 0;
	while (h->after != NULL){
		card->after = new Node(* h->after);
		card->after->before = card;
		card = card->after;
		h = h->after;
		if (h->sorted_next != NULL) {sort_counter += 1;}
	}
	card->after = NULL;
	// if(sort_counter != 0){
	// 	while(h->before != NULL) {
	// 		h = h->before;
	// 		card = card->before;
	// 	}
	// 	Node* h_current;
	// 	Node* s_current;

	// 	while(h != NULL){
	// 		h_current = h;
	// 		s_current = card;
	// 		h = h->sorted_next;
	// 		while(h->before != NULL) {
	// 			h = h->before;
	// 			card = card->after;
	// 		}
	// 		s_current->sorted_next = card;
	// 		card->sorted_prev = s_current;
	// 		card = s_current;
	// 		h = h_current;
	// 		h = h->after;
	// 		card = card->after;
	// 	}
	// }

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

void CutDeck(Node* o, Node* &t, Node* &b, const std::string &mode){
	int a = DeckSize(o);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(-3,3);
	int dice_roll = distribution(generator);
	if (mode == "perfect"){
		t = o;
		t->before = NULL;
		for(int i = 0; i < a/2; i++){
			o = o->after;
		}
		o->before->after = NULL;
		b = o;;
		b->before = NULL;
	}
	if (mode == "random"){
		t = o;
		t->before = NULL;
		for(int i = 0; i < a/2 + dice_roll; i++){
			o = o->after;
		}
		o->before->after = NULL;
		b = o;;
		b->before = NULL;
	}
}

// Node* Shuffle(Node* t, Node* b, const std::string &mode){
// 	Node* i = t;
// 	Node* j = b;
// 	Node* h = t;
// 	//只有1张的时候没写
// 	if(mode == "perfect"){
// 		while (i->after != NULL && j->after != NULL){
// 			i = i->after;
// 			h->after = j;
// 			j->before = h;
// 			j = j->after;
// 			h = h->after;
// 			h->after = i;
// 			i->before = h;
// 			h = h->after;
// 		}
// 		j = j->after;
// 		i = i->after;
// 		if (j != NULL) {
// 			h->after = j;
// 			j->before = h;
// 			while(h->after != NULL) {h = h->after;}
// 		}
// 		if (i != NULL){
// 			h->after = i;
// 			i->before = h;
// 		}
// 		return t;
// 	}

// }






Node* Shuffle(Node* &t, Node* &b, const std::string &mode) {
	Node* top_ptr = t;
	Node* h = t;
	Node* bottom_ptr = b;
	int shuffle_num = 1;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,2);
	int dice_roll = distribution(generator);
	if(mode != "random" && mode != "perfect") {return t;}
	if(mode == "perfect") {
		dice_roll = 0;
	}

	for (int i = 0; i < shuffle_num + dice_roll; i++) {
		if(top_ptr->after != NULL) {
			top_ptr = top_ptr->after;
		}
		else{
			if(bottom_ptr != NULL) {
				top_ptr->after = bottom_ptr;
				bottom_ptr->before = top_ptr;
			}
			return t;
		}
	}
	for (int i = 0; i < shuffle_num + dice_roll; i++) {
		if(bottom_ptr->after != NULL) {
			bottom_ptr = bottom_ptr->after;
			top_ptr->before = h;
			h->after = bottom_ptr->before;
			bottom_ptr->before->after = top_ptr;
			bottom_ptr->before->before = h;
			top_ptr->before = bottom_ptr->before;
		}
		else{
			top_ptr->before = h;
			h->after = bottom_ptr;
			bottom_ptr->after = top_ptr;
			bottom_ptr->before = h;
			top_ptr->before = bottom_ptr;
			return t;
		}
	}
}

// Node* Shuffle(Node* &p1, Node* &p2, const std::string &kind){
//     bool have_extra = false;
//     Node* new_deck = p1;
//     Node* ori_after = p1;
//     Node* extra_card;
//     int need_shuffle_num = 0;
//     int shuffle_num = 1;
//     if(DeckSize(p1) != DeckSize(p2)){
//         have_extra = true;
//         if(DeckSize(p1) > DeckSize(p2)){
//             need_shuffle_num = DeckSize(p2);
//             extra_card = p1;
//             for(int counter = 0; counter < need_shuffle_num; counter++){
//                 extra_card = extra_card->after;
//             }
//         }
//         else{
//             need_shuffle_num = DeckSize(p1);
//             extra_card = p2;
//             for(int counter = 0; counter < need_shuffle_num; counter++){
//                 extra_card = extra_card->after;
//             }
//         }
//     }
//     else{
//         need_shuffle_num = DeckSize(p1);
//     }
//     while(shuffle_num < need_shuffle_num){
//         if(kind == "perfect"){
//             shuffle_num++;
//         }
//         else if(kind == "random"){
//             shuffle_num++;
//         }
//         ori_after = new_deck->after;
//         new_deck->after = p2;
//         new_deck->after->before = new_deck;
//         p2 = p2->after;
//         new_deck = new_deck->after;
//         new_deck->after = ori_after;
//         new_deck->after->before = new_deck;
//         new_deck = ori_after;
//     }
//     new_deck->after = p2;
//     new_deck->after->before = new_deck;
//     new_deck = new_deck->after;  
//     if(have_extra){
//         new_deck->after = extra_card;
//         extra_card->before = new_deck;
//     }
//     else{
//     new_deck->after = NULL;
//     }
//     return p1;

// }
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

void Deal(Node* &deck, Node** hands, int player, 
  const std::string &mode, int card){
	Node* c = deck;
	int count = 1;
	//when card is fewer than player
	for (int i = 0; i < player; i++) {
		c = c->after;
		c->before->after = NULL;
		hands[i] = c->before;
	}
	for (int i = 0; i < player; i++) {
		hands[i]->before = NULL;
	}
	while(multiaftercheck(c, player) && count < card) {
		count += 1;
		for (int i = 0; i < player; i++) {
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
	for (int i = 0; i < player; i++) {
		hands[i]->after = NULL;
	}
	while(hands[0]->before != NULL) {
		for (int i = 0; i < player; i++) {
			hands[i] = hands[i]->before;
		}
	}
	deck = c->after;
	if (deck != NULL) {
		deck = deck->before;
		deck->before = NULL;
	}
}

bool multiaftercheck(Node* a, int player) {
	for (int i = 0; i < player; i++) {
		if (a != NULL) {a = a->after;}
		else {return false;}
	}
	return true;
}

Node* SortHand(Node* deck) {
	Node*current = deck;
	Node*correspond = deck;
	current = current->after;
	while(current != NULL) { 
		if(current->getCard() > correspond->getCard()){ //插在最后
			correspond->sorted_next = current;
			current->sorted_prev = correspond;
			correspond = correspond->sorted_next;
		}
		else{
			while(correspond != NULL) {
				if(current->getCard() > correspond->getCard()) {
					// std::cout << "current: " <<current->getCard().getString() << std::endl;
					// std::cout << "correspond: " << correspond->getCard().getString() <<std::endl;
						//correspond = correspond->sorted_prev;
					correspond->sorted_next->sorted_prev = current;
					current->sorted_next = correspond->sorted_next;
					current->sorted_prev = correspond;
					correspond->sorted_next = current;
					break;
				}
				if(correspond->sorted_prev != NULL) {
					correspond = correspond->sorted_prev;
				}
				else {
					correspond->sorted_prev = current;
					current->sorted_next = correspond;
					break;
				}
			}
		}
		if(current->after != NULL) { //原来的下一格
			current = current->after;
		}
		else {break;}
		while(correspond->sorted_next != NULL) { //sort走到最后
			correspond = correspond->sorted_next;
		}
	}
	//current最后一个没写
	while(correspond->sorted_prev != NULL) { //sort走到最前
		correspond = correspond->sorted_prev;
	}
	return correspond;
}

void PrintDeckSorted(const std::string &description, Node* deck) {
  std::cout << description;
  Node *tmp = deck;
  while (tmp != NULL) {
    std::cout << " " << tmp->getCard().getString();
    tmp = tmp->sorted_next;
  }
  std::cout << std::endl;
}