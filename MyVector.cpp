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
    MyVector(const MyVector& other)
        : data(other.capacity ? new T[other.capacity] : nullptr),
        size(other.size),
        capacity(other.capacity)
    {
        if (other.data) {
            std::copy(other.data, other.data + size, data);
        }
    }
    ~MyVector() {
        delete[] data;
    }
    void push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }
    void pop_back() {
        if (size > 0) size--;
    }
    void fitarr() {
        if (size == 0) {
            delete[] data;
            data = nullptr;
            size = 0;
            capacity = 0;
        }
        else if (size < capacity) {
            T* new_data = new T[size];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;
            capacity = size;
        }
    }
    T& front() {
        if (size > 0) {
            return data[0];
        }
    }
    T& back() {
        if (size > 0) {
            return data[size - 1];
        }
    }
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;

            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
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
    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
    bool empty() const {
        return size == 0;
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
    if (vec.empty()) {
        std::cout << "The vec is empty now\n";
    }
    MyVector<int> vec2 = vec;
    vec.clear();
    vec2.pop_back();
    for (size_t i = 0; i < vec2.get_size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    if (vec.empty()) {
        std::cout << "The vec is empty\n";
    }
    std::cout << vec2.front() << " " << vec2.back() << "\n";
    vec2 = vec;
    if (vec2.empty()) {
        std::cout << "The vec is empty\n";
    }
    return 0;
}