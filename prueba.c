#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int     ft_printnb(int n, int counter)
{
    if (n == INT_MIN)
    {
        write(1, "-2147483648", 11);
        counter = 11;
        return (counter);
    }
    if (n < 0 && n != INT_MIN)
    {
        write(1, "-", 1);
        counter++;
        n = -n;
    }
    if (n < 10)
    {
        n = n + '0';
        write(1, &n, 1);
        counter++;
    }
    else
    {
        counter = ft_printnb(n / 10, counter);
        n = (n % 10) + '0';
        write(1, &n, 1);
        counter++;
    }
    return (counter);
}

int     format(va_list args, const char *str, int counter)
{
    if (*str == 'd' || *str == 'i')
    {
        counter = ft_printnb(va_arg(args, int), counter);
    }
    return (counter);
}

int     ft_printstr(char *str, int counter)
{
    int i = 0;
    while (str[i] != '%' && str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
        counter++;
    }
    return counter;
}

int     ft_printf(const char *str, ...)
{
    va_list args;
    int checker = 0;

    if (!str)
        return (0);

    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            checker = format(args, str, checker);
        }
        else
        {
            checker = ft_printstr((char *)str, checker);
        }
        str++;
    }
    va_end(args);
    return (checker);
}

int main(void)
{
    ft_printf("Hola Luis tu edad es %d", 108);
    return (0);
}
