#include <iostream>
#include "Solution.h"

int main() {
    int qNum;
    std::cout << "Type in the Integer : " << "\n";
    std::cin >> qNum;

    printf("The Answer is %d", Solution().reverse(qNum));
    return 0;
}