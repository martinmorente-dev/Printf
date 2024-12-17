/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:11:38 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/17 13:09:55 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format(va_list args, const char *str, int counter)
{
	int counter;

	counter = 0;
	if (*str == 'c')
	{
		counter = ft_putchar(va_arg(args, int)); // print character
	}
	else if (*str == 's')
	{
		counter = ft_printstr(va_arg(args, char *), counter);
	}
	else if (*str == 'p')
	{
		// Print pointer
	}
	else if (*str == 'd' || *str == 'i')
	{
		counter = ft_printnb((va_arg(args, int)), counter);
	}
	else if (*str == 'u')
	{
		counter = ft_print_dec_numb((va_arg(args,unsigned int)),counter);
	}
	else if (*str == 'x')
	{
		// Print hexadecimal number (base 16) in uppercase
	}
	else if (*str == 'X')
	{
		// Print hexadecimal number (base 16) in lowercase
	}
	else if (*str == '%')
	{
		counter = ft_putchar(*str); // Print the percentage symbol
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
