#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   int arrSize;
   
   cout << "Input array size: ";
   cin >> arrSize;
   cout << endl;

   cout << "Array values: ";
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minLoc = min(arr, arrSize);
      cout << "Min value is: ";
      cout << *minLoc << endl;
   }   

   return 0;
}
