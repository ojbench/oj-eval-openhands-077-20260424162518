
#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;        // Pointer to array of int pointers
        int* sizes;          // Array to store size of each sub-array
        int capacity;        // Maximum number of arrays
        int total_elements;  // Total number of elements across all arrays
        
    public:
        explicit CrossArray(int lines);
        
        CrossArray(const CrossArray& o);
        
        CrossArray& WhichGreater(CrossArray& o);
        
        bool IsSame(const CrossArray& o);
        
        bool InsertArrays(const int* Input, int size);
        
        void AppendArrays(const int* Input, int Line, int size);
        
        void DoubleCrossLength();
        
        const int* AtArray(int i);
        
        int& At(int i, int j);
        
        ~CrossArray();
    };
}

#endif
