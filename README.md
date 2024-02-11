# From the subject:

__Summary:__
The goal of this project is pretty straightforward. You will recode printf().  
You will mainly learn about using a variable number of arguments. How cool is that\?\?  
It is actually pretty cool :)  
Version: 10  

You have to recode the printf() function from libc.  

You have to implement the following conversions:  
• %c Prints a single character.  
• %s Prints a string (as defined by the common C convention).  
• %p The void * pointer argument has to be printed in hexadecimal format.  
• %d Prints a decimal (base 10) number.  
• %i Prints an integer in base 10.  
• %u Prints an unsigned decimal (base 10) number.  
• %x Prints a number in hexadecimal (base 16) lowercase format.  
• %X Prints a number in hexadecimal (base 16) uppercase format.  
• %% Prints a percent sign.  

__bonuses:__  
• Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.  
• Manage all the following flags: \’\#\ \+\’ (Yes, one of them is a space)  

I also added %b and %o.  

# Usage

`make` or `make bonus`.  
Call ft\_printf.  
```c
int	ft_printf(const char *s, ...);
```
