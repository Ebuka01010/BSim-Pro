//
// Created by Ebuka Onyeka on 2021-11-23.
//

#include <iomanip>
#include <string>
#include <utility>
#include <stdlib.h>
#include "Person.h"
#include "Organization.h"
#include "university.h"
#include "Plist.h"

using namespace std;





//  class definitions here
//************************
//  Person : line 28
//  University : line 113
//  Organization : line 154
//  Plist : line 221

//****************************************
//      Person Class Definitions
//****************************************

Person::Person():organizations(5){
    this->name="Instance";
    this->age=0;
//    this->organizations = Plist<Organization*>(5);
}
Person::Person(std::string name, int age):organizations(5) {
    this->name=name;
    this->age=age;
//    this->organizations = Plist<Organization*>(5);
}
Person::Person(std::string name):organizations(5) {
    this->name=name;
    this->age=0;
}

int Person::getAge() {
    return age;
};
string Person::getName(){
    return this->name;
};

void Person::addOrganization(Organization *organization) {
    try{
        organizations.add(organization);
    }catch (std::out_of_range &e){
        cout<<"Cannot add "<< getName() << " to " << organization->getOrgName() << " he is enrolled in 5 organizations already" << endl;
    }
}

void Person::removeOrganization(Organization *o) {
    try{
        organizations.remove(o);
    }catch (std::domain_error &e){
        cout<<"Error Person::removeOrganization: Cannot withdraw "<< this->getName() << " from " << o->getOrgName()<< ". He is not a member of the organization"<<endl;
    }

}

string Person::getOrgNames() {
    if(this->organizations.getSize()==0){
        return "Not a member of any Organizations";
    }
    else{
        string names="";
        for(int i =0 ; i <organizations.getSize();i++){
            if(i == (organizations.getSize() - 1))
                names+=this->organizations.getItem(i)->getOrgName();
            else{
                names+=this->organizations.getItem(i)->getOrgName() + ",";
            }
        }
        return names;
    }
};




//************************************************************************************************************************
//                                         University Class Definitions
//************************************************************************************************************************



void University::setTuition(float tuition){
    this->tuition = tuition;
}

float University::getTuition(){
    return this->tuition;
}

float Person::getTotalTuition(){
    float sum = 0;
    for (int i = 0 ; i<organizations.getSize();i++){
//        auto ptr = organizations->getItem(i);
        if(dynamic_cast<University*>(organizations.getItem(i))){
            University* h = dynamic_cast<University*>(organizations.getItem(i));
            sum += h->paytuition();
        }
    }
    return sum;
}

std::string Person::printSchools() {
    std::string names = "";
    for (int i = 0 ; i<organizations.getSize();i++){
//        auto ptr = organizations->getItem(i);
        if(dynamic_cast<University*>(organizations.getItem(i))){
            University* h = dynamic_cast<University*>(organizations.getItem(i));
            int val = (int) (h->getTuition());
            names += h->getOrgName() +": "+ to_string(val) + "; ";
        }
    }
    return names;
}


//************************************************************************************************************************
//                                      Organization Class Definitions
//************************************************************************************************************************


Organization::Organization():members(10){
//    dim = 100;
//    this->members = new Plist<Person>(dim);
    this->orgName = "";
}
Organization::Organization(string name):members(10){
//    dim = 100;
//    this->members = new Plist<Person>(dim);
    this->orgName = name;
}

std::string Organization::getMemberNames(){
    if(this->members.getSize()==0){
        return "No members in organization";
    }
    else{
        string names="{";
        for(int i =0;i <members.getSize();i++){
            if(i == (members.getSize() - 1))
                names+=this->members.getItem(i)->getName() + "}";
            else{
                names+=this->members.getItem(i)->getName() + ";";
            }
        }
        return names;
    }
}
void Organization::addPerson(Person *person) {
    try{
        members.add(person);
    }catch (std::out_of_range &e){
          cout<< "Cannot add Person";
    }

}

void Organization::removePerson(Person *person) {
    try{
        members.remove(person);
    }catch (std::domain_error &e){
          cout<<"Error Person::removePerson: Cannot withdraw "<< person->getName() << " from " << this->getOrgName()<< ". "<< this->getOrgName() <<" does not a member named "<< person->getName()<<"\n";
    }
}




//************************************************************************************************************************
//                                          Template Plist Class Definitions
//************************************************************************************************************************



template <typename T>
T Plist<T>::get(){
    if(size>0){
        return *(myarray+current+1);
    }
    else{
        throw std::domain_error("No value in array");
    }
}

//template <typename T>
//void Plist<T>::start() {
//    current = -1;
//}

//template <typename T>
//void Plist<T>::next() {
//    if(!isLast()){
//        current += 1;
//    }
//}

template <typename T>
bool Plist<T>::isLast() {
    if(current == (size-1)){
        return true;
    }
    else if(current>size-1){
        throw std::out_of_range("Current has exceeded limit");
    }
    else{
        return false;
    }
}

template <typename T>
int Plist<T>::getCurrent() {
    return current;
}

//template<typename T>
//void Plist<T>::add(T item) {
//    if(myarray == NULL)myarray = new T[capacity];
//    if(isFull()){
//        throw std::out_of_range("No Space");
//    }
//    else{
//        myarray[size] = item;
//        size= size;
//    }
//}

//template<typename T>
//bool Plist<T>::remove(T item) {
//    start();
//    if(size > 0){
//        next();
//        int location = -1;
//        do{
//            if(get() == item){
//                location = current;
//            }
//            else{
//                next();
//            }
//        }while(!isLast());
//        if(location>-1){
//            if(size-1 != location){
//                myarray[location] = myarray[size - 1];
//            }
//            T *tmp = new T[capacity];
//
//            start();
//            do{
//                tmp[current+1] = myarray[current+1];
//                next();
//            }while(current+1!=size);
//
//
//            delete[] myarray;
//
//            myarray = tmp;
//            size--;
//            return true;
//        }
//        else{
//            throw std::domain_error("Does not exist");
//        }
//    }
//    else{
//        throw std::domain_error("Array not initialized");
//    }
//}

template <typename T>
T Plist<T>::getItem(int i) {
    if((i<size) && (i>-1)){
        return myarray[i];
    }
}

template <typename T>
bool Plist<T>::isFull(){
    if(getSize() == getCapacity()){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
int Plist<T>::getSize() {
    return size;
}

template <typename T>
int Plist<T>::getCapacity() {
    return capacity;
}

//template <typename T>
//Plist<T>::Plist(int cap) : size(0), current(-1), capacity(cap), myarray(new T[capacity]){}