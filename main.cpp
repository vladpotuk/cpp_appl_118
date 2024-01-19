#include <iostream>
#include "Array.h"

int main() {
    Array<int> myArray;

    myArray.SetSize(5, 5);
    for (int i = 0; i < myArray.GetSize(); ++i) {
        myArray[i] = i * 2;
    }

    std::cout << "Array contents: ";
    for (int i = 0; i < myArray.GetSize(); ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
