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
	// Ptr is not the last left leaf
	if(ptr_->right != NULL){
		ptr_ = ptr_->right;
		while(ptr_->left != NULL){
			ptr_ = ptr_->left;
		}
	}
	else{
		while((ptr_->parent != NULL) && (ptr_->parent->right == ptr_)){
			ptr_ = ptr_->parent;
		}
		ptr_ = ptr_->parent;
	}
	return *this;
	//assert(0 && "rope_iterator operator++ not implemented!");
}

//Point to the first Node for in-order traversal
rope_iterator Rope::begin() const{
	Node* begin = root;
	while(begin->left != NULL){
		begin = begin->left;
	}
	return rope_iterator(begin);
	//assert(0 && "rope_iterator begin() not implemented!");
}

Rope::Rope(){
	root = NULL;
	size_ = 0;
	//assert(0 && "Rope default constructor not implemented!");
}

//Should make the root = p and adjust any member variables
//This should not make a copy of the rope with root at p,
//it should just "steal" the Node*
Rope::Rope(Node* p){
	root = p;
	Node* size_count = p;
	size_ = p->weight;
	while(size_count->right != NULL){
		size_count = size_count->right;
		size_ += size_count->weight;
	}
	//assert(0 && "Rope constructor from Node not implemented!");
}
Node*  Rope::copy_tree(Node* old_root, Node* the_parent) {
	if (old_root == NULL){
		return NULL;
	}
	Node* answer = new Node;
	answer->value = old_root->value;
	answer->weight = old_root->weight;
	answer->left = copy_tree(old_root->left,answer);
	answer->right = copy_tree(old_root->right,answer);
	answer->parent = the_parent;
	return answer;
}

void Rope::destroy_tree(Node* root){
	if(!root){
		return;
	}
	destroy_tree(root->right);
	destroy_tree(root->left);
	delete root;
}

Rope::~Rope(){
	destroy_tree(root);
	//assert(0 && "Rope destructor not implemented!");
}

Rope::Rope(const Rope& r){
	root = copy_tree(r.root, NULL);
	size_ = r.size_;
	//assert(0 && "Rope copy constructor not implemented!");
}

Rope& Rope::operator= (const Rope& r){
	destroy_tree(root);
	root = copy_tree(r.root, NULL);
	size_ = r.size_;
	return *this;
	//assert(0 && "Rope assignment not implemented!");
}

//MUST BE ITERATIVE
//Get a single character at index i
bool Rope::index(int i, char& c) const{
	Node* guide = root;
	if(i < 0){
		return false;
	}
	if(i >= size_){
		return false;
	}
	while(!is_leaf(guide)){
		if(guide->weight > i){
			guide = guide->left;
		}
		else{
			i -= guide->weight;
			guide = guide->right;
		}
	}
	c = guide->value[i];
	return true;
	//assert(0 && "Rope index() not implemented!");
}

//Add the other rope (r)'s string to the end of my string
void Rope::concat(const Rope& r){
	Node* r_root;
	r_root = this->copy_tree(r.root,NULL);
	Node* new_root = new Node;
	root->parent = new_root;
	new_root->left = root;
	new_root->weight = size_;
	r_root->parent = new_root;
	new_root->right = r_root;
	root = new_root;
	Node* size_count = new_root;
	size_ = new_root->weight;
	while(size_count->right != NULL){
		size_count = size_count->right;
		size_ += size_count->weight;
	}
	//assert(0 && "Rope concat() not implemented!");
}

//Get a substring from index i to index j.
//Includes both the characters at index i and at index j.
//String can be one character if i and j match
//Returns true if a string was returned, and false otherwise
//Function should be written with efficient running time.
bool Rope::report(int i, int j, std::string& s) const{
	s = "";
	if(i < 0 || j < 0){
		return false;
	}
	if(i >= size_ || j >= size_){
		return false;
	}
	if(i > j){
		return false;
	}
	for(rope_iterator it = begin(); it!= end(); it++){
		if(!is_leaf(it.ptr_)){
			continue;
		}
		if(it.ptr_->weight < i){
			i -= it.ptr_->weight;
			j -= it.ptr_->weight;
		}
		else{
			if(i == 0){
				if(j == 0){
					return true;
				}
				else if(it.ptr_->weight < j){
					for(int a = 0; a < it.ptr_->weight; a++){
						s += it.ptr_->value[a];
					}
					j -= it.ptr_->weight;				
				}
				else if(it.ptr_->weight >= j){
					for(int a = 0; a <= j; a++){
						s += it.ptr_->value[a];
					}
					j = 0;
					return true;
				}
			}
			else if(it.ptr_->weight >= i && it.ptr_->weight < j){
				for(int a = i; a < it.ptr_->weight; a++){
					s += it.ptr_->value[a];
				}
				i = 0;
				j -= it.ptr_->weight;
			}
		}
	}
	return false;
	//assert(0 && "Rope report() not implemented!");
}

