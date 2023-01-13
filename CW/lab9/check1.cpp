#include <iostream>
#include <fstream>
#include <string>
#include <map> 
#include <algorithm>


int main(int argc, char* argv[]){
    std::map<std::string, int> mode_map;
    std::string num;
    std::ifstream istr(argv[1]);
    while(istr>>num)
        ++mode_map[num];
    std::map<std::string, int>::iterator itr;
    int max = 0;
    for(itr=mode_map.begin(); itr!=mode_map.end(); itr++) 
        max = std::max(itr->second, max);
    for(itr=mode_map.begin(); itr!=mode_map.end(); itr++){
        if(max == itr->second)
            std::cout<<itr->first<<std::endl;
    }
    return 0;
}
