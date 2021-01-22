// STRUCTURE: First always do the includes necessaries for your program
// USE: Always add the #include X   The X, can be different, depending of the library you are importing
// If the library is one included in C (already coded) like "strings.h" you will use <> --> #include <strings.h>
// If the library has been coded by you, like "test.h" you will use "" --> #include "test.h"
#include <stdio.h>  // stdio.h --> Always present. It has the functions of printf, scanf... all the basics.
#include <strings.h> // strings.h --> Must be used when we need functions like strlen, strok... In general string related functions
#include <math.h>   // math.h --> Used for advanced operations, like rounding numbers, sqrt (raiz cuadrada)

// STRUCTURE: Second you have to do the define of the macros/constants of your project. All those variables, that don't need
// to be changed during the execution of the program, in general, can be defined as a macro.
// USE: Always start with #define, then the name of the constant (MAX.../MIN...) and lastly the value. It can be a int,
// a char, a string... whatever you want. Remember to always write it on capital letters, and separated by underscore.
#define MAX_CHAR 100
#define MAX_PASSENGERS 5
#define PI 3.14
#define MY_NAME "John"
#define MY_SURNAME "Doe"

// STRUCTURE: Third is the global variables. This variables are available to use in all this file. It is not a good practice to use
// them, as different functions can modify it, it can end up generating errors. It is better to use local variables, which
// are the ones created inside procedures and functions, and then return them (like when a function returns an int).
int globalVariableInt = 2;

// STRUCTURE: The last thing before starting to declare functions, is to define your structs. The struct is like creating your own int,
// creating your own type. This type will be composed of other variables.

// This struct is used later in the Car struct, but to be used it must be declared before the car struct.
// It contains information about the passenger: passengerName (a string, of maximum 100 chars) and the passengerAge (an int)
struct CarPassenger {
    char passengerName[MAX_CHAR];
    int passengerAge;
};

// This struct represents a Car, that contains the amount of passengers currently in the car (int numberPassengers)
// and an array of struct CarPassenger. This is an array of 5 positions, which means that the car can only have 5 passengers.
// Is an array of struct CarPassenger, which has been declared earlier.
struct Car {
    int numberPassengers;
    float gasLeft;
    struct CarPassenger passengers[MAX_PASSENGERS];
};

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

    printSeparator();                                   // This procedure is called to print a separator line, between lines. Not necessary, just looks good.
}

void readString() {
    printf("INSIDE PROCEDURE readString()\n");

    char testChar;                                          // To store a single character, we use the type char
    scanf("%c", &testChar);                         // To read the char and store it, in the scanf/printf we use %c
    printf("The char is: %c", testChar);

    char name[MAX_CHAR];        // This is an array of chars, most commonly known as a string. They are the same.
    // In this case we have a string that can contain up to 200 characters.
    // These chars, are stored in the variable named name, but we could use whatever name we want.
    printf("Please, insert your name. (It will be saved in the variable name): \n");

    // There are multiple ways of reading a string, here I'll focus on the two main options.
    // The first and most simple, is to read a word with scanf. Once the user touches the "Enter" key, the word will be saved to the "name" variable
    scanf("%s", name);      // When doing a scanf of a string, is not necessary to put the &, like we do in chars and numbers

    // But if we do it, it will work too.
    printf("Name correctly read.\nNow, the variable name contains the word: %s\n", name);
    printf("Please, insert your name and surname, separated by a space: \n");

    // When trying to read multiple words, separated by a space, we can't do it with scanf, as it gives some problems.
    // In this example you will see that only the first part (the name) has been saved in the variable.
    char nameAndSurname[MAX_CHAR];
    scanf("%s", nameAndSurname);
    printf("Name and surname correctly read.\nNow, the variable nameAndSurname contains the word: %s\n", nameAndSurname);

    // To fix this, and be able to save words with spaces between, we must use the fgets function.
    getchar();                                           // If we used a scanf before doing a fgets, like in this case, it can have problems
    // when reading, because it finds a newline that was inserted by the scanf
    // To fix this problem, is as simple as adding the function "getChar()" before the fgets

    fgets(nameAndSurname, MAX_CHAR, stdin);         // We must give fgets three things: the variable where we want to save the input

    // How much we want to read--> the size of the variable where you are storing
    // And lastly, we will always add "stdin", so it reads the keyboard
    printf("Name and surname correctly read.\nNow, the variable nameAndSurname contains the word: %s\n", nameAndSurname);

    printSeparator();   // This procedure is called to print a separator line, between lines. Not necessary, just looks good.
}

