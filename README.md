Push Swap 🔄💻
================

**Description** 📝
----------------

Push Swap is a sorting algorithm project that uses the Turk Algorithm, a stack-based approach to sort a list of integers. The goal is to sort the list in the fewest number of operations possible. This project is part of the 42 school curriculum and is a great exercise in algorithmic thinking and problem-solving.

**Goals** 🎯
---------

* Sort a list of integers in the fewest number of operations possible
* Implement a stack-based approach to sorting
* Optimize the algorithm for performance and efficiency

**How to Use** 🚀
-------------

### Building the Project

To build the project, simply run the following command in the terminal:
`make` This will compile the source code and create an executable file called `push_swap`.

### Running the Program

To run the program, simply execute the `push_swap` executable and pass in a list of integers as arguments, like so:
`./push_swap 3 1 5 2 4`
The program will then output the sorted list of integers using the following operations:

* `sa`: Swap the first two elements at the top of stack A.
* `sb`: Swap the first two elements at the top of stack B.
* `ss`: Swap the first two elements at the top of both stacks A and B.
* `pa`: Push the top element from stack B to stack A.
* `pb`: Push the top element from stack A to stack B.
* `ra`: Rotate stack A up by one position.
* `rb`: Rotate stack B up by one position.
* `rr`: Rotate both stacks A and B up by one position.
* `rra`: Rotate stack A down by one position.
* `rrb`: Rotate stack B down by one position.
* `rrr`: Rotate both stacks A and B down by one position.

### Cleaning Up

To clean up the project directory, run the following command:
`make clean`: This will remove just the object files.
`make fclean`: This will remove all object files and the executable file.

### Rebuilding the Project

To rebuild the project from scratch, run the following command: 
`make re`: This will remove all object files and the executable file, and then rebuild the project from scratch.

**Other Stuff** 🤔
--------------

* This project uses the `libft` library, which is included in the `libft` directory.
* The `Makefile` is configured to use the `cc` compiler and the `-Wall -Werror -Wextra` flags.
* The project is written in C and uses a stack-based approach to sorting.

**Contributing** 🤝
-------------

If you'd like to contribute to this project, please fork the repository and submit a pull request. I'd love to see your improvements and optimizations!