//The first i characters should stay in the current rope, while a new
//Rope (rhs) should contain the remaining size_-i characters.
//A valid split should always result in two ropes of non-zero length.
//If the split would not be valid, this rope should not be changed,
//and the rhs rope should be an empty rope.
//The return value should be this rope (the "left") part of the string
//This function should move the nodes to the rhs instead of making new copies.
Rope& Rope::split(int i, Rope& rhs){
	Node* guide = root;
	Node* right_part = NULL;
	while(!is_leaf(guide)){
		if(guide->weight > i){
			guide = guide->left;
			if(guide->parent->right != NULL){
				if(right_part == NULL){
					right_part = guide->parent->right;
					right_part->parent->right = NULL;
					right_part->parent = NULL;
				}
				else{
					Node* s_right_root = new Node;
					right_part->parent = s_right_root;
					s_right_root->right = right_part;
					right_part = guide->parent->right;
					right_part->parent->right = NULL;
					right_part->parent = s_right_root;
					s_right_root->weight = s_right_root->left->weight;
					right_part = s_right_root;
				}
			}
		}
		else{
			i -= guide->weight;
			guide = guide->right;
		}
	}
	if(i != 0){
		std::cout << guide->weight;
		std::string fp = "";
		std::string lp = "";
		for(int a = 0; a < guide->weight; a++){
			if(a < i){
				fp += guide->value[a];
			}
			else{
				lp += guide->value[a];
			}
		}
		Node* ln = new Node;
		Node* rn = new Node;
		ln->value = fp;
		rn->value = lp;
		ln->weight = fp.size();
		rn->weight = lp.size();
		ln->parent = guide;
		rn->parent = guide;
		guide->value = "";
		guide->weight = ln->weight;
		guide->left = ln;
		guide->right = rn;
		guide = rn;
	}
	Node* right_root = new Node;
	Node* mi_op = guide->parent;
	while(mi_op->parent != NULL && mi_op->parent->left == mi_op){
		mi_op->parent->weight -= guide->weight;
		mi_op = mi_op->parent;
	}
	right_part->parent = right_root;
	right_root->right = right_part;
	guide->parent->right = NULL;
	guide->parent = right_root;
	right_root->left = guide;
	right_root->weight = guide->weight;
	rhs.root = right_root;
	root->weight = root->left->weight;
	Node* size_countl = root->left;
	while(size_countl->right != NULL){
		size_countl = size_countl->right;
		root->weight += size_countl->weight;
	}

	Node* size_count0 = root;
	size_ = root->weight;
	while(size_count0->right != NULL){
		size_count0 = size_count0->right;
		size_ += size_count0->weight;
	}

	Node* size_count = rhs.root;
	rhs.size_ = rhs.root->weight;
	while(size_count->right != NULL){
		size_count = size_count->right;
		rhs.size_ += size_count->weight;
	}
	return *this;


	// if(i != 0){
	// 	std::cout << guide->weight;
	// 	std::string fp = "";
	// 	std::string lp = "";
	// 	for(int a = 0; a < guide->weight; a++){
	// 		if(a < i){
	// 			fp += a;
	// 		}
	// 		else{
	// 			lp += a;
	// 		}
	// 	}
	// 	Node* ln = new Node;
	// 	Node* rn = new Node;
	// 	ln->value = fp;
	// 	rn->value = lp;
	// 	ln->weight = fp.size();
	// 	rn->weight = lp.size();
	// 	ln->parent = guide;
	// 	rn->parent = guide;
	// 	guide->value = "";
	// 	guide->weight = ln->weight;
	// 	guide->left = ln;
	// 	guide->right = rn;
	// 	guide = rn;
	// }
	// std::cout << 'o'<<guide->weight<< std::endl;
	// Node* new_right_part = guide->parent;
	// while(new_right_part->parent->right == new_right_part){
	// 	new_right_part = new_right_part->parent;
	// }
	// new_right_part = new_right_part->right;
	// guide->parent->right = NULL;
	// guide->parent = NULL;
	// new_right_part->parent->right = NULL;
	// new_right_part->parent = NULL;
	// Node* right_root = new Node;
	// right_root->left = guide;
	// right_root->right = new_right_part;
	// guide->parent = right_root;
	// new_right_part->parent = right_root;
	// right_root->weight = guide->weight + guide->right->weight;
	// Node* size_count = right_root;
	// rhs.size_ = right_root->weight;
	// while(size_count->right != NULL){
	// 	size_count = size_count->right;
	// 	size_ += size_count->weight;
	// }	
	// rhs.root = right_root;
	// return *this;
	// assert(0 && "Rope split() not implemented!");
}