// This is a procedure, as it is returning a void. But in this case we are receiving a parameter, a string.
void strlenOperations(char *testVariable) {
    printf("INSIDE PROCEDURE strlenOperations()\n");

    printf("String Parameter received: %s\n", testVariable);         // Print the string received, to check that its been received properly

    int stringLength = strlen(testVariable);                                // We use the strlen, to detect what is the lenght of the string received.
    printf("The string: %s, has a length of %d\n", testVariable, stringLength);

    printSeparator();

    char testChars[MAX_CHAR] = "second test";
    printf("The original string testChars is: %s\n", testChars);

    testChars[4] = 'F';                                                     // Try modifying only the 5th (as arrays start by 0) position of the array, and put a F in there
    printf("The modified string testChars is: %s\n", testChars);
    printf("The modified string: %s, has a length of %d\n", testChars, strlen(testChars));   // Instead of saving the strlen value in a variable
    // It can also be directly put as a parameter in the printf, as it returns an int

    testChars[6] = '\0';              // Now we will cut the string. This will make that printf will only print till position 6, and strlen

    // will count letters till the 6th position too.
    printf("The reduced string: %s, has a length of %d\n", testChars, strlen(testChars));

    printSeparator();
}

void strtokOperations() {
    char str[MAX_CHAR] = "This is - cCheatsheet - tutorial";            // This is the initial string that we will want to separate
    char delimiter[2] = "-";                                            // The string has a two -, and this will be the delimiter that we will use to cut

    char *token;                                                        // This is the variable where the separated strings will be stored.

    token = strtok(str,delimiter);                                      // The first time the strtok is run, the first part of the string till the delimiter - will be returned
    // In this first case, we would get the "This is "

    // For this example, we will do a while, that will print the token till there are no more tokens (string parts) to show
    while (token != NULL) {
        printf(" %s\n", token);

        token = strtok(NULL, delimiter);  // We get the next token (first "cCheatsheet", and in the second loop " tutorial)
        // IMPORTANT: We only put the string the first time. After, to get the next value, instead of the string we put NULL
    }
}

void printNumbers() {
    printf("INSIDE PROCEDURE printNumbers()\n");

    // There are many types of numbers in C. In this section will check out the main ones: int and float
    int numberInt = 2;                                              // int is a type of number that cannot contain decimals
    printf("int number: %d\n", 1);                          // To print an int, we must use the %d. We can put a number (int) or
    printf("int variable: %d\n", numberInt);                // a int variable
    printf("int macro: %d\n", MAX_CHAR);                    // or even an int macro/constant

    float numberFloat = 3.13;                                       // float is a type of number that can contain decimals
    printf("float number: %f\n", 2.2);                       // To print a float, we must use the %f. We can put a number (float)
    printf("float variable: %f\n", numberFloat);            // a float variable
    printf("float macro: %f\n", PI);                        // or even a float macro/constant

    // The floats (and doubles) have an important thing to know, and is that they show all the decimals when doing a printf
    // To limit the number of decimals, just do %.2f--> to show 2 decimals, &.1f to show one decimal...
    printf("float number (only one decimal with .1f): %.1f\n", 2.2);         // Same example as before, but limiting to one decimal

    printSeparator();
}

