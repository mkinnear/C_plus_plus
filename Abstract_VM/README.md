# this Project is an abstraction of a virtual machine coded in the c++ programming language..
# we have to create a stack, and push an object with values of a specific data type (INT8, INT16, INT32, FLOAT, DOUBLE) containing a specific number of bits on to the stack
# we then have to perform basic calculations with the objects on the stack using polymorphic operation overloads

** READ BELOW FOR A BETTER UNDERSTANDING ON HOS THE PROGRAM WORKS AND HOW IT SHOULD BE USED **

** HOW TO RUN THE PROGRAM **
-> in your terminal type make and then enter to compile the program and create an executable file Abstract_VM
** RUN THE PROGRAM WITH TAKING USER IMPUT FROM THE COMMAND LINE **
-> to run the program type ./Abstract_VM
-> it will prompt an empty line and wait for your imput ** SEE THE COMMAND USE IN THE INSTRUCTION LIST BELOW **
** RUN THE PROGRAM WITH TAKING USER INPUT FROM A FILE (theres a folder named tests filled with test.avm files in this directory) **
-> to run the program type ./Abstract_VM tests/test.avm -> change the test file by retyping tests/test.avm and changing the testfile number like this -> tests/test30.avm

# READ BELOW TO UMDERSTAND HOW THE PROGRAM WORKS

-> the stack was created with a vector storing class objects..
-> the class objects is instanciated through the implemention of a factory class which a createdIOperand function calling an interface with pure virtual functions of polymorphic operands..

# this virtual machine takes in 5 types ov values

-> Int8: an integer of 8 bits.(1 byte) = ( can be considered equivelant to a char **chars also contains 8 bits **)
-> Int16: an integer of 16 bits.(2 bytes)
-> Int32: an integer of 32 bits.(4 bytes)
-> Float: a float value consisting of 4 bytes (floats contain decimal values)
-> Double: a double value consisting of 8 bytes (doubles contain of both real numbers and decimal values)

# this vertual machine uses a list of instructions.

-> PUSH: pushes to the stack..
-> POP: pops the element at the top of the stack.. 
-> ASSERT: runs a function to check if the value & type of the element on the top of the stack matches the instruction you are inputing.. 
-> MUL: removes the 2 values at the top of the stack and multiplies them, then returns the result value back onto the stack..
-> DIV: removes the 2 values at the top of the stack and divides them, then returns the result value back onto the stack..
-> ADD: removes the 2 values at the top of the stack and adds them, then returns the result value back onto the stack..
-> SUB: removes the 2 values at the top of the stack and subtracts them, then returns the result value back onto the stack..
-> MOD:  removes the 2 values at the top of the stack and divides them and finds the remainder, then returns the result value back onto the stack..
-> DUMP: dump prints out all the values that are on the stack..
-> PRINT: print can only work on values of type Int8 which contains 8 bits. this type is equivalant to the size of a char and its value can therefore be converted to an ascii character
-> EXIT: exit will exit the user input prompt when reading from a file.. the exit command for exiting user imput prompt for standard command line input is ** ;; ** (the double semi colon charaters)