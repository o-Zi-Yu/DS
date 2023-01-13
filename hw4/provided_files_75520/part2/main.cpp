//
// PROVIDED CODE FOR HOMEWORK 4: GROCERY LISTS
// 
// You may use none, a little, or all of this, as you choose, but we
// strongly urge you to examine it carefully.  You may modify this
// code as you wish to complete the assignment.
//


#include "recipe.h"
#include "kitchen.h"
#include <cassert>

// Helper functions
void readRecipe(std::istream &istr, std::ostream &ostr, 
  std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr,
  Kitchen &kitchen);
void printRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void makeRecipe(std::istream &istr, std::ostream &ostr, 
  const std::list<Recipe> &recipes, Kitchen &kitchen);

// The main loop parses opens the files for I/O & parses the input
int main(int argc, char* argv[]) {

  // Check the number of arguments.
  if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
      return 1;
  }
  // Open and test the input file.
  std::ifstream istr(argv[1]);
  if (!istr) {
      std::cerr << "Could not open " << argv[1] << " to read\n";
      return 1;
  }
  // Open and test the output file.
  std::ofstream ostr(argv[2]);
  if (!ostr) {
      std::cerr << "Could not open " << argv[2] << " to write\n";
      return 1;
  }

  // the kitchen & recipe list
  Kitchen kitchen;
  std::list<Recipe> recipes;

  // some variables to help with parsing
  char c;
    while (istr >> c) {
        if (c == 'r') {
            // READ A NEW RECIPE
            readRecipe(istr,ostr,recipes);

        } else if (c == 'a') {
            // ADD INGREDIENTS TO THE KITCHEN
            addIngredients(istr,ostr,kitchen);

        } else if (c == 'p') {
            // PRINT A PARTICULAR RECIPE
            printRecipe(istr,ostr,recipes);

        } else if (c == 'm') {
            // MAKE SOME FOOD
            makeRecipe(istr,ostr,recipes,kitchen);

        } else if (c == 'k') {
            // PRINT THE CONTENTS OF THE KITCHEN
            kitchen.printIngredients(ostr);

        } else {
            std::cerr << "unknown character: " << c << std::endl;
            exit(0);
        }
    }  
}

/*the function reads in the input file and output file name. 
The recipes list contains recipes. The functions goes into the 
list and add new recipes into the list if it doesn't exist.
*/
void readRecipe(std::istream &istr, std::ostream &ostr,
  std::list<Recipe> &recipes) {
    int units;
    std::string name, name2;  
    istr >> name;
    // build the new recipe
    Recipe r(name);
    while (1) {
        istr >> units;
        if (units == 0) break;
        assert (units > 0);
        istr >> name2;
        r.addIngredient(name2,units);
    }
    //check if recipe is in the list
    std::list<Recipe>::iterator itr = recipes.begin();
    bool contain = false;
    for (itr = recipes.begin(); itr != recipes.end(); itr++) {
        contain |= (name==(itr->get_rname()));
    }
    if (contain) {
        ostr << "Recipe for " << name << " already exists" << std::endl;
    }
    else {
        // add it to the list
        recipes.push_back(r);
        ostr << "Recipe for " << name << " added" << std::endl;
    }
}

/*the function reads in the input file and output file name. 
The kitchen class contains ingridents in it. It waits until
input is 0 to add ingredients into the kitchen in the list in it. 
*/
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
    int units;
    std::string name;
    int count = 0;
    while (1) {
        istr >> units;
        if (units == 0) break;
        assert (units > 0);
        istr >> name;
        // add the ingredients to the kitchen
        kitchen.addIngredient(name,units);
        count++;
    }

    if (count == 1) {
        ostr << "1 ingredient added to kitchen" << std::endl;
    }
    else {
        ostr << count << " ingredients added to kitchen" << std::endl;
    }
}

/*the function reads in the input file and output file name. 
The recipes list contains recipes. It loop through the recipe with
specific name of recipe. Then output all the ingredients in the recipe
*/
void printRecipe(std::istream &istr, std::ostream &ostr,
  std::list<Recipe> &recipes) {
    std::string name;
    istr >> name;
    //check if recipe is in the list
    std::list<Recipe>::iterator itr;
    bool contain = false;
    for (itr = recipes.begin(); itr != recipes.end(); itr++) {
        if (name==itr->get_rname()) {
            contain = true;
            break;
        }
    }

    if (!contain) {
        ostr << "No recipe for " << name << std::endl;
    }
    else {
        itr->print(ostr);
    }
}

/*the function reads in the input file and output file name. 
The recipes list contains recipes. It checks if the recipe name exists,
then check if the ingreident is enough. If not, it prints out the needed
ingridents.
*/
void makeRecipe(std::istream &istr, std::ostream &ostr,
  const std::list<Recipe> &recipes, Kitchen &kitchen) {
    std::string name;
    istr >> name;
    //check if recipe is in the list
    std::list<Recipe>::const_iterator itr = recipes.begin();
    bool contain = false;
    for (itr = recipes.begin(); itr != recipes.end(); itr++) {
        if (name==itr->get_rname()) {
            contain = true;
            break;
        }
    }
    if (!contain) {
        ostr << "Don't know how to make " << name << std::endl;
    }
    else {
        //create new list to erase to check whether ingredients is enough
        std::list<std::string> l_temp_list(itr->get_ingredient());
        std::list<std::string> k_temp_list(kitchen.get_ingredient());
        for (std::list<std::string>::iterator i = l_temp_list.begin();
          i != l_temp_list.end(); i++) {
            for (std::list<std::string>::iterator j = k_temp_list.begin();
              j != k_temp_list.end(); j++) {
                if (*i == *j) {
                    i = l_temp_list.erase(i);
                    j = k_temp_list.erase(j);
                    i--, j--;
                }
            }
        }
        //ingredients is enough
        if (l_temp_list.size() == 0) {
            kitchen.make_recipe(k_temp_list);
            ostr << "Made " << itr->get_rname() << std::endl;
        }
        else { // not enough
            l_temp_list.sort(); //sort by alphabetical order
            std::list<std::string>::iterator i = l_temp_list.begin();
            std::string a = *i;
            int counter = 0;
            ostr << "Cannot make " << itr->get_rname() << ", need to buy:" 
              << std::endl;
            //the ingredients in the list is needed
            //use counter to find out the number of ingredients
            for (i = l_temp_list.begin(); i != l_temp_list.end(); i++) {
                if(a==*i){
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
                a = *i;
            }
            //last ingredient
            if (counter == 1) {
                ostr << "  1 unit of " << a << std::endl;
            }
            else {
                ostr << "  " << counter << " units of " << a << std::endl;
            }
        }
    }
}



