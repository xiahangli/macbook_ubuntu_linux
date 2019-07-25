#include <iostream>
#include <string>
#include "person.h"

using namespace std;
int main(int argc,char** args){
  Person *person = new Person("name");
  cout << "hello "<<person->getName()<<endl;
  delete person;
  return 0;

}