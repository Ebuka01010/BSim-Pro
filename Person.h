//
// Created by Ebuka Onyeka on 2021-11-23.
//

#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <stdlib.h>
#include "Plist.h"
//#include "Organization.h"

// define your classes here

    class Organization;
    class Person{
        typedef Plist<Organization*> tt;
        std::string name;
        int age;
        tt organizations;
    public:
        Person();
        Person(std::string name);
        Person(std::string name, int age);
//        Person(Person& copy);
        int getAge();
        std::string getName();
        void addOrganization(Organization* organization);
        void removeOrganization(Organization *o);
        std::string getOrgNames();
        inline int getSize(){return this->organizations.getSize();};
        float getTotalTuition();
        std::string printSchools();
    };
