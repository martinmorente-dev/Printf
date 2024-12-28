/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_numb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:02:49 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/28 13:35:22 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_print_uns_numb(unsigned int nb, int counter)
{
	if (nb < 10)
	{
		nb = nb + '0';
		counter += write (1, &nb, 1);
	}
	else
	{
		counter = ft_print_uns_numb((nb / 10), counter);
		nb = (nb % 10) + '0';
		write (1, &nb, 1);
		counter++;
	}
	return (counter);
}
