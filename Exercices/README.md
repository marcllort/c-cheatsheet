# Exercises

The program, must be a menu that allows me to choose between 3 exercises. 
If a wrong option is selected, show an error and allow the user to try again.

It should look something like this: 
```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
```

## Exercise 1
The user will insert a string (that can contain spaces) of his name and both surnames (separated by spaces). The program must return some information about this string:
    
1. The length of the string introduced. EASY
2. The introduced string reversed. COMPLEX
3. Modify the introduced string, by changing where the string ends. Instead of ending after the second surname, make it end after the first surname and print it. MOST DIFFICULT
4. The name, and surname 1 and 2 printed in different printfs (separate the string). They must be saved in a struct User, which will contain the fields: name, surname1 and surname2. NORMAL
5. Save this user in an array of 10 Users. NORMAL

**Example**:

```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
1
Insert name and surnames:
John Doe One

Original string: John Doe One
1. The length of the string is 12.
2. Reversed string: enO eoD nhoJ
3. Stripped string: John Doe
4. User 1: 
        Name: John
        Surnames: Doe One
```

## Exercise 2
In this exercise, you will need to receive the array of users from the previous exercise 1, and print all the users found in the array.

```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
2
There are 3 users in the array:
    User 1: 
        Name: John
        Surnames: Doe One
    User 2: 
        Name: Chop
        Surnames: Bolson Dog
    User 3: 
        Name: Willy
        Surnames: Papa Rex
```

## Exercise 3

In this exercise, you will need to receive the array of users from the previous exercise 1, and ask for a name of a user. 

If the user exists inside the array you will show his information. After having show the information, you will be asked if the user should be deleted.

```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
3
Name of the user to search:
Chop
User exists! Information:
    Name: Chop
    Surnames: Bolson Dog

Do you want to delete it? (Y/N)
Y
User deleted!
```

## Exercise 4

Add the age of the user to the structure, and update the previous exercises to ask for and show the age. 

### Exercise 1
```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
1
Insert name and surnames:
John Doe One
Insert age:
23

Original string: John Doe One
1. The length of the string is 12.
2. Reversed string: enO eoD nhoJ
3. Stripped string: John Doe
4. User 1: 
        Name: John
        Surnames: Doe One
        Age: 27
```

### Exercise 2
```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
2
There are 3 users in the array:
    User 1: 
        Name: John
        Surnames: Doe One
        Age: 23
    User 2: 
        Name: Chop
        Surnames: Bolson Dog
        Age: 2
    User 3: 
        Name: Willy
        Surnames: Papa Rex
        Age: 27
```

### Exercise 3
```
Select exercice to run:
    1. Exercise 1
    2. Exercise 2
    3. Exercise 3
3
Name of the user to search:
Chop
User exists! Information:
    Name: Chop
    Surnames: Bolson Dog
    Age: 2

Do you want to delete it? (Y/N)
Y
User deleted!
```