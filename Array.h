#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    template <typename U>
    struct Node {
        U data;
        Node<U>* next;
        Node<U>* prev;
        Node(const U& val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node<T>* head;
    int size;
    int capacity;
    int growthFactor;

    void allocateMoreMemory(int newSize);

public:
    Array();
    ~Array();

    int GetSize() const;
    int GetUpperBound() const;
    bool IsEmpty() const;
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index) const;
    void SetAt(int index, const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;
    void Add(const T& value);
    void Append(const Array<T>& otherArray);
    Array<T>& operator=(const Array<T>& other);
    T* GetData() const;
    void InsertAt(int index, const T& value);
    void RemoveAt(int index);
    void SetSize(int size, int grow = 1);
};

#include "Array.cpp" 

#endif 
