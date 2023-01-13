
#include <fstream>
#include <iostream>
#include <string>

void compute_squares(unsigned int a[], unsigned int b[], const unsigned int n){
    unsigned int *p, *q;
    for (p = a, q = &b[0]; p < a+n; p++, q++){
        //*p = a[p-a] * a[p-a];
        *q = *p * *p;
        
        //std::cout << *p << std::endl;
    }
    for(int i = 0; i < n; i++){
        std::cout << b[i] << std::endl;
    }
}

int main(){
    unsigned int a[4] = {1, 2, 3, 4};
    unsigned int b[4];
    unsigned int c[5] = {1, 2, 3, 4, 8};
    unsigned int d[5];
    compute_squares(a, b, 4);
    compute_squares(c, d, 5);
}