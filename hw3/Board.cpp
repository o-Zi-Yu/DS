
#include "Board.h"
//default constructor
Board::Board(){
    first_ = "";
    second_ = "";
    space_ = "";
    rownum = 5;
    colnum = 4;
}
//constructor
Board::Board(const std::string& fst, const std::string& snd,
 const std::string& spe){
    first_ = fst;
    second_ = snd;
    space_ = spe;
    rownum = 5;
    colnum = 4;
    m_data = new std::string* [colnum];
    counter = new int[4];
    for (int i = 0; i < 4; i++) { //create pointer of array contains null
        m_data[i] = NULL;
        counter[i] = 0;
    }
}

//takes in the column number
int Board::numTokensInRow(int a){
    if ((unsigned int) a >= rownum) {
        return -1;
    }
    int t = 0;
    for (unsigned int i = 0; i < colnum; i++) {
        if (a < counter[i]) { // find if the array size can have the token
            t++;
        }
    }
    return t;
}

//takes in the column number
int Board::numTokensInColumn(int a){
    if ((unsigned int)a >= colnum) {// find if the array can have the token
        return -1;
    }
    return counter[a];
}

//takes in column number and the boolean of first person or second
//return who wins, or space string if nobody wins
std::string Board::insert(unsigned int col, bool b){
    if (b) { //first person
        if (col >= colnum) { //insert excluding
            m_data = create_col(col, first_);
        }
        else { //insert including
            m_data = add_row(col, first_);
        }
    }
    else{ //second person
        if (col >= colnum) {
            m_data = create_col(col, second_);
        }
        else {
            m_data = add_row(col, second_);
        }        
    }
    return win(col);
}

//takes in column number and token of the person to add rows(insert including)
std::string** Board::add_row(unsigned int a, std::string token){
    //create an array has 1 size larger
    std::string *q = new std::string[counter[a] + 1];
    //put all data inside the array
    for (int i = 0; i < counter[a]; i ++) {
        q[i] = m_data[a][i];
    }
    q[counter[a]] = token; //input the token in the last space
    counter[a] += 1; //change the array size counter
    //loop through counter to search if max rownum changes
    for (unsigned int i = 0; i < colnum; i++) {
        if ((int)rownum < counter[i]) {
            rownum = counter[i];
        }
    }
    delete[] m_data[a]; //delete the origin poionter
    m_data[a] = q; //redirect the pointer
    return m_data;
}

//takes in column number and token of the person to add col(insert excluding)
std::string** Board::create_col(unsigned int a, std::string token){
    //create a new pointer to pointer
    std::string **q = new std::string* [a+1];
    //resize the array of column num
    int *s = new int[a+1];
    for (unsigned int i = 0; i < colnum; i++) {
        q[i] = m_data[i];
        s[i] = counter[i];
    }
    for(unsigned int i = colnum;i < a ;i++){
        q[i] = NULL; //null the col if sth is between
        s[i] = 0;
    }
    q[a] = new std::string[1]; //point the end of q to 1
    q[a][0] = token; //set row 0 with token
    for (unsigned int i = 0; i < colnum; i++) {
        m_data[i] = NULL; //redirect pointer to null
    }
    s[a] = 1; //set new col's height
    //delete the pointer
    delete [] m_data;
    delete [] counter;
    counter = s; //redirect pointer of array size
    colnum = a+1; //increase the max column num
    return q;
}

std::string Board::win(unsigned int col){
    //if there is 3 is under
    if (counter[col] >= 4) {
        //check 3 tokens under is same as the token input
        if ((m_data[col][counter[col]-1] == m_data[col][counter[col]-2]) &&
         (m_data[col][counter[col]-2] == m_data[col][counter[col]-3]) && 
         (m_data[col][counter[col]-3] == m_data[col][counter[col]-4])) {
            if (m_data[col][counter[col]-1] == first_) {
                return first_;
            }
            else {
                return second_;
            }
        }
    }

    //set left and right bundary
    int left = col - 3;
    if (left < 0) {left = 0;}
    for (unsigned int i = left; i < col; i++) {
        if (counter[i] < counter[col]) {
            left = i;
        }
    }
    int right = col + 3;
    if ((unsigned int)right > colnum-1) {right = colnum-1;}
    for (unsigned int i = colnum-1; i > col; i--) {
        if (counter[i] < counter[col]) {
            right = i;
        }
    }
    int fst = 0, snd = 0;
    if (right - left >= 4) {
        //search from left to right if 4 tokens are same
        for (int i = left; i < right-3; i++) {
            if (m_data[i][counter[col]-1] == m_data[i+1][counter[col]-1]) {
                if (m_data[i][counter[col]-1] == first_) {
                    fst += 1;
                    snd = 0;
                }
                else {
                    fst = 0;
                    snd += 1;
                }
            }
        }
    }
    if (fst == 3) {
        return first_;
    }
    else if (snd == 3) {
        return second_;
    }
    else {
        return space_;
    }
}

//how to print the board
std::ostream& operator<<(std::ostream& os, const Board& bd){
    //create a new tempory board with spaces
    std::string **temp;
    temp = new std::string* [bd.colnum];
    for (unsigned int i = 0; i < bd.colnum;i++){
        temp[i] = new std::string[bd.rownum];
        for (unsigned int j = 0; j < bd.rownum; j++) {
            temp[i][j] = bd.space_;
        }
    }
    //replace spaces to tokens 
    for (unsigned int i = 0; i < bd.colnum; i++) {
        if (bd.counter[i] == 0) {
            continue;
        }
        else {
            for (int j = 0; j < bd.counter[i]; j++) {
                temp[i][j] = bd.m_data[i][j];
            }
        }
    }
    //print the board
    for (int i = bd.rownum - 1; i >= 0; i--) {
        for (unsigned int j = 0; j < bd.colnum - 1; j++) {
            os << temp[j][i] << ' ';
        }
        os << temp[bd.colnum - 1][i] << std::endl;
    }
    //delete the tempory board
    for(unsigned int i = 0; i < bd.colnum; ++i) {
        delete[] temp[i];   
    }
    //Free the array of pointers
    delete[] temp;    
    return os;
}

//delete all pointers in the board class
void Board::clear(){
    for(unsigned int i = 0; i < colnum; ++i) {
        delete[] m_data[i];   
    }
    delete[] m_data; 
    delete[] counter;
    Board(first_, second_, space_); //initialize
}

//destructor, delete all pointers in the board class
Board::~Board() {
    for(unsigned int i = 0; i < colnum; ++i) {
        delete[] m_data[i];   
    }
    delete[] m_data; 
    delete[] counter;
}

// Assign one board class to another, avoiding duplicate copying.
Board& Board::operator=(const Board& v) {
    if (this != &v) {
        this -> copy(v);
    }
    return *this;
}

void Board::copy(const Board& v) {
    clear(); //delete pointers it already has
    first_ = v.first_;
    second_ = v.second_;
    space_ = v.space_;
    rownum = v.rownum;
    colnum = v.colnum;
    counter = new int[colnum];
    for (unsigned int i = 0; i < colnum; i ++) { //copy counter
        counter[i] = v.counter[i];
    }
    m_data = new std::string* [v.colnum]; //copy pointer to pointer
    for (unsigned int i = 0; i < colnum; i++) {
        m_data[i] = new std::string[counter[i]];
        for (int j = 0; j < counter[i]; j++) {
            this -> m_data[i][j] = v.m_data[i][j];
        }
    }
}
