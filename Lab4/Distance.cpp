#include "Distance.h"
#include <iostream>
#include <cmath> 

using namespace std;

Distance::Distance() {                          //default constructor
    _feet = 0;
    _inches = 0.0;

    init();
}

Distance::Distance(unsigned ft, double in) {   //constructor 
    _feet = ft;
    _inches = in;

    init();
}

Distance::Distance(double in) {                 //constructor
    _feet = 0;
    _inches = in;

    init();
}

unsigned Distance::getFeet() const {            //get value for ft
    return _feet;       
}

double Distance::getInches() const {            //get value for inch
    return _inches;
}

double Distance::distanceInInches() const {     //return total distance in inches form
    return (_feet * 12) + _inches;
}

double Distance::distanceInFeet() const {       //return total distance in ft
    return _feet + (_inches / 12.0);
}

double Distance::distanceInMeters() const {    //return total distance in meters
    return (_feet * 12 + _inches) * 0.0254;
}

//Distance = returnType
Distance Distance::operator+(const Distance &rhs) const {       //adding two distance objects, save space
    return Distance(_feet + rhs._feet, _inches + rhs._inches);
}

Distance Distance::operator-(const Distance &rhs) const {                //subtract distance
    return Distance(distanceInInches() - rhs.distanceInInches());        //difference in inch and create new distance object
}

void Distance::init() {                     //extra inches to ft
    if(_inches < 0) {
        _inches = _inches * -1;
    }

    while(_inches >= 12) {
        _inches = _inches - 12;
        _feet = _feet + 1;
    }
}

ostream &operator<<(ostream &out, const Distance &rhs) {        //display
    out << rhs._feet << "' " << rhs._inches << "\"";

    return out;
}
