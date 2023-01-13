#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    std::ifstream input_text;
    input_text.open(argv[1]);

    //std::ifstream in_str(argv[1]);
    if (!input_text.good()) {
        std::cerr << "Can't open " << argv[1] << " to read.\n";
        exit(1);
  }
    float sum = 0;
    int counter = 0;
    std::string my_variable;
    int minimum = 9999;
    while(input_text >> my_variable){
        counter += 1;
        int num = std::stoi(my_variable);
        //int num = atoi(input_text.c_str());
        sum += num;
        minimum = std::min(num, minimum);
        std::cout << sum << " " << counter << std::endl;
    }
    float avg = sum / counter;
    std::cout << avg  << " " << minimum << std::endl;

    /*while (!in_str.eof()) {
    in_str >> my_variable;
    // do something with my_variable
  }
    inFile.open("first.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
}
    int sum = 0;
    while (inFile >>) {
        sum = sum + x;
    }*/
}
