//
// Created by mac12 on 22/01/2021.
//

#ifndef CHEATSHEETC_EXERCISE_H
#define CHEATSHEETC_EXERCISE_H

#include <stdio.h>
#include <strings.h>
#include <math.h>

#define MAX_CHAR 100
#define MAX_USERS 10

struct User{
    char name[MAX_CHAR];
    char surname1[MAX_CHAR];
    char surname2[MAX_CHAR];
    int age;
};

struct Users{
    int numberUsers;
    struct User users[MAX_USERS];
};


#endif //CHEATSHEETC_EXERCISE_H
