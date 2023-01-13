/*
Write your Rope implementation in this file. 
You do not have to keep any of the code that is already in this file.
Functions that are required that you have not implemented have an assert 0
meaning they will always crash. This should help you make sure you implement
everything.
*/

#include <cassert>
#include "Rope.h"

//Should advance to the next Node using in-order traversal
//It can point at any Node, not just leaves
rope_iterator& rope_iterator::operator++(){
	if (ptr_->right != NULL) { // find the leftmost child of the right node
		ptr_ = ptr_->right;
		while (ptr_->left != NULL) { 
			ptr_ = ptr_->left;
		}
	} 
	else { // go upwards along right branches... stop after the first left
		while (ptr_->parent != NULL && ptr_->parent->right == ptr_) {
			ptr_ = ptr_->parent; 
		}
		ptr_ = ptr_->parent;
	}
	return *this;
}

//Point to the first Node for in-order traversal
rope_iterator Rope::begin() const{
	rope_iterator a(root);
	while(a.ptr_->left != NULL) {
		a.ptr_ = a.ptr_->left;
	}
	return a.ptr_;
}

//initializer
Rope::Rope(){
	root = NULL;
	size_ = 0;
}

//Should make the root = p and adjust any member variables
//This should not make a copy of the rope with root at p,
//it should just "steal" the Node*
Rope::Rope(Node* p){
	root = p;
	Node* a = p;
	size_ = p->weight;
	while(a->right != NULL){ //add weight in the right nodes
		a = a->right;
		size_ += a->weight;
	}
}

//destructor
Rope::~Rope(){
	this->destroy_tree(root);
	size_ = 0;
	root = NULL; 
}

void Rope::destroy_tree(Node* p) {
	if (!p) return;
	destroy_tree(p->left);
	destroy_tree(p->right);
	delete p;
}

//copy constructor
Rope::Rope(const Rope& r){
	root = copyHelper(r.root);
	size_ = r.size_;
}

Node* Rope::copyHelper(Node *r){
	if (r == NULL)
		return NULL;
	Node *copyNode = new Node;
	copyNode->weight = r->weight;
	copyNode->value = r->value;
	copyNode->left = copyHelper(r->left);
	if (copyNode->left) copyNode->left->parent = copyNode;
	copyNode->right = copyHelper(r->right);
	if (copyNode->right) copyNode->right->parent = copyNode;
	return copyNode;
}

Rope& Rope::operator= (const Rope& r){
	if (&r != this) {
		this->destroy_tree(root);
		root = this->copyHelper(r.root);
		size_ = r.size_;
	}
	return *this;
}


//MUST BE ITERATIVE
//Get a single character at index i
bool Rope::index(int i, char& c) const{
	Node* a = root;
	if(i < 0 || i >= size_) return false;
	while (!is_leaf(a)){
		if (i < a->weight) {
			a = a->left;
		}
		else {
			i = i - a->weight;
			a = a->right;
		}
	}
	c = a->value[i];
	return true;
}




//Add the other rope (r)'s string to the end of my string
void Rope::concat(const Rope& r){
	Node* rightnode = copyHelper(r.root);
	Node* headnode = new Node;
	headnode->left = root;
	root->parent = headnode;
	headnode->right = rightnode;
	rightnode->parent = headnode;
	headnode->weight = size_;
	root = headnode;
	size_ = headnode->weight;

	while(headnode->right != NULL){
		headnode = headnode->right;
		size_ += headnode->weight;
	}
}

//Get a substring from index i to index j.
//Includes both the characters at index i and at index j.
//String can be one character if i and j match
//Returns true if a string was returned, and false otherwise
//Function should be written with efficient running time.
bool Rope::report(int i, int j, std::string& s) const{
	if (i > j || i < 0 || j < 0 || i > size_-1 || j > size_-1) return false;
	s.clear();
	char a;
	for (int k = i; k < j+1; k++) {
		index(k, a);
		s.push_back(a);
	}
	if(s.size() == 0) return false;
	else return true;
}

//The first i characters should stay in the current rope, while a new
//Rope (rhs) should contain the remaining size_-i characters.
//A valid split should always result in two ropes of non-zero length.
//If the split would not be valid, this rope should not be changed,
//and the rhs rope should be an empty rope.
//The return value should be this rope (the "left") part of the string
//This function should move the nodes to the rhs instead of making new copies.
Rope& Rope::split(int i, Rope& rhs){
	if(i >= size_ || i < 0) return *this;
	std::vector<Node*> vector_node;
	Node* a = root;
	while (!is_leaf(a)){ //point a to the right side that need to cut
		if (i < a->weight) {
			a = a->left;
		}
		else {
			i = i - a->weight;
			a = a->right;
		}
	}
	if (i != 0) { //split the node if needed
		Node* leftnode = new Node;
		std::string value, leftstr, rightstr;
		value = a->value;
		leftstr = value.substr(0,i);
		leftnode->weight = leftstr.size();
		leftnode->value = leftstr;
		leftnode->parent = a;
		a->left = leftnode;
		a->value = "";
		a->weight = i;
		Node* rightnode = new Node;
		rightstr = value.substr(i);
		rightnode->weight = rightstr.size();
		rightnode->value = rightstr;
		rightnode->parent = a;
		a->right = rightnode;
		a = a->right;
	}
	Node* z = a->parent->left;

	Node* c = a;
	while (c->parent){ //cut the node is right of a;
		if ((c->parent->left == c) && c->parent->right){
		c = c->parent->right;
		vector_node.push_back(c);
		}
		c = c->parent;
 	}
	Node* b = a;
	while(1) { //cut a;
		if (b->parent->right) {
			b->parent->right = NULL;
			b->parent = NULL;
			break;
		}
		b = b->parent;
	}

	Node* d = b;
	if (vector_node.size() >= 1) {
		//break the nodes
		for (uint i = 0; i < vector_node.size(); i++) {
			vector_node[i]->parent->right = NULL;
			vector_node[i]->parent = NULL;
		}
		//combine into a new node
		for (uint i = 0; i < vector_node.size(); i++) {
			d = concat_no_copy(d, vector_node[i]);
		}
	}

	rhs.root = d; //rhs adjust
	Node* e = d;
	rhs.size_ = e->weight;
	while(e->right != NULL){
		e = e->right;
		rhs.size_ += e->weight;
	}

	//lhs adjust
	while(1) {
		if (!z->parent) break;
		z = z->parent;
		z->weight = z->left->weight;
		Node* f = z;
		f = f->left;
		while(f->right != NULL){
			f = f->right;
			z->weight += f->weight;
		}
	}
	size_ = z->weight;
	while(z->right != NULL){
		z = z->right;
		size_ += z->weight;
	}
	return *this;
}

//link 2 nodes together with a new parent node without copy
Node* concat_no_copy(Node* x1, Node* x2) {
	Node* a = new Node;
	a->weight = x1->weight;
	Node* b = x1;
	while(b->right != NULL){
		b = b->right;
		a->weight += b->weight;
	}

	a->left = x1;
	x1->parent = a;
	a->right = x2;
	x2->parent = a;
	return a;
}
