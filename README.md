# Ft_Printf

### Introduction

This project is a remake of the standard library function *Printf*.  In this project, there were many techniques that I was already familiar with, bit this was such a big project with so many details that what I took out of it was planning and execution.  However, there were a few new concepts, such as variadic functions, dispatch tables and how floats/doubles are stored in memory.

Apart from this project having the experience reward, this also allowed me to use `ft_printf` in my other projects.  I no longer had to settle for `ft_putstr`, `print_hex`, `ft_putnbr` etc.

### Details

The allowed functions for this project are:
```
write
malloc
free
exit
stdarg variadic functions
```

Naturally, I used my Libft library.

The conversion specifiers that had to be handled were:
```
d: digits
i: digits
o: octal
u: unsinged
x: hexidecimal (lowercase)
X: hexidecimal (UPPERCASE)
f: floating point
```
diouxX had to be managed with the following length flags:
`hh, h, l, and ll`

As far as the `f` flag, we had to manage with the `l` and `L` flags.

`%%`, minimum width and precision had to be managed as well.

And finally, for all conversions, the following flags had to be handled as well:

```
'#'
'0'
'-'
'+'
' '
```

### Usage

To use print, compile the `ft_printf.a` library by cloning the repository and typing `make`.

Be sure to include the `ft_printf.h	` header file, and then you can use the following functions:

`ft_printf(const char *str, ...)`
This function works like printf.

`ft_printf_fd(int fd, const char *str, ...)`
This work like printf as well, but allows the caller to pass in a file descriptor.

### What's so special about your ft_printf?

One of the things that I spend extra time on in this project was the printing of floats and doubles.  The exponent and mantissa were extracted and then used to create a string, and then following a mathematic formula, the float/double was calculated.  This was cool because it made is so my implementation of ft_printf made rounding errors.  *Wait, why would you want that?* Well, that's what the real printf does.





Want to know more about this project?

Feel free to read the included PDF instructions or reach out and ask a question!

