// These "include guards" prevent errors from "multiple includes"
#ifndef __name_h_
#define __name_h_
#include <iostream>
#include <string>
class Name {
    public:
        // CONSTRUCTOR (with default arguments)
        Name(const std::string& fst="", const std::string& lst="");
        // ACCESSORS
        // Providing a const reference to the string allows the string to be
        // examined and treated as an r-value without the cost of copying it.
        const std::string& first() const { return first_; }
        const std::string& last() const { return last_; }
        // MODIFIERS
        void set_first(const std::string & fst) { first_ = fst; }
        void set_last(const std::string& lst) { last_ = lst; }
    private:
        // REPRESENTATION
        std::string first_, last_;
};
        // operator< to allow sorting
        bool operator< (const Name& left, const Name& right);
        // operator<< to allow output
        std::ostream& operator<< (std::ostream& ostr, const Name& n);
#endif

int q[3] = {1, 3, 2};
*z = &q[1];
int p = 20;
int* x = &p;
std::string *y = new std::string[2];
*y[0] = 
y = new std::string;
*y = "five";