// This is a function, as it starts with an int. This allows us to return an int value to the function from where readNumbers() is called.
// To do so, at the end of the function we must do "return X" where X is the value or variable that we want to return
int readNumbers() {
    printf("INSIDE PROCEDURE readNumbers()\n");

    // To read numbers is as simple as printing them
    int testInt = 0;                            // It is a good practice to always initialize the variables to something
    // In the case of numbers such as ints, to 0
    printf("Insert a new int: \n");
    scanf("%d", &testInt);               // We use the %d to read and print int values
    printf("The int you inserted was: %d\n", testInt);

    float testFloat = 0;
    printf("Insert a new float (ex: 3.2): \n");
    scanf("%f", &testFloat);               // We use the %f to read and print float values
    printf("The float you inserted was: %.2f\n", testFloat);        // Print with %.2f to only show 2 decimals

    printSeparator();

    return testInt;     // Return the int we read in the first scanf, to the place this functions is being called from.
    // Once a return is done, the function ends. If a printf is after the return, as after the return the
    // function ends, the printf will never be called.

    printf("This will never be printed, because of the previous return!");
}

// This is a function, as it returns an int
int printMenu() {
    // Usually all the computer programs need a menu to be navigated with. This is a basic implementation of a menu,
    // which will ask for a correct option. If the option inserted does not exist, it will ask to insert the option again
    printf("INSIDE PROCEDURE printMenu()\n");

    int selectedOption = 0;                             // Declare the variable where the option is stored.

    printf("-- Welcome to the MENU --\n");      // Print the menu options
    printf("\t 1. Strings\n");
    printf("\t 2. Numbers\n");
    printf("\t 3. Arrays\n");
    printf("\t 4. Structs\n");
    printf("Select a tutorial: \n");

    scanf("%d", &selectedOption);               // Save the option in selectedOption int variable

    while (0 >= selectedOption || selectedOption > 4) { // Check that the option is somewhere between 0 and 5 (1,2,3,4)
        printf("Wrong Option. Please, select a option number between 1 and 4.\n\n");

        printf("\t 1. Strings\n");
        printf("\t 2. Numbers\n");
        printf("\t 3. Arrays\n");
        printf("\t 4. Structs\n");
        printf("Select a tutorial: \n");

        scanf("%d", &selectedOption);           // Store the new value to the variable
    }

    return selectedOption;                              // Return the variable, knowing that will be between 1 and 4
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {       // We look for the smallest number in the rest of the array
            if (arr[j] < arr[min_idx]) {
                min_idx = j;                // If the number in the J position is smaller than the current smallest number
                // we update the min_idx var, to save the position of the smallest number
            }
        }

        // Swap the found minimum element
        // with the first element
        int temp = arr[i];                  // We use a temporal variable, to store the original value of position i
        arr[i] = arr[min_idx];              // If we don't do the previous step, as we are now overriding the position i
        arr[min_idx] = temp;                // the old value that was in i (now stored in temp) would be lost
    }
}

// Procedure to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // Print position i of the array
    }
    printf("\n");
}

void sortIntArray() {
    printf("INSIDE PROCEDURE sortIntArray()\n");

    int arr[] = {0, 23, 14, 12, 9};                     // Original array to order

    int n = sizeof(arr) / sizeof(arr[0]);               // To know the length of the array, instead of manually counting we can do this division
    // We divide the sizeof the array, by the size of one position of the array, to get how many positions are inside
    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);                              // The array and its length is given to the sort array procedure. An array is passed by reference
    // which means that once inside the selectionSort procedure is reordered, it does not need to be returned and saved in
    // a new array variable, the original "arr" variable will already have the changes in it.

    printf("\nSorted array in Ascending order: \n");
    printArray(arr, n);

    printSeparator();
}

// Function that receives a string and returns an float
float myAtof(char *string) {
    float total = 0, num;
    int df = 10, i = 0;
    int decimal = 0;
    while (string[i]) {
        num = string[i] - '0';
        if (decimal) {
            num = num / df;
            df = df * 10;
        } else if ((string[i] >= '0' && string[i] <= '9')) {
            total = total * 10;
        }
        if (string[i] == '.') {
            decimal = 1;
        } else {
            total += num;
        }

        i++;
    }
    return total;
}

