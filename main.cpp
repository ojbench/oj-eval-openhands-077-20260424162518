


#include <iostream>
#include "CrossArray.hpp"

int main() {
    // Simple test to verify compilation
    sjtu::CrossArray arr1(5);
    
    int test1[] = {1, 2, 3};
    arr1.InsertArrays(test1, 3);
    
    int test2[] = {4, 5};
    arr1.InsertArrays(test2, 2);
    
    std::cout << "Test array created successfully" << std::endl;
    std::cout << "Element at [0][0]: " << arr1.At(0, 0) << std::endl;
    std::cout << "Element at [0][1]: " << arr1.At(0, 1) << std::endl;
    std::cout << "Element at [1][0]: " << arr1.At(1, 0) << std::endl;
    
    return 0;
}


