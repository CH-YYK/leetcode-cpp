#include <iostream>
#include "Solution.h"
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>


int main() {
    std::string str("hello world");
    for(auto i:str) std::cout << i << " ";
    std::cout << "\n";

    std::map<char, int> map = {{'1', 1}, {'2', 2}};

    for(auto i=map.begin(); i!=map.end(); i++) std::cout << " " << i->second;
    std::cout << "\n";
    for(auto i:map) std::cout << " " << i.second;
    std::cout << "\n";
    return 0;
}