
#include "Board.h"
int Board::numTokensInRow(int a){
    if (a >= rownum) {
        return -1;
    }
    int token_count = 0;
    for (unsigned int i = 0; i < colnum; i++) {
        if (p[i][a] != space_){
            token_count ++;
        }
    }
    return token_count;
}

int Board::numTokensInColumn(int a){
    if (a >= colnum) {
        return -1;
    }
    int token_count = 0;
    for (unsigned int i = 0; i < rownum; i++) {
        if (p[a][i] != space_){
            token_count ++;
        }
    }
    return token_count;
}

std::string Board::insert(unsigned int col, bool b){
    if (b) {
        if (col >= colnum) {
            p = create_col(p, colnum, rownum, col, space_, first_);
        }
        else {
            unsigned int h = height(p, col);
            if (h <= rownum) {
                p[col][h] = first_;
            }
            else {
                p = create_row(p, colnum, rownum, col, space_, first_);
            }
        }
    }
    else {
        if (col >= colnum) {
            p = create_col(p, colnum, rownum, col, space_, second_);
        }
        else {
            unsigned int h = height(p, col);
            if (h <= rownum) {
                p[col][h] = second_;
            }
            else {
                p = create_row(p, colnum, rownum, col, space_, second_);
            }
        }
    }
    return "win";
}

std::string** Board::create_col(std::string **p, unsigned int colnum, unsigned int rownum, unsigned int a, std::string space_, std::string token){
    std::string **q = new std::string* [a+1];
    for (unsigned int i = 0; i < colnum; i++) {
        q[i] = *p;
    }
    for (unsigned int i = colnum; i < a+1; i++) {
        q[i] = new std::string [rownum];
    }
    q[a][0] = token;
    delete [] p;
    return q;
    // std::string **q = new std::string* [rownum];
    // for (unsigned int i = 0; i < colnum; i++){
    //     q[i] = new std::string[a + 1];
    // }
    
    // for (unsigned int i = 0; i < colnum; i++) {
    //     for (unsigned int j = 0; j < rownum; j++) {
    //         q[i][j] = p[i][j];
    //     }
    //     for (unsigned int k = rownum; k < a; k++) {
    //         q[i][k] = space_;
    //     }
    //     q[colnum][a] = token;
    // }
    // for(unsigned int i = 0; i < rownum; ++i) {
    //     delete[] p[i];   
    // }
    // //Free the array of pointers
    // delete[] p;
    // return q;
    // for (unsigned int i = colnum; i < a; i++){
    //     p[i] = new std::string[rownum];
    //     for (unsigned int k = 0; k < colnum; k++) {
    //         p[i][k] = space_;
    //     }
    // }
    // p[a][0] = token;
}

unsigned int Board::height(std::string **p, unsigned int col) {
    for (unsigned int i = 0; i < rownum; i++) {
        if (p[col][i] != space_) {
            return i;
        }
    }
    return 999;
}

std::string** Board::create_row(std::string **p, unsigned int colnum, unsigned int rownum, unsigned int a, std::string space_, std::string token){
    std::string **q = new std::string* [colnum];
    for (unsigned int i = 0; i < colnum;i++){
        q[i] = new std::string[rownum+1];
        for (unsigned int j = 0; j < rownum; j++) {
            q[i][j] = p[i][j];
        } 
        q[i][rownum] = space_;
    }
    q[a][rownum] = token;
    for(unsigned int i = 0; i < colnum; ++i) {
        delete[] p[i];   
    }
    return q;
}

std::ostream& operator<<(std::ostream& os, const Board& bd){
    
    for (int i = bd.rownum - 1; i >= 0; i--) {
        for (unsigned int j = 0; j < bd.colnum; j++) {
            os << bd.p[j][i] << ' ';
        }
        os << std::endl;
    }
    return os;
}
