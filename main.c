// STRUCTURE: First always do the includes necessaries for your program
// USE: Always add the #include X   The X, can be different, depending of the library you are importing
// If the library is one included in C (already coded) like "strings.h" you will use <> --> #include <strings.h>
// If the library has been coded by you, like "test.h" you will use "" --> #include "test.h"
#include <stdio.h>  // stdio.h --> Always present. It has the functions of printf, scanf... all the basics.

// STRUCTURE: Second you have to do the define of the macros/constants of your project. All those variables, that don't need
// to be changed during the execution of the program, in general, can be defined as a macro.
// USE: Always start with #define, then the name of the constant (MAX.../MIN...) and lastly the value. It can be a int,
// a char, a string... whatever you want. Remember to always write it on capital letters, and separated by underscore.
#define MAX_CHAR 100
#define PI 3.14
#define MY_NAME "John"
#define MY_SURNAME "Doe"

void printSeparator() {
    printf("\n--------------------------------------------------------------------------------------------\n");
}

// This is a procedure, as it does not have a return statement, and starts its declaration with void.
// Important to notice, that this procedure can be called in the main, because its declared before the main. ç
// If it was declared after it, it would not be detected and not compile.
void printString() {
    printf("INSIDE PROCEDURE printString()\n");

    // Here, a printf of a string is being used. To print a string/array of chars, we use %s
    // The place where the %s is positioned in the printf, is where it will be replaced by the value stored in MY_NAME
    printf("Hello, my name is %s\n", MY_NAME);
    // We use the \n to jump to the next line
    printf("If we don't use /n, look what happens ");
    printf("ALL THE TEXT IS IN THE SAME LINE!\n");
    printf("To fix it, lets always add it at the end of the printf\n");

    // There are other modificatiors like \n --> \t to do a tabulation for example
    printf("\t%s - %s", MY_NAME, MY_SURNAME);   // Notice that depending the order we set the variables, the name is
    printf("\t%s - %s", MY_SURNAME, MY_NAME);   // printed first or second.

    printSeparator();   // This procedure is called to print a separator line, between lines. Not necessary, just looks good.
}

void readString() {
    printf("INSIDE PROCEDURE readString()\n");

    char testChar;                          // To store a single character, we use the type char
    scanf("%c", &testChar);         // To read the char and store it, in the scanf/printf we use %c
    printf("The char is: %c", testChar);

    char name[MAX_CHAR];        // This is an array of chars, most commonly known as a string. They are the same.
    // In this case we have a string that can contain up to 200 characters.
    // These chars, are stored in the variable named name, but we could use whatever name we want.
    printf("Please, insert your name. (It will be saved in the variable name): \n");
    // There are multiple ways of reading a string, here I'll focus on the two main options.
    // The first and most simple, is to read a word with scanf. Once the user touches the "Enter" key, the word will be saved
    // to the "name" variable
    scanf("%s",
          name);      // When doing a scanf of a string, is not necessary to put the &, like we do in chars and numbers
    // But if we do it, it will work too.
    printf("Name correctly read.\nNow, the variable name contains the word: %s\n", name);
    printf("Please, insert your name and surname, separated by a space: \n");

    // When trying to read multiple words, separated by a space, we can't do it with scanf, as it gives some problems.
    // In this example you will see that only the first part (the name) has been saved in the variable.
    char nameAndSurname[MAX_CHAR];
    scanf("%s", nameAndSurname);
    printf("Name and surname correctly read.\nNow, the variable nameAndSurname contains the word: %s\n",
           nameAndSurname);

    // To fix this, and be able to save words with spaces between, we must use the fgets function.
    getchar();                                           // If we used a scanf before doing a fgets, like in this case, it can have problems
    // when reading, because it finds a newline that was inserted by the scanf
    // To fix this problem, is as simple as adding the function "getChar()" before the fgets

    fgets(nameAndSurname, MAX_CHAR,
          stdin);         // We must give fgets three things: the variable where we want to save the input
    // How much we want to read--> the size of the variable where you are storing
    // And lastly, we will always add "stdin", so it reads the keyboard
    printf("Name and surname correctly read.\nNow, the variable nameAndSurname contains the word: %s\n",
           nameAndSurname);

    printSeparator();   // This procedure is called to print a separator line, between lines. Not necessary, just looks good.
}

void printNumbers() {
    printf("INSIDE PROCEDURE printNumbers()\n");

    // There are many types of numbers in C. In this section will check out the main ones: int and float
    int numberInt = 2;                                  // int is a type of number that cannot contain decimals
    printf("int number: %d\n", 1);              // To print an int, we must use the %d. We can put a number (int) or
    printf("int variable: %d\n", numberInt);    // a int variable
    printf("int macro: %d\n", MAX_CHAR);        // or even an int macro/constant

    float numberFloat = 3.13;                                     // float is a type of number that can contain decimals
    printf("float number: %f\n",
           2.2);                  // To print a float, we must use the %f. We can put a number (float)
    printf("float variable: %f\n", numberFloat);        // a float variable
    printf("float macro: %f\n", PI);                    // or even a float macro/constant

    // The floats (and doubles) have an important thing to know, and is that they show all the decimals when doing a printf
    // To limit the number of decimals, just do %.2f--> to show 2 decimals, &.1f to show one decimal...
    printf("float number (only one decimal with .1f): %.1f\n",
           2.2);   // Same example as before, but limiting to one decimal

    printSeparator();
}

int readNumbers() {
    printf("INSIDE PROCEDURE readNumbers()\n");

    // To read numbers is as simple as printing them
    int testInt = 0;                            // It is a good practice to always initialize the variables to something
                                                // In the case of numbers such as ints, to 0
    printf("Insert a new int: \n");
    scanf("%d",&testInt);               // We use the %d to read and print int values
    printf("The int you inserted was: %d\n", testInt);

    float testFloat=0;
    printf("Insert a new float (ex: 3.2): \n");
    scanf("%f",&testFloat);               // We use the %f to read and print float values
    printf("The float you inserted was: %.2f\n", testFloat);        // Print with %.2f to only show 2 decimals

    printSeparator();
}

// If returns something different than "void" --> Function
// If returns "void" --> Procedure == Does not return nothing, so the function does not have the return clause at the end.
int main() {

    // Strings
    //printString();
    //readString();

    // Numbers
    printNumbers();
    readNumbers();

    return 0;
}
