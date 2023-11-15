#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(const string& filename) {
   int sum = 0;
   int input;
   ifstream userFile(filename);     //input file stream = ifstream (used for input file stream operations)

   if(!userFile) {
      cout << "Error opening " << filename << endl;

      exit(EXIT_FAILURE);           
   }

   while(userFile >> input) {      //read data from userFile into input; 
      sum = sum + input;
   }

   userFile.close();

   return sum;
}

int main() {
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here