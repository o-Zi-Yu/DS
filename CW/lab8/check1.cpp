#include <fstream>
#include <iostream>

int noblock(int x, int y);

int main() {
    std::cout << "no block is " << noblock(1, 1) << std::endl;
}

int noblock(int x, int y){
    if (x == 0) {
      return 1;
    }
    if (y == 0) {
      return 1;
    }
    if (x == 0 && y == 0) {
      return 1;
    }
    return noblock(x - 1, y) + noblock(x, y - 1);
}

