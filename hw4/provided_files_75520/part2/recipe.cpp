#include "recipe.h"

//loop times to add ingredient into the list
void Recipe::addIngredient(std::string &name2, int units){
    ingredient = name2;
    unit_ = units;
    for(int i = 0; i < unit_; i++) {
        l_ingredient.push_back(ingredient);
    }
}

//print out the recipe with numbers
void Recipe::print(std::ostream &ostr) {
    l_ingredient.sort(); //sort in alphabetical order
    std::list<std::string>::const_iterator itr = l_ingredient.begin();
    std::string a = *itr;
    int counter = 0;
    ostr << "To make " << get_rname() << ", mix together:" << std::endl;
    //use counter to find out the number of ingredients
    for (itr = l_ingredient.begin(); itr != l_ingredient.end(); itr++) {
        if(a==*itr){
            counter+=1;
        }
        //next ingredient
        else {
            if (counter == 1) {
                ostr << "  1 unit of " << a << std::endl;
            }
            else {
                ostr << "  " << counter << " units of " << a << std::endl;
            }
            counter = 1;
        }
        a = *itr;
    }
    //last ingreident
    if (counter == 1) {
        ostr << "  1 unit of " << a << std::endl;
        }
        else {
            ostr << "  " << counter << " units of " << a << std::endl;
    }
}
