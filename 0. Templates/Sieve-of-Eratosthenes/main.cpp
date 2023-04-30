#include <iostream>
#include "Solution.h"

void test(int N);
void test2();

// static const int N = 10;
int main() {
    test2();
    // test
    // test(20);
    /*
    int *ans = Solution().printPrimesUnderN(10);
    int j = 0;
    while(*(ans+j)){
        if(*(ans+j) == 1) std::cout << j << "\n";
        j++;
    }
    */
    int *ans;
    ans = Solution().printPrimesUnderN(20);
    // std::cout << "First element : " << *(ans) << "\n";
    std::cout << std::endl;

    for(int i = 0; i < 50; i++) std::cout << " " << ans[i];
    // while(ans) std::cout << " " << *ans; ans++;

    std::cout << "\n";
    return 0;
}

void test(int N) {
    int a[N];
    for(int i = 2; i < N; i++) a[i] = 1;
    for(int i = 2; i < N; i++)
        if(a[i])
            for(int j = i; j*i < N; j++) a[i*j] = 0;
    //for(int i = 2; i < N; i++)
    //    if(a[i]) std::cout << " " << i;
    //std::cout << std::endl;
    std::cout << " " << *(a+2);
    int k = 1;
    while((a+k)){
        std::cout << " " << *(a+k);
        k += 1;
    }
    std::cout << std::endl;

}

void test2() {
    char cString[] = {'A', 'B', 'C', 'D'};
    int cArray[] = {1, 2, 3, 4};
    std::cout << "String Size is " << sizeof('a') << "\n";
    std::cout << "Array size is " << sizeof(cArray) << "\n";
}