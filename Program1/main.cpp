#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

//1. Get from the command line the name of the file that contains the wind tunnel data.
//2. Read wind-tunnel data into two parallel vectors, one vector stores the flight-path
//   angle and the other stores the corresponding coefficient of lift for that angle.
//   Both vectors should store doubles.
//3. Ask the user for a flight-path angle. If the angle is within the bounds of the data set,
//   the program should then use linear interpolation (see explanation of linear interpolation
//   below) to compute the corresponding coefficient of lift and output it.
//4. Finally, ask the user if they want to enter another flight-path angle.
//   Repeat steps 3 and 4 if they answer Yes, otherwise end the program if they answer No.

void readData(const string &userFileName, vector<double> &angle, vector<double> &coefficient) {
    double userAngle;
    double userCoefficient;
    ifstream userFile(userFileName);                           

    if(!userFile.is_open()) {
        cout << "Error opening " << userFileName << endl;

        exit(1);                             
    }
    
    while(userFile >> userAngle >> userCoefficient) {
        angle.push_back(userAngle);
        coefficient.push_back(userCoefficient);
    }

    userFile.close();
}

double interpolation(double userAngle, const vector<double> &angle, const vector<double> &coefficient) {
    if(userAngle < angle.front()) {
        return coefficient.front();
    }
    if(userAngle > angle.back()) {
        return coefficient.back();
    }

    size_t angleIndex = 0;

    for(size_t i = 1; i < angle.size(); ++i) {
        if(angle[i] >= userAngle) {
            angleIndex = i;

            break;
        }
    }

    if(angle[angleIndex] == userAngle) {
        return coefficient[angleIndex];
    }

    double lowerAngle = angle[angleIndex - 1];
    double upperAngle = angle[angleIndex];
    double lowerCoeff = coefficient[angleIndex - 1];
    double upperCoeff = coefficient[angleIndex];

    double interpolationVal;

    interpolationVal = lowerCoeff + ((userAngle - lowerAngle) / (upperAngle - lowerAngle)) * (upperCoeff - lowerCoeff);
    
    return interpolationVal;
}

bool isOrdered(const vector<double> &angle) {
    for(size_t i = 1; i < angle.size(); ++i) {
        if(angle[i] < angle[i - 1]) {
            return false;
        }
    }

    return true;
}

void reorder(vector<double> &angle, vector<double> &coefficient) {
    if(angle.empty() || coefficient.empty()) {
        return;
    }

    bool switched;

    do {
        switched = false;

        for (unsigned int i = 0; i < angle.size() - 1; ++i) {
            if (angle[i] > angle[i + 1]) {
                swap(angle[i], angle[i + 1]);
                swap(coefficient[i], coefficient[i + 1]);

                switched = true;
            }
        }
    } while(switched);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: You must put file name in command line." << endl;

        return 1;
    }

    string fileName = argv[1];                        

    vector<double> angle;
    vector<double> coefficient;

    readData(fileName, angle, coefficient);
    reorder(angle, coefficient);              

    string userAnswer;

    do {
        double newAngle;
        
        cout << "Enter angle: ";
        cin >> newAngle;

        if(newAngle >= angle.front() && newAngle <= angle.back()) {
            double newCoeff = interpolation(newAngle, angle, coefficient);

            cout << "Interpolation Value: " << newCoeff << endl;
        }

        cout << "Would you like to enter a new angle? Type Yes or No: ";
        cin >> userAnswer;
    } while(userAnswer == "Yes" || userAnswer == "yes");

    cout << "Done." << endl;

    return 0;
}