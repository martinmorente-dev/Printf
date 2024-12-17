#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int ft_print_dec_numb(unsigned int nb, int counter)
{
	if (nb < 10)
	{
		nb = nb + '0';
		write(1, &nb, 1);
		counter++;
	}
	else
	{
		counter = ft_print_dec_numb((nb / 10), counter);
		nb = (nb % 10) + '0';
		write(1, &nb, 1);
		counter++;
	}
	return (counter);
}

int ft_printstr(const char *str, int counter)
{
	int i = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		counter++;
	}
	return (counter);
}

int ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int format(va_list args, const char *str, int counter)
{
	if (*str == 's')
	{
		counter = ft_printstr(va_arg(args, char *), counter);
	}
	return (counter);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int checker = 0;
	int i = 0;

	if (!str)
		return (0);

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			checker = format(args, &str[i], checker);
			if (checker == -1)
				return (-1);
		}
		else
		{
			ft_putchar(str[i]);
			checker++;
		}
		i++;
	}
	va_end(args);
	return (checker);
}

int main(void)
{
    int result = ft_printf("%s", "Hola mundo");

    printf("Número de caracteres impresos: %d", result);
    
    return (0);
}