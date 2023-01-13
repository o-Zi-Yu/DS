#ifndef __kitchen_h_
#define __kitchen_h_
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <cctype>
#include <algorithm>

class Kitchen {
    public:
        //accessor
        const std::list<std::string>& get_ingredient(){return k_ingredient;}
        //member functions
        void addIngredient(std::string &name2, int units);
        void printIngredients(std::ostream &ostr);
        void make_recipe(std::list<std::string> &a) {k_ingredient = a;}
        
    private:
        std::string r_name, ingredient;
        int unit_;
        std::list<std::string> k_ingredient, k_num_ingreident;
};
//non-member function
bool sort_by_number(const std::string &a, const std::string &b);
#endif
