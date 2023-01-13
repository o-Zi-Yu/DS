
#ifndef __board_h_
#define __board_h_
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

class Board {
    public:
        Board(const std::string& fst, const std::string& snd, const std::string& spe){
            first_ = fst;
            second_ = snd;
            space_ = spe;
            rownum = 5;
            colnum = 4;
            p = new std::string* [colnum];
            for (unsigned int i = 0; i < colnum;i++){
                p[i] = new std::string[rownum];
                for (unsigned int j = 0; j < rownum; j++) {
                    p[i][j] = space_;
                }
            }
        }
        int numTokensInRow(int a);
        int numTokensInColumn(int a);
        std::string insert(unsigned int a, bool b);
        unsigned int height(std::string **p, unsigned int rownum);

        int numRows(){return rownum;}
        int numColumns(){return colnum;}
        std::string** create_col(std::string **p, unsigned int colnum, unsigned int rownum, unsigned int a, std::string space_, std::string token);
        std::string** create_row(std::string **p, unsigned int colnum, unsigned int rownum, unsigned int a, std::string space_, std::string token);
        //std::string** (create_row(std::string **p, unsigned int colnum, unsigned int rownum, unsigned int a, std::string space_, std::string token));
        friend std::ostream& operator<<(std::ostream& os, const Board& bd);
        

    private:
        std::string first_, second_, space_;
        unsigned int rownum, colnum;
        std::string **p;
};
#endif
