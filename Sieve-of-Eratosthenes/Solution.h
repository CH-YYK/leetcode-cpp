#include <iostream>

int N = 20;
class Solution {
public:
    int * printPrimesUnderN(int N) {
        static int a[20];
        for(int i = 2; i < N; i++) a[i] = 1;
        for(int i = 2; i < N; i++)
            if(a[i])
                for(int j = i; j * i < N; j++) a[j*i] = 0;
        /*
        for(int k = 0; k < N; k++)
            if(a[k])
                std::cout << " " << k;
        std::cout << std::endl;
        */
        return a;
    }
};