//
// Created by Ebuka Onyeka on 2021-11-23.
//

#ifndef ASSIGNMENT4_UNIVERSITY_H
#define ASSIGNMENT4_UNIVERSITY_H

#include <iostream>
#include <string>
#include <utility>
#include <stdlib.h>
#include "Person.h"

class University : public Organization{
    float tuition;
public:
    using Organization::Organization;
    float getTuition();
    void setTuition(float tuition);
    virtual int paytuition() override { return getTuition(); }
};


#endif //ASSIGNMENT4_UNIVERSITY_H
