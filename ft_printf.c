/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:11:38 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/09 21:51:09 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format(va_list args, char *str)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int));//print character
	else if (*str == 's')
		ft_printstr(va_arg(args, char *));//print string
	else if(*str == 'p')
		TODO(); //print pointer in hexadecimal format (search)
	else if(*str == 'd')
		TODO(); //Print a decimal number on base 10
	else if(*str == 'i')
		TODO();//Print a int number base 10
	else if(*str == 'u')
		TODO();//Print decimal number base 10
	else if(*str == 'x')
		TODO();//Print hexadecimal number (base 16) in uppercase
	else if(*str == 'X')
		TODO();//Print hexadecimal number (base 16) in lowercase
	else if(*str == '%')
		ft_putchar(*str);// Print the percentage symbol
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		checker;

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
