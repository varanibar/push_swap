*This project has been created as part of the 42 curriculum by varaniba and lekoelma.*
# DESCRIPTION
The Push Swap project is an algorithm project where data must be sorted. The `push_swap` program calculates and displays on the standard output the operations needed to sort the integers received as arguments. The goal of this project is to discover algorithmic complexity, through the use of two stacks and a set of operations to sort a set of integer values.

## RULES
### STACKS
At the beginning:
- stack `a` contains a random amount of integers without any duplicate.
- stack `b` is empty.
### OPERATIONS
Only the following operations are allowed:

- Swap operations:
	- `sa` (swap a) swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
	- `sb` (swap b) swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
	- `ss` sa and sb at the same time.
- Push operations
	- `pa` (push a) Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	- `pb` (push b) Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- Rotate operations
	- `ra` (rotate a) Shift up all elements of stack a by one. The first element becomes the last one.
	- `rb` (rotate b) Shift up all elements of stack b by one. The first element becomes the last one.
	- `rr`  ra and rb at the same time.
	- `rra` (reverse rotate a) Shift down all elements of stack a by one. The last element becomes the first one.
	- `rrb` (reverse rotate b) Shift down all elements of stack b by one. The last element becomes the first one.
	- `rrr` rra and rrb at the same time.

### ALGORITHM REQUIREMENTS
Four distinct sorting strategies must be implemented and the program must be able to select a strategy at runtime based on the input configuration. When a complexity class is stated, the theoretical complexity of a classical array-based algorithm every considers CPU step as an operation, but for this project, the cost is measured in number of `push_swap` operations generated.

 The required strategies are:
1. Simple algorithm (O(*n²*))
2. Medium algorithm (O(*n√n*))
3. Complex algorithm (O(*n log n*))
4. Custom adaptive algorithm (learner’s design): adaptive strategy that selects different internal methods depending on the measured disorder.
### DISORDER METRIC
Disorder is a value between `0` and `1` that represents how far the initial stack `a` is from being sorted.
The metric is based on the number of inverted pairs. An inverted pair is a pair of values where the bigger value appears before the smaller one.

If the stack is already sorted, there are no inverted pairs and the disorder is `0`. If the stack is in reverse order, all possible pairs are inverted and the disorder is `1`

## METHOD

The following algorithms have been implemented for each strategy:
### Selection sort (O(*n²*)):
Selection sort is a comparison-based sorted algorithm. It repeatedly looks for the smallest value in the unsorted part of the stack and moves it to its final position.

For this projectm the algorithm is adapted to the `push_swap` constraint. Since values cannot be moved directly by index, the implementation first findst the position of the smallest value in stack `a`. Then, stack `a` is rotated until this value reaches the top. The rotation direction is chosen depending of the smalles value. Once the smallest value is at the top, it is pushed to stack `b`. The process is repeated until stack `a` is sorted or until the required passes have been completed. Finally, all values stored in stack `b` are pushed back to stack `a`.

The implementation is divided into three main steps:
- `ft_min_index` finds the position of the smallest value in stack `a`.
- `ft_rotate_and_push` brings the smallest value to the top using `ra` or `rra`, then pushes it to stack `b`.
- `ft_selection_sort` repeats this process and then pushes all values from stack `b` back to stack `a`.
### Chunk sort (O(*n√n*)):

### Radix sort LSD (O(*n log n*)):
Radix sort LSD is a digit-based sorting algorithm. Instead of comparing values directly, it processes the numbers digit by digit, starting from the least significant digit. In the decimal version, each pass separates the values into several buckets according to the current digit.

For this project, the algorithm is adapted to the `push_swap` constraint. Since only two stacks are available, the implementation uses the binary representation of the ranked values. Each pass checks one bit position and separates the values between stack `a` and stack `b`. Values with a `0`at the current bit are pushed back to stack `b`, while values with a `1` stay in stack `a`through rotation. After each pass, the values in stack `b` are pushed back to stack `a`. The process is repeated for each bit needed to represent the highest rank.

