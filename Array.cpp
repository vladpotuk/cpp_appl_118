#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"


template <typename T>
Array<T>::Array() : head(nullptr), size(0), capacity(0), growthFactor(1) {}

template <typename T>
Array<T>::~Array() {
    RemoveAll();
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return size - 1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    if (size < capacity) {
        Node<T>* current = head;
        for (int i = 0; i < size; ++i) {
            current = current->next;
        }

        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }

        capacity = size;
    }
}

template <typename T>
void Array<T>::RemoveAll() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
T Array<T>::GetAt(int index) const {
    if (index < 0 || index >= size) {

    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {
    if (index < 0 || index >= size) {

    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->data = value;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size) {

    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= size) {

    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
void Array<T>::Add(const T& value) {
    if (size == capacity) {
        allocateMoreMemory(size + growthFactor);
    }

    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    size++;
}

template <typename T>
void Array<T>::Append(const Array<T>& otherArray) {
    for (int i = 0; i < otherArray.GetSize(); ++i) {
        Add(otherArray[i]);
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        RemoveAll();
        Append(other);
    }

    return *this;
}

template <typename T>
T* Array<T>::GetData() const {
    T* dataArray = new T[size];
    Node<T>* current = head;
    for (int i = 0; i < size; ++i) {
        dataArray[i] = current->data;
        current = current->next;
    }

    return dataArray;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > size) {

    }

    if (index == size) {
        Add(value);
    }
    else {
        if (size == capacity) {
            allocateMoreMemory(size + growthFactor);
        }

        Node<T>* newNode = new Node<T>(value);

        if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        size++;
    }
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index < 0 || index >= size) {

    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
    size--;
}

template <typename T>
void Array<T>::SetSize(int newSize, int grow) {
    if (newSize < 0 || grow <= 0) {

    }

    if (newSize > capacity) {
        allocateMoreMemory(newSize + grow);
    }
    else if (newSize < size) {
        Node<T>* current = head;
        for (int i = 0; i < newSize; ++i) {
            current = current->next;
        }

        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    size = newSize;
}

template <typename T>
void Array<T>::allocateMoreMemory(int newSize) {
    if (newSize <= capacity) {
        
        return;
    }

    capacity = newSize;

    Node<T>* current = head;
    Node<T>* newHead = nullptr;

    for (int i = 0; i < size; ++i) {
        Node<T>* newNode = new Node<T>(current->data);
        if (newHead == nullptr) {
            newHead = newNode;
        }
        else {
            Node<T>* temp = newHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        current = current->next;
    }

    
    current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }

    head = newHead;
}

#endif 
