#include "person.h"
#include <string>
using namespace std;

Person::Person(string theName){
    this->name = theName;
}

string Person::getName(){
    return this->name;
}