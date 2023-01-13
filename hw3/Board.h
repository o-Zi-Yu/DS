#ifndef __board_h_
#define __board_h_
#include <iostream>
#include <string>

class Board {
    public:
        //constructor
        Board();
        Board(const std::string& fst, const std::string& snd, 
         const std::string& spe);
        //assignment operator
        Board& operator=(const Board& v); 
        //destructor
        ~Board();

        //accessor
        int numRows(){return rownum;}
        int numColumns(){return colnum;}
        int numTokensInRow(int a);
        int numTokensInColumn(int a);

        //member function
        std::string insert(unsigned int a, bool b);
        std::string win(unsigned int col);
        std::string** create_col(unsigned int a, std::string token);
        std::string** add_row(unsigned int a, std::string token);
        friend std::ostream& operator<<(std::ostream& os, const Board& bd);
        void clear();
        void copy(const Board& v); 

    private:
        std::string first_, second_, space_;
        unsigned int rownum, colnum;
        std::string **m_data;
        int *counter;
        
};
#endif
