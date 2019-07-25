#ifndef person_h
#define person_h
using namespace std;
#include <string>

class Person{
    private :
    string name;
    public :
    string getName();
    Person(string name); 
};

#endif