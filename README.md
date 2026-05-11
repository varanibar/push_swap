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
Four distinct sorting strategies must be implemented and the program must be able to select a strategy at runtime based on the input configuration. When a complexity class is stated, the theoretical complexity of a classical array-based algorithm considers every CPU step as an operation, but for this project, the cost is measured in number of `push_swap` operations generated.

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
### Selection sort - O(*n²*):
Selection sort is a comparison-based sorted algorithm. It repeatedly looks for the smallest value in the unsorted part of the stack and moves it to its final position.

For this project, the algorithm is adapted to the `push_swap` constraint. Since values cannot be moved directly by index, the implementation first finds the position of the smallest value in stack `a`. Then, stack `a` is rotated until this value reaches the top. The rotation direction is chosen depending of the smalles value. Once the smallest value is at the top, it is pushed to stack `b`. The process is repeated until stack `a` is sorted or until the required passes have been completed. Finally, all values stored in stack `b` are pushed back to stack `a`.

The implementation is divided into three main steps:
- `ft_min_index` finds the position of the smallest value in stack `a`.
- `ft_rotate_and_push` brings the smallest value to the top using `ra` or `rra`, then pushes it to stack `b`.
- `ft_selection_sort` repeats this process and then pushes all values from stack `b` back to stack `a`.
### Chunk sort - O(*n√n*):
Chunk sort is a rank-based sorting algorithm. Instead of comparing all values directly, it divides the ranked values into smaller groups called chunks and processes each chunk separately.

For this project, the number of chunks is based on the square root of the stack size. Each chunk represents a range of ranks. The algorithm searches stack `a` for values that belong to the current chunk, rotates stack `a` until one of those values reaches the top, and pushes it back to stack `b`.
After all chunks have been pushed to stack `b`, the values are moved back to stack `a` in descending order. The algorithm repeatedly finds the highest value in stack `b`, rotates stack `b` until this value reaches the top, and pushes it back to stack `a`.

The implementation is divided into several main steps:
- `ft_sqrt` calculates the square root used to define the number of chunks.
- `ft_get_chunk_bounds` calculates the minimum and maximum rank of the current chunk.
- `ft_find_chunk_index` finds the first value in stack `a` that belongs to the current chunk.
- `rotate_and_push_to_b` rotates stack `a` using `ra` or `rra`, then pushes values from the current chunk to stack `b`.
- `ft_max_index` finds the position of the highest value in stack `b`.
- `push_back_to_a` brings the highest value in stack `b` to the top using `rb` or `rrb`, then pushes it back to stack `a`.
- `ft_chunk_sort` processes all chunks and then rebuilds stack `a` in sorted order.

### Radix sort LSD - O(*n log n*):
Radix sort LSD is a digit-based sorting algorithm. Instead of comparing values directly, it processes the numbers digit by digit, starting from the least significant digit. In the decimal version, each pass separates the values into several buckets according to the current digit.

For this project, the algorithm is adapted to the `push_swap` constraint. Since only two stacks are available, the implementation uses the binary representation of the ranked values. Each pass checks one bit position and separates the values between stack `a` and stack `b`. Values with a `0`at the current bit are pushed to stack `b`, while values with a `1` stay in stack `a`through rotation. After each pass, the values in stack `b` are pushed back to stack `a`. The process is repeated for each bit needed to represent the highest rank.

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
The subject requires support for flags and valid input, but it does not explicitly require GNU-style argument permutation, for instance:
>>`cat -e file.txt`

>>`cat file.txt -e`

Because of this, the program uses the following strict argument grammar:

```bash
./push_swap [options] [operands]
```

Options are flags such as benchmark mode `--bench` or strategy flags such as `--simple`, `--medium`, `--complex`. Operands are the values the program works on, in this case the numbers to sort.
If flags are present, the options section is closed.  From that point, every following argument must be a valid integer.

Available options:

- Benchmark mode:
  - `--bench` displays the computed disorder, the name of the selected strategy, its theoretical complexity class, the total number of operations, and the count of each operation type on `stderr`.
- Strategy selector:
  - `--simple` forces the simple strategy, based on Selection sort.
  - `--medium` forces the medium strategy, based on Chunk sort.
  - `--complex` forces the complex strategy, based on Radix sort.
  - `--adaptive` selects one of the algorithms according to the disorder metric.

  In adaptive mode, the strategy is selected as it follows:
  - If the disorder is lower than 20%, the simple strategy is used.
  - If the disorder is greater than or equal to 20% and lower than 50%, the medium strategy is used.
  - If the disorder is greater than or equal to 50%, the complex strategy is used.

  There is one exception to this rule: for very small inputs of 5 integers or less, the simple strategy is used even when the disorder is high, because it has proven to be more efficient for this type of input. If no strategy is specified, the default behavior is the adaptive strategy.

  A maximum of two flags is accepted:

  >>Benchmark mode + Strategy selector


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
# Contributions
The work was divided between both contributors, with several parts later reviewed, adapted, or reused across the project.

varaniba's main contributions:
- Input parsing and argument validation
- Command-line flag handling
- Radix sort implementation
- README structure and documentation

lekoelma`s main contributions:
- `push_swap` operations implementation
- Selection sort implementation
- Chunk sort implementation
- Adaptive strategy implementation

During the project duration, several functions and structures were adjusted together so they could be reused by different parts of the program. Some code was also adapted by the other contributor when needed to keep the project consistent and functional as a whole.

# RESOURCES
To create this program, the references and tools used were:
- Linux man page [manual](https://linux.die.net/man/)
- W3 schools [DSA Time Complexity](https://www.w3schools.com/dsa/dsa_timecomplexity_theory.php)
- GeeksforGeeks [Time Complexities of all Sorting Algorithms](https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/)
- TutorialsPoint [Selection Sort Algorithm](https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm)
- w3schools [Selection Sort](https://www.w3schools.com/dsa/dsa_algo_selectionsort.php)
- Medium [Sorting Large Datasets with Limited Memory: The Chunked Merge Sort Approach](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)
- GeeksforGeeks [Radix Sort Algorithm](https://www.geeksforgeeks.org/dsa/radix-sort/)

- POSIX utility conventions [Utility Argument Syntax](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)
 - GNU Coding Standards [Standards for Command Line Interfaces](https://www.gnu.org/prep/standards/standards.html#Command_002dLine-Interfaces)
- Github [website](https://github.com/)

AI Use:
- ChatGPT and Claude:
  - Understanding programming concepts;
  - Debugging and reasoning about implementation issues;
  - Improving README wording, grammar, and clarity.

All the code, the implementation choices and final project structure were created by the authors.
