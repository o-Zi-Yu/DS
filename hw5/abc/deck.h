#include "playing_card.h"
#include "node.h"

// ==================================================================================
// prototypes for provided functions (implemented in main.cpp)
// ==================================================================================

bool SanityCheckPrimary(Node* top);
bool SanityCheckSorted(Node* first);
Node* CreateDeck(int numCards);
void DeckPushBackCard(Node* &deck, const std::string& suit, int num);
void PrintDeckPrimary(const std::string &description, Node* deck);


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
int DeckSize(Node* deck);
int DeckSizeHelp(Node* deck, int &count);
bool SamePrimaryOrder(Node* deck, Node* deck2);
bool ReversePrimaryOrder(Node* deck, Node* deck2);

Node* CopyDeck(Node* deck);
void CopyDeckHelp(Node* deck, Node* &deck2);//helper function for CopyDeck()
void DeleteAllCards(Node* &deck);
void CutDeck(Node* deck, Node* &top, Node* &bottom, const std::string &type);
Node* Shuffle(Node* &top, Node* &bottom, const std::string &type);
void Deal(Node* &deck, Node** hands, const int &player, const std::string &type, const int &card);
Node* SortHand(Node* &deck);
void PrintDeckSorted(const std::string &description, Node* sorted);
// ==================================================================================


