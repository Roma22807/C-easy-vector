#include <iostream>
#include <algorithm> 

template <typename T>
class MyVector {
private:
    T* data;         
    size_t size;    
    size_t capacity;  
public:
    MyVector() : data(nullptr), size(0), capacity(0) {}
    ~MyVector() {
        delete[] data;
    }
    void push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
}
    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity) return;
        T* new_data = new T[new_capacity];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("ERROR");
        }
        return data[index];
}
    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("...");
        return data[index];
    }
    size_t get_size() const {
        return size;
    }
};
int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    return 0;
}