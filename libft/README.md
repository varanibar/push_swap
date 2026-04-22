*This project has been created as part of the 42 curriculum by varaniba*
# DESCRIPTION
Libft is the first project in the CODAM (42 School) curriculum. It consists of creating our own library by recreating the behavior of Libc, the standard C library. The goal of recreating these functions is to understand how they work and learn how to implement them effectively. 
## Part 1

### Character checks and conversion
- ft_isalpha: checks whether a character is alphabetic.
- ft_isdigit: checks whether a character is a decimal digit.
- ft_isalnum: checks whether a character is alphanumeric.
- ft_isascii: checks whether a character is part of the ASCII character set.
- ft_isprint: checks whether a character is printable.
- ft_toupper: converts a lowercase letter to uppercase.
- ft_tolower: converts an uppercase letter to lowercase.
### String functions
- ft_strlen: returns the length of a string.
- ft_strlcpy: copies a string into a destination buffer of a given size.
- ft_strlcat: appends a string to a destination buffer of a given size.
- ft_strchr: locates the first occurrence of a character in a string.
- ft_strrchr: locates the last occurrence of a character in a string.
- ft_strncmp: compares two strings up to a specified number of characters.
- ft_strnstr: locates a substring in a string within a maximum length.
- ft_strdup: allocates memory and returns a duplicate of a string.
### Memory functions
- ft_memset: fills a block of memory with a specified value.
- ft_bzero: fills a block of memory with zeros.
- ft_memcpy: copies a block of memory from one location to another.
- ft_memmove: copies a block of memory safely, including overlapping regions.
- ft_memchr: searches for a byte in a block of memory.
- ft_memcmp: compares two blocks of memory.
### Conversion
- ft_atoi: converts a string to an integer.
### Memory allocation
- ft_calloc: allocates memory and initializes it to zero.
## Part 2
### String manipulation
- ft_substr: creates a substring from a given string.
- ft_strjoin: joins two strings into a new one.
- ft_strtrim: trims selected characters from the beginning and end of a string.
- ft_split: splits a string into an array of strings using a delimiter.
- ft_strmapi: creates a new string by applying a function to each character of a string.
- ft_striteri: applies a function to each character of a string in place.
### Conversion
- ft_itoa: converts an integer into a string.
### Output functions
- ft_putchar_fd: writes a character to a file descriptor.
- ft_putstr_fd: writes a string to a file descriptor.
- ft_putendl_fd: writes a string followed by a newline to a file descriptor.
- ft_putnbr_fd: writes an integer to a file descriptor.
## Part 3
### Node creation
- ft_lstnew: allocates memory and returns a new node initialized with the given content, with next set to NULL.
### List insertion
- ft_lstadd_front: adds the node new at the beginning of the list.
- ft_lstadd_back: adds the node new at the end of the list.
### List information
- ft_lstsize: counts the number of nodes in the list.
- ft_lstlast: returns the last node of the list.
### List modification
- ft_lstdelone: frees the content of a node using a delete function and then frees the node itself, without freeing the next node.
- ft_lstclear: deletes and frees a node and all following nodes using a delete function, then sets the list pointer to NULL.
- ft_lstiter: iterates through the list and applies a function to the content of each node.
- ft_lstmap: iterates through the list, applies a function to each node’s content, and creates a new list from the results. If needed, del is used to free allocated content.
# INSTRUCTIONS

## Compilation
To create the library, follow these next steps:
- Clone the repository into the desired directory.
- Create the library by running the 'make' command in the terminal (while inside the repository directory).

This will compile all '.c' files and create the 'libft.a' file in the repository.

### Makefile
- make / make all: creates 'libft.a'
- make clean: removes object ('.o') files
- make fclean: runs 'clean' and removes 'libft.a'
- make re: runs 'fclean' and then 'make all'

## Using the library
To use the library: 
- Include the header file in the project by using 
> #include "libft.h"
- Compile with the following flags: 'cc -Wall -Wextra -Werror'
- Link the archive during the compilation by writing '-L.' and '-lft'
- Name the output file with the '-o' flag
The command in the terminal should look like: 
> cc -Wall -Wextra -Werror file.c -L. -lft -o program_name

# RESOURCES
To create this library, the references and tools used were:
- Linux man page [manual](https://linux.die.net/man/)
- W3 schools [website](https://www.w3schools.com/)
- GeeksforGeeks [website](https://www.geeksforgeeks.org/)
- Stack Overflow [website](https://stackoverflow.com/questions)
- Github [website](https://github.com/)

AI Use:
- ChatGPT :
AI was used to support understanding of C concepts and clarify errors and bugs during the project. The code in this project was written by me.





