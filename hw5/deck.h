#include "playing_card.h"
#include "node.h"

// ==================================================================================
// prototypes for provided functions (implemented in main.cpp)
// ==================================================================================

//main functions
bool SanityCheckPrimary(Node* top);
bool SanityCheckSorted(Node* first);
Node* CreateDeck(int numCards);
void DeckPushBackCard(Node* &deck, const std::string& suit, int num);
int DeckSize(Node* &head);
Node* CopyDeck(Node* &head);
void DeleteAllCards(Node* &head);
void CutDeck(Node *o, Node * &t, Node* &b, const std::string &mode);
Node* Shuffle(Node* &t, Node* &b, const std::string &mode);
bool SamePrimaryOrder(Node* &fst, Node* &snd);
bool ReversePrimaryOrder(Node* &fst, Node* &snd);
void Deal(Node* &deck, Node** hands, int player, 
  const std::string &mode, int card);
Node* SortHand(Node* deck);
//print deck
void PrintDeckSorted(const std::string &description, Node* deck);
void PrintDeckPrimary(const std::string &description, Node* deck);
//helper functions
bool multiaftercheck(Node* a, int player);



// ==================================================================================
//
// Write all the prototypes for the your functions here
// (they will be implemented in deck.cpp)
//
// NOTE: These are standalone functions, not part of a class.
//
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// ==================================================================================