// Function that receives a string and returns an int
int myAtoi(char *string) {
    int res = 0;            // Initialize result variable

    // Iterate through all characters of input string and update result take ASCII
    // character of corresponding digit and subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle digits left to update running total
    for (int i = 0; string[i] != '\0' && string[i] != '\n'; ++i) {
        res = res * 10 + string[i] - '0';
    }

    return res;             // return result.
}

void printCar(struct Car car) {
    printf("This car has %d passengers and %.2f gas left.\n", car.numberPassengers, car.gasLeft);
    for (int i = 0; i < car.numberPassengers; ++i) {
        printf("Passenger %d:\n\tName: %s\n\tAge: %d\n", i + 1, car.passengers[i].passengerName, car.passengers[i].passengerAge);
    }
}

void structExample() {
    printf("INSIDE PROCEDURE structExample()\n");

    printf("Please, insert a string like gasLeft#numberPassengers#passenger1Name#passenger1Age#passenger2Name#passenger2Age#... \n");
    printf("Example: 20.5#4#John Doe#44#Yerar Dogg#10#Willy Papa#27#Chop Bolson#5 \n");


    char input[MAX_CHAR];                                       // Variable where the input string will be saved
    getchar();                                                  // Consume the previous \n, always must be done before a fgets
    fgets(input, MAX_CHAR, stdin);                         // fgets, just in case a name has a space

    printf("String input: %s\n", input);                // Print the string to make sure that its been correctly saved

    char delimiter[2] = "#";                                    // This will be the delimiter that we will use to cut
    char *token;                                                // This is the variable where the separated strings will be stored.


    printSeparator();

    // From this point, now we will want to save the information introduced in the string to the struct Car type
    // Its important to realize what the order of the string is and where it has to be stored.

    // The first info given, is the amount of passengers the car will have, that must be saved in Car->numberPassengers
    struct Car car;

    token = strtok(input, delimiter);                           // In the token we now have the gas left, but as a string
    car.gasLeft = myAtof(token);                                // To save it we need the number as an float, so we use the myAtof function to transform it

    token = strtok(NULL, delimiter);                        // In the token we now have the number of passengers, but as a string
    car.numberPassengers = myAtoi(token);                       // To save it we need the number as an int, so we use the myAtoi function to transform it

    // Now that we know how many passengers will be introduced, we can do a for loop to save as many information as passengers will be

    for (int i = 0; i < car.numberPassengers; i++) {
        token = strtok(NULL, delimiter);                    // We get the next token --> passengerName
        strcpy(car.passengers[i].passengerName, token);
        token = strtok(NULL, delimiter);                    // We get the next token --> passengerAge
        car.passengers[i].passengerAge = myAtoi(token);         // As we need a int, we transform the string to int
    }

    printCar(car);                                              // Once all the information is saved, we print the car variable, to check its been correctly saved

    printSeparator();
}

// If returns something different than "void" --> Function
// If returns "void" --> Procedure == Does not return nothing, so the function does not have the return clause at the end.
int main() {

    int selectedOption = printMenu();           // Save the option in the variable

    // The switch works like and if/else. It will check if selectedOption == 1, == 2... the number is set in the "case".
    // A switch can also be used with chars or strings, does not always have to be with integers.
    switch (selectedOption) {
        case 1:
            // Strings
            printString();
            readString();
            strlenOperations("test string");
            strtokOperations();
            break;
        case 2:
            // Numbers
            printNumbers();
            int value = readNumbers();      // This is a function that returns an int. If we want to save it we can store its value in a variable.
            printf("The function readNumbers() has returned the value: %d", value);
            break;
        case 3:
            // Arrays
            sortIntArray();
            break;
        case 4:
            // Structs
            structExample();
            break;
        default:                // This is a special case. Its like the else. If there is no case that matches the value of selectedOption
            // for example a 5, it will go to the default. In this case it will never be used, as in the printMenu() function
            // we are always making sure that the value will be 1,2,3 or 4
            break;
    }

    return 0;
}
