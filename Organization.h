#ifndef ASSIGNMENT4_ORGANIZATION_H
#define ASSIGNMENT4_ORGANIZATION_H

#include <iostream>
#include <string>
#include <utility>
#include <stdlib.h>
#include "Person.h"


class Organization{
    std::string orgName; // name of the org
//    int dim; // max size of the org
    Plist<Person*> members; // list of members
public:
    Organization();
    Organization(std::string name);
//    Organization(Organization& copy);
    std::string getMemberNames();
    void addPerson(Person *person);
    void removePerson(Person *person);
    inline std::string getOrgName(){return orgName;}
    virtual int paytuition() { std::cout << "no tuition for organization class "; return 0; }
//    virtual ~Organization();
};


#endif //ASSIGNMENT4_ORGANIZATION_H
