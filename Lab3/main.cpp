#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here
Rational::Rational() {
   numerator = 0;                 //also can be written as numberator(0)
   denominator = 1;               //denominator(1)
}

Rational::Rational(int value) {
   numerator = value;
   denominator = 1;
}

Rational::Rational(int value, int denomValue) {
   numerator = value;
   denominator = denomValue;
}

Rational Rational::add(const Rational &rhs) const {         //add is const member function
   Rational output;

   output.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
   output.denominator = denominator * rhs.denominator;

   return output;
}

Rational Rational::subtract(const Rational &rhs) const {
   Rational output;

   output.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
   output.denominator = rhs.denominator * denominator;

   return output;
}

Rational Rational::multiply(const Rational &rhs) const {
   Rational output;

   output.numerator = numerator * rhs.numerator;
   output.denominator = denominator * rhs.denominator;

   return output;
}

Rational Rational::divide(const Rational &rhs) const {
   Rational output;

   output.numerator = numerator * rhs.denominator;
   output.denominator = rhs.numerator * denominator;

   return output;
}

int Rational::gcd(int value1, int value2) const {        //const->to not modify any member variables of the class
   while (value2 != 0) {            //value1 == GCD
      int temp = value2;
      value2 = value1 % value2;     //calc remainder
      value1 = temp;
   }

   return value1;
}

void Rational::simplify() {
   int commonNum;

   commonNum = gcd(numerator, denominator);

   numerator = numerator/commonNum;
   denominator = denominator/commonNum;
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

