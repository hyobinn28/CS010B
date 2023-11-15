#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string& filename, char findVal);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string& filename, char findVal) {
   int freq = 0; 
   char character;
   ifstream userFile(filename);

   if(!userFile) {
      cout << "Error opening " << filename << endl;

      exit(EXIT_FAILURE);
   }

   while(userFile.get(character)) {       //read char from an input stream(file)
      if(character == findVal) {
         ++freq;                          //count how much times certain char 
      }
   }

   userFile.close();

   return freq;
}
