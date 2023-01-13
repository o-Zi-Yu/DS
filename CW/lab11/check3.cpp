

#include <iostream>



class Node{
    public:
        int value;
        Node* left;
        Node* right;

};

bool shape_match(Node* a,Node* b){
    //Case 0: both node are end node
    if(!a->left && !a->right && !b->left && !b->right){
        return true;
    }

    //Case 1: left are both DNE, right both exist and same
    if(!a->left && !b->left){
        if(a->right && b->right){
            if(shape_match(a->right,b->right)){
               return true;
           }
        }
    }

    //Case 2: right are both DNE, left exist and same
    if(!a->right && !b->right){
        if(a->left && b->left){
            if(shape_match(a->left,b->left)){
               return true;
           }
        }
    }
    //Case 3: left and right both exist and same
    if(a->left && b->left){
        if(shape_match(a->left,b->left)){
            if(a->right && b->right){
                if(shape_match(a->right,b->right)){
                    return true;
                }
            }
        }
    }

    return false;

}

Node* find_subtree_match (Node* a,Node* b){
    if(!a->left && !a->right && !b->left && !b->right){
        return a;
    }
    if(!a->left && !b->left){
        if(a->right && b->right){
            if (!find_subtree_match(a->right, b->right)) {
                return a;
            }
        }
    }

    if(!a->right && !b->right){
        if(a->left && b->left){
            if(!find_subtree_match(a->left,b->left)){
               return a;
           }
        }
    }
    if(a->left && b->left){
        if(!find_subtree_match(a->left,b->left)){
            if(a->right && b->right){
                if(!find_subtree_match(a->right,b->right)){
                    return a;
                }
            }
        }
    }
    return NULL;

}

int main(){
	Node* ret = new Node;
    ret->value = 5;
	ret->left = new Node;
    ret->left->value = 4;
	ret->left->left = new Node;
    ret->left->left->value = 6;
	ret->left->right = new Node;
    ret->left->right->value = 7;
	ret->left->left->left = new Node;
	ret->left->left->left->value = 1;
	ret->left->left->right = new Node;
	ret->left->left->right->value = 2;
	ret->left->right->left = new Node;
    ret->left->right->left->value = 8;
	ret->left->right->right = new Node;
    ret->left->right->right->value = 9;
	ret->left->right->left->left = new Node;
    ret->left->right->left->left->value = 10;
	ret->left->right->left->right = new Node;
	ret->left->right->left->left->value = 3;

    Node* tre = new Node;
    tre->value = 5;
	tre->left = new Node;
    tre->left->value = 4;
	tre->left->left = new Node;
    tre->left->left->value = 6;
	tre->left->right = new Node;
    tre->left->right->value = 7;
	tre->left->left->left = new Node;
	tre->left->left->left->value = 1;
	tre->left->left->right = new Node;
	tre->left->left->right->value = 2;
	tre->left->right->left = new Node;
    tre->left->right->left->value = 8;
	tre->left->right->right = new Node;
    tre->left->right->right->value = 9;
	tre->left->right->left->left = new Node;
    tre->left->right->left->left->value = 10;
	tre->left->right->left->right = new Node;
	tre->left->right->left->left->value = 3;

    Node* etr = new Node;
    etr->value = 5;
	etr->left = new Node;
    etr->left->value = 4;
	etr->left->left = new Node;
    etr->left->left->value = 6;

    std::cout << shape_match(ret, tre) << std::endl;
    std::cout << find_subtree_match(ret, etr) << std::endl;

    return 0;
}