#include <iostream>
#include <fstream>
#include <string>
#include <map> 
#include <algorithm>


int main(int argc, char* argv[]){
    std::map<std::string, int> mode_map;
    std::string num;
    std::ifstream istr(argv[1]);
    std::map<std::string, int>::iterator itr;
    while(istr>>num){
        if(mode_map.find(num) == mode_map.end()){
            mode_map.insert(std::make_pair(num, 1));
        }
        else{
            mode_map.find(num)->second++;
        }
    }
    int max = 0;
    for(itr=mode_map.begin(); itr!=mode_map.end(); itr++) 
        max = std::max(itr->second, max);
    for(itr=mode_map.begin(); itr!=mode_map.end(); itr++){
        if(max == itr->second)
            std::cout<<itr->first<<std::endl;
    }
    return 0;
}
