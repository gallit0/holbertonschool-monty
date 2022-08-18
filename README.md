Monty ByteCode Interpreter

This program is an interpreter for Monty ByteCodes files, it will open the file and excecute the instructions given inside.
The program must be given only one argument, it being the name of the Monty file to be opened.

It is built to handle the following instructions:
  - push: Pushes an element to the stack. The element must be an interger, otherwise it will exit with the status EXIT_FAILURE.
  - pall: Prints all values of the stack starting from the top. Be it the case that the stack is empty, it won't print anything.
  - pint: Prints the value at the top of the stack, followed by a new line. If the stack is empty, it will exit with the status EXIT_FAILURE.
  - pop: Removes the top element of the stack. If the stack is empty, it will exit with the status EXIT_FAILURE.
  - swap: Swaps the top two elements of the stack. If the stack contains less than two elements, it will exit with the status EXIT_FAILURE.
  - add: Adds up the top two elements of the stack, stores the result in the second top element, and deletes the top element of the stack. If the stack contains less than two elements, it will exit with the status EXIT_FAILURE.
  - nop: Doesn't do anything.

The program returns 0 upon success, or 1 if failure.
