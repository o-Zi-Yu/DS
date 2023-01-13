//if (head == NULL)
if (!head){
    head = tmp;
}
else{
    //find end
    Node<T>* tmp2 = head;
    while(tmp2->ptr){
        tmp2=tmp2->ptr;
    }
    //attch to end
    tmp2->ptr=tmp;
}

void Copyall (Node<T>* old_head, Node<T>*& new_head) {
    if(!old_head){
        new_head = NULL;
    }
    else{
        new_head = new Node<T>;
        new_head -> value = old_head -> value;
        Copyall(old_head->ptr, new_head->ptr);
    }
}`                                                  

template <class T> void Removeall(Node<T>*& head) {
    if (head == NULL){
        //do nothing
    }
    else{
        if (head->ptr == NULL) {
            delete head;
            head = NULL;
            return
        }
    }
    Removeall(head->ptr);
    delete head;
    head = NULL;
}

//insert
Node<int>* tmp = new Node<int>(15);
tmp->next= ->next;
p->next= tmp;
tmp ->next->prev = tmp;
tmp->prev = p;