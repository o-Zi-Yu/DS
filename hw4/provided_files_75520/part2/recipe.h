#ifndef __recipe_h_
#define __recipe_h_
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include <cctype>

class Recipe {
    public:
        //constructor
        Recipe();
        Recipe(const std::string &a) {r_name=a;};
        //accessor
        const std::string& get_rname() const{return r_name;};
        const std::list<std::string>& get_ingredient() const{return l_ingredient;}
        //member function
        void addIngredient(std::string &name2, int units);
        void print(std::ostream &ostr);
        

    private:
        std::string r_name, ingredient;
        int unit_;
        std::list<std::string> l_ingredient;
};
#endif
