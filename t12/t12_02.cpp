#include <iostream>
#include <cstdio>

typedef unsigned long long ULL;


int main() {
    ULL sum=0, tmp;
    std::cout << "enter your number line: "<<std::endl;
    char buffer[11];
    while (std::cin.get(buffer, 11)) {
        std:: cout<<buffer<<std::endl;
        int res=sscanf(buffer, "%llu", &tmp);
        if (res!=1) {
            break;
        }
        sum += tmp;
    }
    std::cout << "sum="<<sum << std::endl;
}