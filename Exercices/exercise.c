//
// Created by mac12 on 22/01/2021.
//

#include "exercise.h"       // All the imports and structures are created in the .h file. This is considered to be the best practice.

// This is a function, as it returns an int
int printMenu() {
    // Usually all the computer programs need a menu to be navigated with. This is a basic implementation of a menu,
    // which will ask for a correct option. If the option inserted does not exist, it will ask to insert the option again

    int selectedOption = 0;                             // Declare the variable where the option is stored.

    printf("-- Welcome to the MENU --\n");      // Print the menu options
    printf("\t 1. Exercise 1\n");
    printf("\t 2. Exercise 2\n");
    printf("\t 3. Exercise 3\n");
    printf("\t 4. Exercise 4\n");
    printf("\t 5. Exit 4\n");
    printf("Select a exercise: \n");

    scanf("%d", &selectedOption);               // Save the option in selectedOption int variable

    while (0 >= selectedOption || selectedOption > 5) { // Check that the option is somewhere between 0 and 6 (1,2,3,4,5)
        printf("Wrong Option. Please, select a option number between 1 and 4.\n\n");

        printf("\t 1. Exercise 1\n");
        printf("\t 2. Exercise 2\n");
        printf("\t 3. Exercise 3\n");
        printf("\t 4. Exercise 4\n");
        printf("\t 5. Exit 4\n");
        printf("Select a exercise: \n");

        scanf("%d", &selectedOption);           // Store the new value to the variable
    }

    return selectedOption;                              // Return the variable, knowing that will be between 1 and 4
}

void printUser(struct User user) {
    printf("\tName: %s\n", user.name);
    printf("\tSurname 1: %s\n", user.surname1);
    printf("\tSurname 2: %s\n", user.surname2);
    printf("\tAge: %d\n", user.age);
}

char *reverseString(char input[MAX_CHAR], char reversedInput[MAX_CHAR]) {
    int stringLength = strlen(input);

    int i;
    for (i = 1; i <= stringLength; ++i) {
        reversedInput[i - 1] = input[stringLength - i];
    }
    reversedInput[i] = '\0';
}

struct Users exercise1(struct Users usersArray) {
    char input[MAX_CHAR];
    char *token;
    int ageUser = 0;

    printf("Insert name and surnames:\n");
    getchar();
    fgets(input, MAX_CHAR, stdin);
    input[strlen(input) - 1] = '\0';                // Delete the \n from the last position

    printf("Insert age of the user:\n");
    scanf("%d", &ageUser);

    printf("Original String: %s\n", input);

    // 1st: Length
    printf("The length of the string is %d\n", strlen(input));

    // 2nd: Reverse the input string
    char reversedInput[MAX_CHAR];
    reverseString(input, reversedInput);
    printf("Reversed string: %s\n", reversedInput);

    // 3rd: Cut the input string after the first surname
    char inputCopy[MAX_CHAR];           // Will work with a copy, as we later will need the original string to save in the structure
    strcpy(inputCopy, input);

    int spaceCount = 0;
    for (int i = 0; i < strlen(inputCopy); ++i) {
        if (inputCopy[i] == ' ') {
            if (spaceCount == 1) {
                inputCopy[i] = '\0';
            }
            spaceCount++;
        }
    }
    printf("Stripped string: %s\n", inputCopy);

    // 4rd: Save in structure, and print User
    token = strtok(input, " ");
    strcpy(usersArray.users[usersArray.numberUsers].name, token);       // We copy from the token to the user.name

    token = strtok(NULL, " ");
    strcpy(usersArray.users[usersArray.numberUsers].surname1, token);

    token = strtok(NULL, " ");
    strcpy(usersArray.users[usersArray.numberUsers].surname2, token);

    usersArray.users[usersArray.numberUsers].age = ageUser;

    printUser(usersArray.users[usersArray.numberUsers]);

    // 5th: Already done, as we added the info inside the User of the user array
    usersArray.numberUsers++;           // We only need to update the number of users that are stored inside of the array

    return usersArray;                  // Return the modified array, with the new user and updated numberUsers value
}

void exercise2(struct Users usersArray) {
    printf("There are %d users in the array:\n", usersArray.numberUsers);
    for (int i = 0; i < usersArray.numberUsers; ++i) {
        printf("\nUser %d\n", i + 1);
        printUser(usersArray.users[i]);
    }
}

struct Users deleteUser(struct Users usersArray, int positionUser) {

    for (int j = positionUser; j < usersArray.numberUsers; ++j) {
        usersArray.users[j] = usersArray.users[j + 1];                  // We are shifting the users that are behind the one to be deleted
        // Example: If there was a user after the one deleted (pos 0), now instead of being in position 1, now it will be in position 0
    }

    usersArray.users[usersArray.numberUsers].name[0] = '\0';            // The last position, is cleaned, putting the firt char as \0, so in case we do a print it will be empty text
    usersArray.users[usersArray.numberUsers].surname1[0] = '\0';
    usersArray.users[usersArray.numberUsers].surname2[0] = '\0';
    usersArray.users[usersArray.numberUsers].age = 0;

    usersArray.numberUsers--;                                           // Reduce the amount of total users in the array

    return usersArray;
}

struct Users exercise3(struct Users usersArray) {
    char name[MAX_CHAR];
    char option;
    printf("Name of the user to search:\n");
    scanf("%s", name);                                          // In this case, as the name can't have spaces, we can use a scanf

    for (int i = 0; i < usersArray.numberUsers; ++i) {
        if (strcmp(usersArray.users[i].name, name) == 0) {              // We use strcmp(strings.h), to compare if the names are the same. When they are the same, it returns a 0
            printf("User exists! Information:\n");
            printUser(usersArray.users[i]);
            printf("Do you want to delete this user? (Y/N)\n");
            scanf(" %c", &option);                      // When doing a scanf of a char, always put a space before, if not it won't be read

            if (option == 'Y' || option == 'y') {
                printf("User with name %s deleted!", usersArray.users[i].name);
                usersArray = deleteUser(usersArray, i);
                return usersArray;          // Return the updated array, with the deleted user and reduced number of users
            }
        }
    }

    return usersArray;          // Return the updated array, with the deleted user and reduced number of users
}


void exercise4() {
    printf("Nothing to show!\n");
}

// If returns something different than "void" --> Function
// If returns "void" --> Procedure == Does not return nothing, so the function does not have the return clause at the end.
int main() {
    int selectedOption = printMenu();           // Save the option in the variable

    struct Users usersArray;
    usersArray.numberUsers = 0;

    // The switch works like and if/else. It will check if selectedOption == 1, == 2... the number is set in the "case".
    // A switch can also be used with chars or strings, does not always have to be with integers.
    while (selectedOption != 5) {
        switch (selectedOption) {
            case 1:
                usersArray = exercise1(usersArray);
                break;
            case 2:
                exercise2(usersArray);
                break;
            case 3:
                usersArray = exercise3(usersArray);
                break;
            case 4:
                exercise4();
                break;
            default:                // This is a special case. Its like the else. If there is no case that matches the value of selectedOption
                // for example a 5, it will go to the default. In this case it will never be used, as in the printMenu() function
                // we are always making sure that the value will be 1,2,3 or 4
                break;
        }
        selectedOption = printMenu();           // Save the option in the variable
    }

    return 0;
}