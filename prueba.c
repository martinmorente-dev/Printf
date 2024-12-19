#include "ft_printf.h"
#include <limits.h>  // Para LONG_MAX

int	ft_print_hex(unsigned long num_hex)
{
    char				*base = "0123456789abcdef";
    unsigned long long	counter = 0;

    if (num_hex >= 16)
    {
        counter += ft_print_hex(num_hex / 16);  // Recursión para dividir el número
        counter += ft_print_hex(num_hex % 16);  // Imprimir el último dígito
    }
    else
    {
        write(1, &base[num_hex], 1);  // Imprimir el dígito hexadecimal
        counter++;
    }
    return (counter);
}

int	format(va_list args, const char *str, int counter)
{
    if (*str == 'x')
        counter = ft_print_hex((va_arg(args, long)));  // Usa 'long' aquí para trabajar con LONG_MAX
    return (counter);
}

int	ft_printf(const char *str, ...)
{
    va_list	args;
    int		checker = 0;
    int		leng = 0;

    if (!str)
        return (0);

    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            checker += format(args, str, checker);
            if (checker == -1)
                return (-1);
        }
        else
            leng += ft_putchar(*str);
        str++;
    }
    va_end(args);
    return (checker + leng);
}



int	ft_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (1);
}

int	main(void)
{
    ft_printf(" %x ", LONG_MAX);  // Usa LONG_MAX directamente, no hace falta cast
    write(1,"\0",1);
    return (0);
}
