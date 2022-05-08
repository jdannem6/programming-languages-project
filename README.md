# Program Comparison between C and Python
### CS33101: Structure of Programming Languages
This project demonstrates some of the main differences between Python and C programming languages through a simple program coded in both languages and in different programming paradigms (imperative(procedural) and object-oriented)


## Program Description
The program emulates the creation and modification of a customer record at their bank. More particularly, both programs create a Customer entity to represent a given customer, and use functions (C) or class methods (Python) to perform operations upon the  customer's data. Such operations include adding new checking accounts and updating or returning the balance of a given checking account.

### Prerequisites
This project was tested with a system consisting of a gcc compiler, a gdb debugger, Python3.9.12, and a Windows 10 Pro operating system

### C Program
## Program Translation and Execution
1. Compile the program Account.c and produce object file Account.o

![](/documentation_images/compileC.PNG)

2. Run the Account.o object file

![](/documentation_images/executeC.PNG)

## Example Output
![](/documentation_images/sample_output_C.PNG)

### Python Program
## Program Translation and Execution
1. Interpret and run the Account.py program

![](/documentation_images/executePy.PNG)

## Example Output
![](/documentation_images/sample_output_Py.PNG)

### Comparison of Programming Languages
One of the largest differences between the two langauges is that C does not support the Object-Oriented paradigm while Python does. In order to demonstrate the effect of this difference, the C program was written under the imperative programming paradigm while the Python was written under the object-oriented paradigm. Discrepencies between the two programs can easily be seen in how they perform their operations upon the Customer's data. C relies on functions, independent of any class, to perform its operations on the Customer struct instances while Python uses the defined methods of the Customer Class to perform them.

Another important distinction between these langauges is in their garbage collection schemes. Specificially, Python uses the reference counting garbage collection method while C does not natively support automatic garbage collection. This implies that the burden of allocating and deallocating dynamic data falls on the programmer in C, but is managed entirely behind-the-scenes by Python's implementation. This can be seen by comparing the functions used in both programs to add an account to the Customer entity. In the case of C, that dynamic account information must be allocated and deallocated explicity (through the use of malloc() and free(), respectively), but in python, how new accounts are dynamically added to the accounts attribute is completely behind-the-scenes.

A third major distinction is that C is statically-typed while Python is dynamically-typed, meaning that in C, a variable's type must explicitly declared at that variable's declaration while in Python, variable type is not declared by the programmer. By abstracting type information away from the program, Python lends greater freedom to the programmer, enabling them to focus on the logic central to their program. Their are certain advantages of statically-typed langauges, such as C, however. Particularly, in such languages, the all variables' types are known at compile time, so they can be checked and fixed before running a program, preventing any type-mismatch errors that would otherwise occur at run-time. Contrast this with Python, where any type mismatch errors result in run-time failures.

The two languages can be further distinguished by their translation methods, as Python is an interpreted language while C is a compiled language. This means that lines of source code within Python are converted into bytecode and executed line-by-line rather than entire code blocks being compiled and then executed together as in compiled langugages, such as C. Moreover, since, some code blocks are executed frequently within a program and can break down into many lower-level instructions, the line-by-line interpretation used in Python can often result in the reinterpretation of the same source code. Due to this, Python typically has higher execution times than C.

A final distinction between Python and C is in their scope convention. In C, the scope of a variable is limited to the block of code within which they were declared. In python, however, variables can be accessed outside their declaration blocks. This affords greater freedom to the programmer, but it also implies that Python must also deal with collisions between variables with matching identifiers.






 
