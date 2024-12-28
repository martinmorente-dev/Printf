/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:11:38 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/28 12:59:06 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list args, const char *str, int counter)
{
	if (*str == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (*str == 's')
		counter = ft_printstr(va_arg(args, char *), counter);
	else if (*str == 'p')
		counter = ft_print_ptr(va_arg(args, unsigned long long), counter);
	else if (*str == 'd' || *str == 'i')
		counter = ft_printnb((va_arg(args, int)), counter);
	else if (*str == '%')
		counter = ft_putchar(*str);
	else if (*str == 'u')
		counter = ft_print_uns_numb((va_arg(args, unsigned int)), counter);
	else if (*str == 'x')
		counter = ft_print_hex((va_arg(args, unsigned int)));
	else if (*str == 'X')
		counter = ft_print_hex_may((va_arg(args, unsigned int)));
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
