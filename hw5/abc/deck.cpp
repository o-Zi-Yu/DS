// ==================================================================================
// Implement all functions that you listed by prototype in deck.h
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// NOTE: These are standalone functions, not part of a class.
// ==================================================================================

#include <iostream>
#include <cassert>
#include "playing_card.h"
#include "node.h"
#include "deck.h"

// ==================================================================================
//count the size of the deck
int DeckSize(Node* deck){
	int count = 0;
	if (!deck){
		count = 0;
	}else{
		Node* tmp = deck;
		while (tmp){
			tmp = tmp->after;
			count++;
		}
	}
	return count;
}

//copy the deck; both "after-before" pointers
//and "sorted_prev-sorted_next" pointers
Node* CopyDeck(Node* deck){
	Node* deck2;
	//helper function copying "after"
	CopyDeckHelp(deck, deck2);
	//copy "before"
	Node* tmp = deck2;
	tmp->before = NULL;
	Node* tmp2;
	while (tmp->after){
		tmp2 = tmp;
		tmp = tmp->after;
		tmp->before = tmp2;
	}
	//copy sorting pointers by actually sorting it
	if(deck->sorted_next||deck->sorted_prev){
	Node* sort_tmp = SortHand(deck2);
	sort_tmp = NULL;}
	return deck2;
}

//a helper recursive function inside of CopyDeck()
//only copies "after"
void CopyDeckHelp(Node* deck, Node* &deck2){
	if (!deck){
		deck2 = NULL;
	}else{
		deck2 = new Node(deck->getCard());
		CopyDeckHelp(deck->after, deck2->after);
	}
}

//recursively delete all nodes objects
void DeleteAllCards(Node* &deck){
	if (!deck){
		//do nothing
	}else{
		DeleteAllCards(deck->after);
		delete deck;
		deck = NULL;
	}
}

//cut the deck into top and bottom
void CutDeck(Node* deck, Node* &top, Node* &bottom, const std::string &type){
	if (type == "random"){
		//extra credit space
	}
	if (type == "perfect"){
		int number = DeckSize(deck);
		int count = 0;
		bottom = deck;
		top = deck;
		//make bottom point to middle
		//bottom includes extra one if deck
		//has odd number of cards
		while(count < number/2){
			bottom = bottom->after;
			count++;
		}
		//separate bottom and top
		bottom->before->after = NULL; 
		bottom->before = NULL;
	}
}

//shuffle the deck by crossing top and bottom
Node* Shuffle(Node* &top, Node* &bottom, const std::string &type){
	if (type == "random"){
		//extra credit space
	}
	if (type == "perfect"){
		Node* d;
		d = top;
		Node* b = bottom;
		Node* d2;

		//a flag used to check if bottom has one extra card
		//(odd deck case)
		int flag=0;
		while (bottom ->after){
			d2 = d->after;
			b = bottom->after;
			/*if(d->before){
			d->before = bottom->before;
			d->before->after = d;}*/
			//if bottom has one extra card
			//connect second last bottom with b (bottom->after)
			if(!d->after){
				d->after = bottom;
				bottom->before = d;
				//bottom->after = b;
				//b->before = bottom;
				flag++;
				break;
			}
			//connect bottom with d (top)
			bottom->after = d->after; 
			d->after = bottom;
			bottom->after->before = bottom;
			bottom->before = d;
			d = d2;
			bottom = b;
		}
		//if bottom size = top size
		//connect last bottom with last top
		if(flag == 0){
			if (DeckSize(top)>DeckSize(bottom)){
			b->after = d->after;
			d->after->before = b;
			}
		b->before = d;
		d->after = b;}

	}
	//return top (head pointer)
	return top;
}

//check if two decks contain the same cards
//in the same order
bool SamePrimaryOrder(Node* deck, Node* deck2){
	Node* d1 = deck;
	Node* d2 = deck2;
	bool condition = true;
	if (DeckSize(d1) != DeckSize(d2)){
		condition = false;
	}
	while(d1->after && d2->after){
		if(d1->getCard() != d2->getCard()){
			condition = false;
			break;
		}
		d1 = d1->after;
		d2 = d2->after;
	}
	return condition;
}

