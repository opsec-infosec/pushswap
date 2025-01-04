![](push_swap.gif)
# PushSwap

Sorting algorithm written in C using 2 stacks. Sort numbers using the 2 stacks and return the sorted numbers in the first stack.


## Rules
* You have 2 stacks named A and B.
* 500 random numbers, there should be no more than 5500 operations on average.

### At The Start:
* The stack A contains a random amount of negative and/or positive numbers
which cannot be duplicated.
* The stack B is empty.
* The goal is to sort in ascending order numbers into stack A with the minimum amount of operations.

### Using The Following Operations:
* sa (swap a): Swap the first 2 elements at the top of stack A.
Do nothing if there is only one or no elements.
* sb (swap b): Swap the first 2 elements at the top of stack B.
Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of stack B and put it at the top of stack A.
Do nothing if stack B is empty.
* pb (push b): Take the first element at the top of stack A and put it at the top of stack B.
Do nothing if a is empty.
* ra (rotate a): Shift up all elements of stack A by 1.
The first element becomes the last one.
* rb (rotate b): Shift up all elements of stack B by 1.
The first element becomes the last one.
* rr : ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack A by 1.
The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack B by 1.
The last element becomes the first one.
* rrr : rra and rrb at the same time.

## Sorting Alogrithm

1. Group the numbers from smallest to largest into stack B, providing a rough initial sorting
2. Split stack B in half. If a specified number is above the split, use rr/ra/rb else use rrr/rra/rrb
3. Determin the number of operations to move any number from stack B into the correct position in stack A
4. Determin the least number of operations from step 3 above
5. Execute the operation
6. Repeat step 3 until stack B is empty
7. Rotate stack A until it is in the correct position from smallest to largest numbers

## Requirments
1. Create the sorting algorithm based on the rules above.
2. Create the 2 stacks, you can use arrays, linked list or any data structures.
3. Create the operations required, ie. pa,pb,sa,sb... etc to manipulate your stacks in step 2 above.
4. Take as a command line argument the numbers to use for sorting.
5. Verify the command line arguments (numbers to sort), no duplicate numbers are allowed and they must be valid numbers.
6. There can be no memory leaks or segmentation faults.
7. The program will produce as an output the operations, pa,pb,sa,sb... etc.
8. Create a checker that takes the output from step 7 and verifies stack A is sorted.
9. You are not allowed to use the system printf, you must create and use your own.
10. You are not allowed to use any libc function libraries, such as strlen, isdigit... etc. You must create your own.
11. You must create a makefile that compiles your libc and printf as a library.
12. You must create a makefile for your program and link your libraries from step 11 above.

## Compiling

In the root of the project,
Compile the main program and checker

```bash
make all
```

Compile the checker
```bash
make bonus
```

Recompile the main program and checker
```bash
make re
```

#### Cleaning
Clean all object files
```bash
make clean
```

Clean all object files and programs executables
```bash
make fclean
```
