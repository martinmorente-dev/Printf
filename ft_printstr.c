/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:38:25 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/17 12:54:21 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printstr(const char *str, int counter)
{
	int	i;

	if (*str == NULL)
		str = "(null)";
	i = 0;
	while (str[i] != '%' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		counter++;
	}
	return (counter);
}