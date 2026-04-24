

#ifndef SRC_HPP
#define SRC_HPP

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
    
    // Implementation
    
    CrossArray::CrossArray(int lines) {
        capacity = lines;
        arrays = new int*[capacity];
        sizes = new int[capacity];
        total_elements = 0;
        
        // Initialize all arrays to nullptr and sizes to 0
        for (int i = 0; i < capacity; i++) {
            arrays[i] = nullptr;
            sizes[i] = 0;
        }
    }
    
    CrossArray::CrossArray(const CrossArray& o) {
        capacity = o.capacity;
        total_elements = o.total_elements;
        arrays = new int*[capacity];
        sizes = new int[capacity];
        
        for (int i = 0; i < capacity; i++) {
            if (o.arrays[i] != nullptr) {
                sizes[i] = o.sizes[i];
                arrays[i] = new int[sizes[i]];
                
                // Deep copy the elements
                for (int j = 0; j < sizes[i]; j++) {
                    arrays[i][j] = o.arrays[i][j];
                }
            } else {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }
    }
    
    CrossArray& CrossArray::WhichGreater(CrossArray& o) {
        if (total_elements >= o.total_elements) {
            return *this;
        } else {
            return o;
        }
    }
    
    bool CrossArray::IsSame(const CrossArray& o) {
        return (arrays == o.arrays);
    }
    
    bool CrossArray::InsertArrays(const int* Input, int size) {
        // Find the first available nullptr position
        int insert_pos = -1;
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] == nullptr) {
                insert_pos = i;
                break;
            }
        }
        
        // If no available position, return false
        if (insert_pos == -1) {
            return false;
        }
        
        // Create new array and copy elements
        arrays[insert_pos] = new int[size];
        sizes[insert_pos] = size;
        
        for (int i = 0; i < size; i++) {
            arrays[insert_pos][i] = Input[i];
        }
        
        total_elements += size;
        return true;
    }
    
    void CrossArray::AppendArrays(const int* Input, int Line, int size) {
        // Create new array with increased size
        int new_size = sizes[Line] + size;
        int* new_array = new int[new_size];
        
        // Copy existing elements
        for (int i = 0; i < sizes[Line]; i++) {
            new_array[i] = arrays[Line][i];
        }
        
        // Copy new elements
        for (int i = 0; i < size; i++) {
            new_array[sizes[Line] + i] = Input[i];
        }
        
        // Delete old array and update
        delete[] arrays[Line];
        arrays[Line] = new_array;
        sizes[Line] = new_size;
        total_elements += size;
    }
    
    void CrossArray::DoubleCrossLength() {
        int new_capacity = capacity * 2;
        int** new_arrays = new int*[new_capacity];
        int* new_sizes = new int[new_capacity];
        
        // Copy existing arrays
        for (int i = 0; i < capacity; i++) {
            new_arrays[i] = arrays[i];
            new_sizes[i] = sizes[i];
        }
        
        // Initialize new positions to nullptr
        for (int i = capacity; i < new_capacity; i++) {
            new_arrays[i] = nullptr;
            new_sizes[i] = 0;
        }
        
        // Delete old arrays and update
        delete[] arrays;
        delete[] sizes;
        arrays = new_arrays;
        sizes = new_sizes;
        capacity = new_capacity;
    }
    
    const int* CrossArray::AtArray(int i) {
        return arrays[i];
    }
    
    int& CrossArray::At(int i, int j) {
        return arrays[i][j];
    }
    
    CrossArray::~CrossArray() {
        // Delete all sub-arrays
        for (int i = 0; i < capacity; i++) {
            if (arrays[i] != nullptr) {
                delete[] arrays[i];
            }
        }
        
        // Delete the main arrays
        delete[] arrays;
        delete[] sizes;
    }
}

#endif