//check if two decks contain the same cards but
//in reverse order
bool ReversePrimaryOrder(Node* deck, Node* deck2){
	Node* d1 = deck;
	Node* d2 = deck2;
	bool condition = true;
	if (DeckSize(d1) != DeckSize(d2)){
		condition = false;
	}
	while (d2->after){
		d2 = d2->after;
	}
	while (d1->after && d2->before){
		if(d1->getCard() != d2->getCard()){
			condition = false;
			break;
		}
		d1 = d1->after;
		d2 = d2->before;
	}
	return condition;
}

//deal the cards one at a time to each player
void Deal(Node* &deck, Node** hands, const int &player, const std::string &type, const int &card){
	if (type != "one-at-a-time"){
		//extra credit
	}
	if (type == "one-at-a-time"){

		//make each hand point to the first card
		//the corresponding player would get
		Node* d = deck;
		for(int i=0; i<player; ++i){
			hands[i] = d;
			d = d->after;
		}

		//create pointers to manipulate
		//(hands pointers would not be modified)
		Node* tmp[player];
		Node* tmp_previous[player];
		for(int ii=0; ii<player; ++ii){
			tmp[ii] = hands[ii];
			tmp_previous[ii] = tmp[ii];
		} 

		//dealing cards
		for(int j=0; j<card-1; ++j){ //deal a card each turn
			for(int k=0; k<player; ++k){ //deal to each player

				for(int l=0; l<player&&tmp[k]->after; ++l){
					tmp[k] = tmp[k]->after;
				}
				//connect the previous card with the next card
				tmp_previous[k]->after = tmp[k];
				tmp[k]->before = tmp_previous[k];
				//separate hands
				if(tmp_previous[k]->before && j == 0){
					tmp_previous[k]->before = NULL;
				}
				//moving to the next card
				tmp_previous[k] = tmp[k];
			}
		}

		deck = tmp_previous[player-1]->after;

		//if there are cards left in deck
		if(deck){
		deck->before = NULL;}

		//separate hands
		for(int jj=0; jj<player; ++jj){
			tmp[jj]->after = NULL;
		}
	}
}

//sort hand cards
Node* SortHand(Node* &deck){
	Node* tail = deck;
	while(tail->after){
		tail = tail->after;
	}
	Node* track = deck; //track each card
	Node* tmp = tail; //tmp is for sorted list
	Node* head; //pointing to the sorted head

	//compare each card with tmp one at a time
	while(track != tail){
		while(true){
			//if track is greater, "insert" it before tmp
			if(track->getCard()<tmp->getCard()){
				if(tmp->sorted_prev){
					tmp->sorted_prev->sorted_next = track;
					track->sorted_prev = tmp->sorted_prev;
					track->sorted_next = tmp;
					tmp->sorted_prev = track;
				}else{
					track->sorted_next = tmp;
					tmp->sorted_prev = track;
					head = track;
				}
				break;
			//if tmp is greater, compare track with next 
			//sorted tmp; if no next, track is the smallest,
			//so attach it to the last
			}else{
				if(tmp->sorted_next){
					tmp = tmp->sorted_next;
				}else{
					track->sorted_prev = tmp;
					tmp->sorted_next = track;
					break;
				}
			}
		}
		//make tmp point back to the largiest card and resume comparing
		tmp = head;
		track = track->after;
	}
	return head;
}

//using sorted_next pointers to print the deck
//in sorted order
void PrintDeckSorted(const std::string &description, Node* sorted){
	std::cout << description;
  Node *tmp = sorted;
  while (tmp != NULL) {
    std::cout << " " << tmp->getCard().getString();
    tmp = tmp->sorted_next;
  }
  std::cout << std::endl;
}