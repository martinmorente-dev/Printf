#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int     ft_printnb (int n,int counter)
{
        if(n == INT_MIN)
        {
                write(1,"-2147483648",11);
                counter = 11;
                return (counter);
        }
        if (n < 0 && n != INT_MIN)
        {
                write(1,"-",1);
                counter++;
                n = -n;
        }
        if (n < 10)
        {
                n = n + '0';
                write(1,&n,1);
                counter++;
        }
        else
        {
                counter = ft_printnb((n / 10), counter);
                n = (n % 10) + '0';
                write(1,&n,1);
                counter++;
        }
        return (counter);
}

void    format(va_list args, char *str)
{
        int     counter;

        counter = 0;
       	if(*str == 'd' || *str == 'i')
		ft_printnb((va_arg, int) counter); //Print a decimal number on base 10
}

int     ft_printf(char const *str, ...)
{
        va_list args;
        int             checker;

        if (!str)
                return (0);
        checker = 0;
        va_start(args,*str);
        while (*str)
        {
                if (*str == '%')
                {
                        str++;
                        checker += format(args, (char *)str);
                }
                else
			print_str((char *)str);
                va_end(args);
                return (checker);
        }
}

int	main(void)
{
	ft_printf("Hola Luis tu edad es %d",18);

	return(0);
}