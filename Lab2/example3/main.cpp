#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   // Assign to inputFile value of 2nd command line argument
   string inputFile = argv[1];

   // Assign to outputFile value of 3rd command line argument
   string outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream userStream(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!userStream.is_open()) {
      cout << "Error opening the file" << endl;

      return 1;                                   //same thing as return 1 
   }
   // Read in integers from input file to vector.
   vector<int> integers;                         //declared vector list named integers
   string fileVals;                             //to store file values

   while(getline(userStream, fileVals)) {       //read lines from input stream to fileVals
      istringstream fileInput(fileVals);
      string value;                             //to store comma

      while(getline(fileInput, value, ',')) {   //extract values from 'fileInput' separated by commas into 'value'
      integers.push_back(stoi(value));          //stoi = turns a string into a integer
      }                                         //convert 'value' to an integer using stoi and add to 'integers' vector.
   }
   
   // Close input stream.
   userStream.close();

   // Get integer average of all values read in.
   int sum = 0;
   int average = 0;

   for (unsigned int i = 0; i < integers.size(); ++i) {
      sum = sum + integers[i];
   }

   average = sum / integers.size();

   for(unsigned int i = 0; i < integers.size(); ++i) {
      integers[i] = integers[i] - average;
   }

   // Convert each value within vector to be the difference between the original value and the average.
   ofstream showVals(outputFile);
   
   // Create output stream and open/create output csv file.

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!showVals.is_open()) {
      cout << "error opening" << endl;

      return 1;
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned int i = 0; i < integers.size(); ++i) {
      showVals << integers[i];

      if(i != integers.size() - 1) {
         showVals << ",";
      }
   }
   // Close output stream.
   showVals.close();

   return 0;
}