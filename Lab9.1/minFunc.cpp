#include "minFunc.h"
#include <iostream>

using namespace std;

const int *min(const int arr[], int arraySize) {
    if(arraySize == 0) {
        return 0;
    }
    if(arraySize == 1) {
        return arr;
    }

    const int *leftMin = min(arr + 1, arraySize - 1);

    if(*leftMin < arr[0]) {
        return leftMin;
    }

    else {
        return &arr[0];
    }
}