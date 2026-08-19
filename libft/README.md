*This project has been created as part of the 42 curriculum by msouza-t.*

# Libft

---

## Description

Libft is the foundational project of the 42 curriculum. The goal is to recreate a selection of essential functions from the standard C library (`libc`), as well as additional utility functions, to develop a deep, low-level understanding of memory management, pointer arithmetic, and data structures.

Since standard library functions are forbidden in subsequent 42 projects, the resulting static library (`libft.a`) serves as the core toolkit that I will reuse and expand throughout my journey in the curriculum.

### Features

* Reimplementation of Standard Library Functions: Rewriting core `libc` functions from scratch.
* Safe Memory Manipulation: Robust handling of buffers, allocations, and overlapping memory zones.
* String Processing Utilities: Advanced handling, splitting, trimming, and transformation of strings.
* Data Structure Implementation: A complete set of utilities for managing singly linked lists using generic pointers (`void *`).
* Strict Compilation Flags: Guaranteed stability and safety, compiled with `-Wall -Wextra -Werror`.
* Zero Memory Leaks: Thoroughly tested and validated using Valgrind.

### Library Functions

### Part 1 - Libc functions
| `ft_isalpha` | Checks if character is alphabetic           |
| `ft_strlen`  | Returns string length                       |
| `ft_isdigit` | Checks if character is a digit              |
| `ft_strchr`  | Finds first occurrence of a character       |
| `ft_isalnum` | Checks if character is alphanumeric         |
| `ft_strrchr` | Finds last occurrence of a character        |
| `ft_isascii` | Checks if character belongs to ASCII        |
| `ft_strncmp` | Compares two strings up to `n` bytes        |
| `ft_isprint` | Checks if character is printable            |
| `ft_strnstr` | Locates a substring inside a string         |
| `ft_toupper` | Converts character to uppercase             |
| `ft_strdup`  | Duplicates a string (allocates memory)      |
| `ft_tolower` | Converts character to lowercase             |
| `ft_substr`  | Extracts a substring from a string          |
| `ft_strjoin` | Concatenates two strings                    |
| `ft_strtrim` | Trims specific characters from both ends    |
| `ft_split`   | Splits a string into an array using a char  |
| `ft_strmapi` | Applies a function to map a new string      |
| `ft_striteri`| Iterates and applies a function to a string |

### Part 2 - Additional Functions
| `ft_memset`     | Fills memory with a constant byte                                 |
| `ft_bzero`      | Sets a byte string to zero                                        |
| `ft_memcpy`     | Copies memory area (non-overlapping)                              |
| `ft_memmove`    | Copies memory area safely even if zones overlap                   |
| `ft_memchr`     | Scans memory for a specific character                             |
| `ft_memcmp`     | Compares two memory blocks                                        |
| `ft_calloc`     | Allocates memory and initializes all bits to zero                 |
| `ft_atoi`       | Converts a string representation of an integer to an actual `int` |
| `ft_itoa`       | Converts an `int` into a dynamically allocated string             |
| `ft_putchar_fd` | Outputs a character to the specified file descriptor              |
| `ft_putstr_fd`  | Outputs a string to the specified file descriptor                 |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor       |
| `ft_putnbr_fd`  | Outputs an integer to the specified file descriptor               |

### Part 3 - Linked List
| `ft_lstnew`       | Allocates and initializes a new list node                       |
| `ft_lstadd_front` | Adds a new node at the beginning of the list                    |
| `ft_lstsize`      | Counts the number of nodes in the list                          |
| `ft_lstlast`      | Returns the last node of the list                               |
| `ft_lstadd_back`  | Adds a new node at the end of the list                          |
| `ft_lstdelone`    | Deletes and frees a single node content using a function        |
| `ft_lstclear`     | Deletes and frees an entire list and all its contents           |
| `ft_lstiter`      | Iterates the list and applies a function to each node content   |
| `ft_lstmap`       | Iterates a list and maps it into a brand new transformed list   |

---

## Instructions

### Requirements
* A Unix-like operating system (Linux / macOS)
* `gcc` or `clang` compiler
* GNU `make`

### Compilation & Commands
make
make all
make clean
make fclean
make re

---

## Resources

* PEREIRA, S. L. Estruturas de Dados em C - Uma Abordagem Didática, Saraiva, 2016. 
* Linux Programmer's Manual: System man pages (e.g., `man malloc`, `man memcpy`).
* GNU C Library Documentation

### AI Usage Disclosure

Artificial Intelligence tools such as Gemini were utilized during development strictly as interactive learning assistants for the following specific tasks:

* Concept Clarification: Breaking down complex behaviors of edge cases in functions like `memmove` (handling overlapping memory) and `split` (handling nested pointer arrays).
* Debugging Insights: Deciphering abstract segmentation faults and memory tracking warnings flags during local stress testing.
