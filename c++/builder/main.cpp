#include <iostream>

#include "Builder.h"

int main() {
    Builder b{"root"};
    b.addChild("child1");
    b.addChild("child2");

    std::cout << b.str();
    
    return 0;
}