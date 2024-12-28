#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_print_ptr(unsigned long long mem_dir, int counter)
{
	if (!mem_dir)
		return (ft_printstr("(nil)", 1));
	counter += write(1, "0x", 2);
	counter += ft_print_hex(mem_dir);
	return (counter);
}


int	ft_printstr(const char *str, int counter)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		counter += write(1, &str[i], 1);
		i++;
	}
	return (counter);
}

int	ft_print_hex(unsigned long long num_hex)
{
	char				*base;
	unsigned long long	counter;

	base = "0123456789abcdef";
	counter = 0;
	if (num_hex >= 16)
	{
		counter += ft_print_hex(num_hex / 16);
		counter += ft_print_hex(num_hex % 16);
	}
	else
	{
		write(1, &base[num_hex], 1);
		counter++;
	}
	return (counter);
}

int	format(va_list args, const char *str, int counter)
{
	
	if (*str == 'p')
		counter = ft_print_ptr(va_arg(args, unsigned long long), counter);
	return (counter);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		checker;
	int		leng;

	checker = 0;
	leng = 0;
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


int main(void)
{
	int result = 0;
	int real_res = 0;

	result = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%d\n",result);
	printf("%d\n",real_res);
	return 0;
}
