/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:52:41 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/12 08:58:32 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printnb (int	n)
{
	int	counter;

	counter = 0;
	if(nb == INT_MIN)
	{
		write(1,'INT_MIN',11);
		counter = 11;
		return (counter);
	}
	if (nb < 0 && nb != INT_MIN)
	{
		write(1,'-',1);
		counter++;
	}
	if(nb > 9)
	{
		
	}
}
