#include "ft_printf.h"
#include <stdio.h>


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
	return (i);
}
int	ft_putchar(char c)
{
	write(1,&c,1);
	return (1);
}

int	format(va_list args, const char *str, int counter)
{
	if (*str == 's')
		counter = ft_printstr(va_arg(args, char *), counter);
	return (counter);
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
		}
		else
		{
			leng += ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (checker + leng);
}


int main(void)
{

	int result;

	result = 0;
	result = ft_printf(" %s %s ", " - ", "");
	write(1,"\n",1);
	printf("My printf: %d",result);
	return 0;
}
