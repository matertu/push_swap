*This project has been created as part of the 42 curriculum by msouza-t.*

# ft_printerr

A custom implementation of the standard C `printf` function, developed as part of the 42 School curriculum.

---

## DESCRIPTION

`ft_printerr` is a simplified recreation of the standard library function `printf()`. The goal of this project is to gain a deeper understanding of:

- Variadic functions (`stdarg.h`)
- String formatting
- Number conversion
- Recursive algorithms
- Low-level output using `write()`

The implementation reproduces the behavior of the original `printf` for a limited set of format specifiers required by the project.

---

## SUPPORTED CONVERSIONS

|  Specifier |                    Description                      |
|------------|-----------------------------------------------------|
| `%c`       | Prints a single character                           |
| `%s`       | Prints a string                                     |
| `%p`       | Prints a pointer address in hexadecimal format      |
| `%d`       | Prints a decimal (base 10) integer                  |
| `%i`       | Prints an integer                                   |
| `%u`       | Prints an unsigned decimal integer                  |
| `%x`       | Prints a hexadecimal number using lowercase letters |
| `%X`       | Prints a hexadecimal number using uppercase letters |
| `%%`       | Prints a percent sign                               |

---

## COMPILATION

Compile the library using:

```bash
make -> will generate 'libftprintf.a'
cc *.c libftprintf.a
```

To call the function in your program include 'ft_printerr.h' header, example: #include "ft_printerr.h".

## RESOURCES

- Linux `printf(3)` man page
- `stdarg.h` documentation
- 42 School subject
- C language reference documentation
- Hexadecimal conversion references
- Recursion tutorials
- Comparison tests against the standard `printf`

## AI USAGE

AI tools like chat GPT and Gemini were used to help create test cases and assist in debugging during development. All implementation decisions and final code were written and validated by me.