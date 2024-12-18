/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:07:14 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/18 13:00:50 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long num_hex, int counter)
{
	char	*base;

	*base = "0123456789abcdef";
	if (!num_hex)
		return (-1);
	if (num_hex > 15)
	{
		ft_print_hex(num_hex / 16, counter);
		ft_print_hex(num_hex % 16, counter);
	}
	else
	{
		write(1, &base[num_hex], 1);
		counter++;
	}
	return (counter);
}
