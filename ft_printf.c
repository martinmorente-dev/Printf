/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:11:38 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/13 10:58:05 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format(va_list args, char *str)
{
	int	counter;

	counter = 0;
	if (*str == 'c')
		ft_putchar(va_arg(args, int));//print character
	else if (*str == 's')
		ft_printstr(va_arg(args, char *));//print string
	else if(*str == 'p')
		// Print pointer;
	else if(*str == 'd' || *str == 'i')
		ft_printnb((va_arg(args, int), counter));
	else if(*str == 'u')
		//Print decimal number base 10
	else if(*str == 'x')
		//Print hexadecimal number (base 16) in uppercase
	else if(*str == 'X')
		//Print hexadecimal number (base 16) in lowercase
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
