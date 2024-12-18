#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

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

int ft_print_ptr (unsigned long long mem_dir, int counter)
{
	char	hex[] = "123456789abcdef";

	if (!mem_dir)
		return (-1);
	
	if (mem_dir > 16)
	{
		ft_print_ptr(mem_dir % 16, counter);
	}
	else
	{
		write(1,&hex[mem_dir],1);
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
	if (*str == 'p')
	{
		counter = ft_print_ptr(va_arg(args, unsigned long long ),counter);
	}
	return (counter);
}

int ft_printf(const char *str, ...)
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
			if (checker == -1)
				return (-1);
		}
		else
		{
			ft_putchar(*str);
			checker++;
		}
		str++;
	}
	va_end(args);
	return (checker);
}

int main(void)
{
	char	*a;
	char	b;

	b = 'a';
	a = &b;

	ft_printf("%p",a);
	write(1,"\n",1);
	printf("%p",a);
    return (0);
}	