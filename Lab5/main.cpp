//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
   double finalVal = 0.0;
   double mean = 0.0;

   for(int i = 0; i < arraySize; ++i) {            //will cause infinite loop when its unsigned 
      finalVal = finalVal + array[i];              //calculating sum of all the values in the file
   }

   mean = finalVal/arraySize;

   return mean;
}
//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {
   if(index < 0 || index >= arraySize) {
      cout << "Error with index" << endl;

      return;
   }

   for(int i = index; i < arraySize - 1; ++i) {             //shift values (left)
      array[i] = array[i + 1];
   }

   --arraySize;                                             //reducing arraySize by 1
}

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
   for(int i = 0; i < arraySize - 1; ++i) {
      cout << array[i] << ", ";
   }

   cout << array[arraySize - 1];             //print last val wo comma
}

//declared for the size of the array, to not exceed specified values
const int ARR_CAP = 100;                   

int main(int argc, char *argv[]) {
   // verify file name provided on command line
   if(argc != 2) {
      cout << "Error: Command line cannot exceed over 2." << endl;

      return 1;
   }

   // open file and verify it opened
   ifstream userFile(argv[1]);

   if(!userFile.is_open()) {
      cout << "Cannot open the file named " << argv[1] << endl;

      return 1;
   }

   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];              //declared array type double named array with value 1000
   int arraySize = 0;
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while(arraySize < ARR_CAP && userFile >> array[arraySize]) {
      ++arraySize;
   }
    
   userFile.close();

   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(array, arraySize) << endl << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int removeIndex;

   cout << "Enter index of value to be removed (0 to " << (arraySize - 1) << "): ";
   cin >> removeIndex;
   cout << endl << endl;

   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(array, arraySize);
   cout << endl << endl;

   
   // Call the remove function to remove the value at the index
   // provided by the user.

   remove(array, arraySize, removeIndex);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(array,arraySize);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(array, arraySize) << endl;
   
	return 0;
}