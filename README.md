# Types
![Types](./assets/types.jpg)

# Operators

| Symbol | Meaning or Pronunciation     | “True” Comparison Examples |
|--------|---------------------------|----------------------------|
| <         | Less than                    | 1 < 5 / 8 < 9                |
| ==        | Equal to                     | 5 == 5 / 0 == 0              |
| >      | Greater than                 | 8 > 5 / 10 > 0               |
| <=        | Less than or equal to        | 4 <= 5 / 8 <= 8              |
| > =        | Greater than or equal to     | 9 >= 5 / 2 >= 2              |
| !=        | Not equal to                 | 1 != 0 / 4 != 3.99           |

There are also the && operator, which allows to do an AND.

Example: `if (x>1 && y>2)` --> Both conditions should be true to enter the if

The other operator is the ||, which allows to do an OR. 

Example: `if (x>1 || y>2)` --> Only one condition has to be true to enter the if

# Mathematical Operators

![Math](./assets/math.jpg)

# Loops

## For Loop
A for loop is a repetition control structure which allows us to write a loop that is executed a specific number of times. The loop enables us to perform 'N' number of steps together in one line.

```
int i=0; 
for (i = 1; i <= 10; i++)
{    
    // body of the loop
    // statements we want to execute
    printf( "Hello World %d\n", i);
}
```
**Output**:
```
Hello World 0
Hello World 1
Hello World 2
Hello World 3
Hello World 4
Hello World 5
Hello World 6
Hello World 7
Hello World 8
Hello World 9
```

## While Loop
While loops are used in situations where we do not know the exact number of iterations of loop beforehand. The loop execution is terminated on the basis of test condition.

```
int i=0; 
while (i < 6) 
{    
    // body of the loop
    // statements we want to execute
    printf( "Hello World %d\n", i);
}
```
**Output**:
```
Hello World 0
Hello World 1
Hello World 2
Hello World 3
Hello World 4
Hello World 5
```

# Arrays

![Arrays](./assets/c-cheatsheet-Arrays.jpg)

# Structs

![Structs](./assets/c-cheatsheet-Structs.jpg)
