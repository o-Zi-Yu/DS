#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>

void SequenceA(std::list<int>& l1){  
  std::list<int> l_tmp;  
  std::list<int*> l2;  
  for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++){  
    l_tmp.push_back(*it);  
    l2.push_back(&(l_tmp.back()));  
  }  
  int sum = 0;  
  for(std::list<int*>::iterator it = l2.begin(); it != l2.end(); it++){  
    sum += *(*it);  
  }  
  std::cout << sum << std::endl;  
}  

void SequenceB(std::vector<int>& v1){  
  std::vector<int> v_tmp;  
  std::vector<int*> v2;  
  for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++){  
    v_tmp.push_back(*it);  
    v2.push_back(&(v_tmp.back()));  
  }  
  int sum = 0;  
  for(std::vector<int*>::iterator it = v2.begin(); it != v2.end(); it++){  
    sum += *(*it);  
  }  
  std::cout << sum << std::endl;  
}

int main(){
    std::vector<int> b;
    b.push_back(11);
    b.push_back(21);
    b.push_back(31);
    b.push_back(41);
    b.push_back(51);
    SequenceB(b);
    return 1;
}
class PhraseNode {  
    public:  
      PhraseNode(const std::string& p) : phrase(p), next(NULL) {}  
      std::string phrase;  
      PhraseNode* next;  
      std::vector<PhraseNode*> options;  
};  
std::vector<std::string> original_sentence = {"I'm", "almost", "done", "with", "this", "course"};
PhraseNode* createSentenceLL(const std::vector<std::string>& original_sentence) {
    PhraseNode* a = new PhraseNode(original_sentence[0]);
    PhraseNode* b = a;
    for (uint i = 1; i < original_sentence.size(); i++) {
        a->next = new PhraseNode(original_sentence[i]);
        a = a->next;
    }
    return b;
}

//std::map<std::string, std::list<std::string> >subs = {"almost": <"nearly", "more or less">, "done": <"finished", "through">, "course": <"class">, "not a word": <"garbage", "filler", "none">};
void addOptionsToList(std::map<std::string, std::list<std::string> >& subs, PhraseNode* head) {
    PhraseNode* a = head;
    while(a) {
        if (subs.find(a->phrase) != subs.end()) {
            std::list<std::string> option_list = subs[a->phrase];
            std::list<std::string>::iterator itr;
            for (itr = option_list.begin(); itr != option_list.end(); itr++) {
                PhraseNode* b = new PhraseNode(*itr);
                b->next = a->next;
                a->options.push_back(b); 
            }
        }
        a = a->next;
    }
}

void generateSentences(std::vector<std::string>& sentences, PhraseNode* head, int complete){
    if(complete == 0)
        sentences.push_back(head->phrase);
    for (uint i = 0; i < head->options.size(); i++){
        sentences[sentences.size()]+= head->options[i]->phrase;
        if (head->next)
            generateSentences(sentences, head->next, 1);
        else {
            complete = 0;
        }
    }
}

void cleanupList(PhraseNode* head){
    while(head){
        for (uint i = 0; i < head->options.size(); i++) {
            delete head->options[i];
        }
        PhraseNode* before = head;
        head = head->next;
        delete before;
    }
}


class Node {  
public:  
  int number;  
  std::string name;  
  Node* next;  
};  
void ConvertHashSet(std::vector<std::list<Node*> >& hs, unsigned int new_size) {
    int num = hs.size();
    for (int i = 0; i < num; i++) {
        if(hs[i].size() != 1 && hs[i].size() != 0) {
            std::list<Node*>::iterator itr;
            for (itr = hs[i].begin(); itr != hs[i].end(); itr++) {
                int a = itr->number;
                bool b = false;
                while(b){
                    if(!hs[a]) {
                        hs[a] = *itr;
                    }
                    else{
                        a = (a+1)/new_size;
                    }
                }
            }
        }
    }
}