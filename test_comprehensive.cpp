


#include <iostream>
#include <cassert>
#include "src.hpp"

void test_basic_functionality() {
    std::cout << "Testing basic functionality..." << std::endl;
    
    sjtu::CrossArray arr(3);
    
    // Test InsertArrays
    int arr1[] = {1, 2, 3};
    assert(arr.InsertArrays(arr1, 3) == true);
    
    int arr2[] = {4, 5};
    assert(arr.InsertArrays(arr2, 2) == true);
    
    // Test At function
    assert(arr.At(0, 0) == 1);
    assert(arr.At(0, 1) == 2);
    assert(arr.At(0, 2) == 3);
    assert(arr.At(1, 0) == 4);
    assert(arr.At(1, 1) == 5);
    
    // Test AtArray function
    const int* ptr = arr.AtArray(0);
    assert(ptr[0] == 1 && ptr[1] == 2 && ptr[2] == 3);
    
    std::cout << "Basic functionality test passed!" << std::endl;
}

void test_copy_constructor() {
    std::cout << "Testing copy constructor..." << std::endl;
    
    sjtu::CrossArray arr1(3);
    int arr1_data[] = {1, 2, 3};
    arr1.InsertArrays(arr1_data, 3);
    
    sjtu::CrossArray arr2(arr1);
    
    // Test that they have same values but different memory
    assert(arr2.At(0, 0) == 1);
    assert(arr2.At(0, 1) == 2);
    assert(arr2.At(0, 2) == 3);
    assert(arr1.IsSame(arr2) == false);
    
    // Modify original and check copy is unchanged
    arr1.At(0, 0) = 99;
    assert(arr2.At(0, 0) == 1);
    
    std::cout << "Copy constructor test passed!" << std::endl;
}

void test_append_arrays() {
    std::cout << "Testing AppendArrays..." << std::endl;
    
    sjtu::CrossArray arr(2);
    int arr1[] = {1, 2};
    arr.InsertArrays(arr1, 2);
    
    int append_data[] = {3, 4, 5};
    arr.AppendArrays(append_data, 0, 3);
    
    assert(arr.At(0, 0) == 1);
    assert(arr.At(0, 1) == 2);
    assert(arr.At(0, 2) == 3);
    assert(arr.At(0, 3) == 4);
    assert(arr.At(0, 4) == 5);
    
    std::cout << "AppendArrays test passed!" << std::endl;
}

void test_which_greater() {
    std::cout << "Testing WhichGreater..." << std::endl;
    
    sjtu::CrossArray arr1(3);
    sjtu::CrossArray arr2(3);
    
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5};
    
    arr1.InsertArrays(data1, 3);
    arr2.InsertArrays(data2, 2);
    
    sjtu::CrossArray& greater = arr1.WhichGreater(arr2);
    assert(&greater == &arr1);  // arr1 has more elements
    
    std::cout << "WhichGreater test passed!" << std::endl;
}

void test_double_cross_length() {
    std::cout << "Testing DoubleCrossLength..." << std::endl;
    
    sjtu::CrossArray arr(2);
    int data[] = {1, 2, 3};
    arr.InsertArrays(data, 3);
    
    arr.DoubleCrossLength();
    
    // Original data should still be accessible
    assert(arr.At(0, 0) == 1);
    assert(arr.At(0, 1) == 2);
    assert(arr.At(0, 2) == 3);
    
    // Should be able to insert more arrays now
    int data2[] = {4, 5};
    assert(arr.InsertArrays(data2, 2) == true);
    assert(arr.InsertArrays(data2, 2) == true);  // Should still work
    assert(arr.InsertArrays(data2, 2) == true);  // Should still work
    
    std::cout << "DoubleCrossLength test passed!" << std::endl;
}

void test_is_same() {
    std::cout << "Testing IsSame..." << std::endl;
    
    sjtu::CrossArray arr1(3);
    sjtu::CrossArray arr2(3);
    
    assert(arr1.IsSame(arr2) == false);
    
    sjtu::CrossArray arr3(arr1);
    assert(arr1.IsSame(arr3) == false);  // Different memory
    
    sjtu::CrossArray& ref = arr1;
    assert(arr1.IsSame(ref) == true);  // Same object
    
    std::cout << "IsSame test passed!" << std::endl;
}

int main() {
    try {
        test_basic_functionality();
        test_copy_constructor();
        test_append_arrays();
        test_which_greater();
        test_double_cross_length();
        test_is_same();
        
        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}