The implementation is divided into three main steps:
- `ft_bits` calculates how many bit positions are needed to represent the highest rank.
- `ft_process_one_bit` processes one bit position for all elements in stack `a`.
  - If the current bit is `0`, the value is pushed to stack `b`.
  - If the current bit is `1`, the value is rotated inside stack `a`.
  - At the end of the pass, all values from stack `b` are pushed back to stack `a`.
- `ft_radix_sort` repeats this process for each bit position until all required bits have been processed, or until the stack is already sorted.

# INSTRUCTIONS

## Compilation

The project uses a Makefile to compile the `push_swap` executable with the required compiler flags: `cc -Wall -Wextra -Werror`

The source files are compiled into object files (`.o`), then linked together with `libft.a` to create the final executable `push_swap`.

Available rules:
- `make` or `make all`: runs the makefile inside the `libft` directory, compiles the project source files, and creates the push_swap executable
- `make clean`: removes the object (`.o`) files from the project and runs `clean` inside the `libft` directory
- `make fclean`: runs `clean`, removes the `push_swap` executable, and runs `fclean` inside the libft directory
- `make re`: runs `fclean` and then recompiles the project from scratch

## Running the program

### Command-Line Interface (CLI)
The subject requires support for flags and valid input, but it does not explicitly require GNU-style argument permutation (for instance: `cat -e file.txt` or `cat file.txt -e`).
Because of this, the program uses the following strict argument grammar:

```bash
./push_swap [options] [operands]
```

Options are flags such as benchmark mode `--bench` or strategy flags such as `--simple`, `--medium`, `--complex`. Operands are the values the program works on, in this case the numbers to sort.
Once the first operand is found, the options section is closed.  From that point, every following argument must be a valid integer.

Available options:

- Benchmark mode:
  - `--bench` will show the metrics in addition to the operations made.
- Strategy selection:
  - `--simple` will force the simple complexity strategy (Selection sort).
  - `--medium` will force the medium complexity strategy (Chunk sort).
  - `--complex` will force the complex strategy (Radix sort).
  - `--adaptive` will choose the algorithm according to the disorder metric. For a disorder of less than 20%, the simple strategy is used. A disorder of more or equal 20% but less than 50%, the medium strategy is applied. For a disorder of more or equal than 50%, the complex strategy will be selected. There is an exception to this cases, for a very small input (of <= 5 integers), even if there is a high disorder, the simple strategy has proven to be the most efficient for this type of input.

  If no strategy option is specified, the default behavior is the adaptive strategy.

- Valid argument grammar:

```bash
./push_swap 5 4 3 2 1
```
```bash
./push_swap --simple 5 4 3 2 1
```
```bash
./push_swap --bench --complex 5 4 3 2 1
```
- Invalid argument grammar:

```bash
./push_swap --simple --medium 5 4 3 2 1
```
```bash
./push_swap 5 4 3 2 1 --simple
```
```bash
./push_swap --bench 5 4 3 2 1 --simple
```
```bash
./push_swap --bench --simple
```
# RESOURCES
To create this library, the references and tools used were:
- Linux man page [manual](https://linux.die.net/man/)
- W3 schools [DSA Time Complexity](https://www.w3schools.com/dsa/dsa_timecomplexity_theory.php)
- GeeksforGeeks [Time Complexities of all Sorting Algorithms](https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/)
- GeeksforGeeks [Radix sort](https://www.geeksforgeeks.org/dsa/radix-sort/)

- POSIX utility conventions [Utility Argument Syntax](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)
 - GNU Coding Standards [Standards for Command Line Interfaces](https://www.gnu.org/prep/standards/standards.html#Command_002dLine-Interfaces)
- Github [website](https://github.com/)

AI Use:
- ChatGPT :

?????????????????????
