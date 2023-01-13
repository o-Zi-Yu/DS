#include "kitchen.h"

//loop times to add ingredient into the list
void Kitchen::addIngredient(std::string &name2, int units){
    ingredient = name2;
    unit_ = units;
    for(int i = 0; i < unit_; i++) {
        k_ingredient.push_back(ingredient);
    }
}

//print out the ingredients in kitchen with numbers
void Kitchen::printIngredients(std::ostream &ostr) {
    ostr << "In the kitchen:" << std::endl;
    //count number by first sorting in alphabetical order
    k_ingredient.sort();
    std::list<std::string>::iterator itr = k_ingredient.begin();
    std::string a = *itr;
    int counter = 0;
    k_num_ingreident.clear();
    //use counter to find out the number of ingredients
    for (itr = k_ingredient.begin(); itr != k_ingredient.end(); itr++) {
        if(a==*itr){
            counter+=1;
        }
        //next ingredient
        else {
            k_num_ingreident.push_back(std::to_string(counter)+a);
            counter = 1;
        }
        a = *itr;
    }
    //add number with the ingredient in the new list
    k_num_ingreident.push_back(std::to_string(counter)+a);
    //sort by number, then by alphabetical order
    k_num_ingreident.sort(sort_by_number);
    itr = k_num_ingreident.begin();
    a = *itr;
    for (itr = k_num_ingreident.begin(); itr != k_num_ingreident.end(); itr++) {
        uint i;
        //loop through the string to find where number ends
        for (i = 0; i < itr->length(); i++) {
            if (!isdigit((*itr)[i])) {break;}
        }
        //split the number with string then output
        if (itr->substr(0,i) == "1") {
            ostr << "  1 unit of " << itr->substr(i,itr->size()) << std::endl;
        }
        else {
            ostr << "  " << itr->substr(0,i) << " units of " << itr->substr(i,itr->size()) << std::endl;
        }
    }
}

//sort by number, then by alphabetical order
bool sort_by_number(const std::string &a, const std::string &b) {
    uint i, j;
    //loop through the string to find where number ends
    for (i = 0; i < a.length(); i++) {
        if (!isdigit(a[i])) {break;}
    }
    for (j = 0; j < b.length(); j++) {
        if (!isdigit(b[j])) {break;}
    }
    //split the number with string then output
    int numa = std::stoi(a.substr(0,i));
    int numb = std::stoi(b.substr(0,j));
    if (numa<numb) {return true;}
    if (numa==numb && a<b) {return true;}
    return false;
}