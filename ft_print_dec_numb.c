/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_numb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:02:49 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/19 11:57:26 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_print_dec_numb(unsigned int nb, int counter)
{
	if (nb < 10)
	{
		nb = nb + '0';
		write (1, &nb, 1);
		counter++;
	}
	else
	{
		counter = ft_print_dec_numb((nb / 10), counter);
		nb = (nb % 10) + '0';
		write (1, &nb, 1);
		counter++;
	}
	return (counter);
}
