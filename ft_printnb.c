/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:52:41 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/12 18:27:25 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printnb (int	n, int counter)
{
	if(n == INT_MIN)
	{
		
	}
	if (n < 0 && n != INT_MIN)
	{
		write(1,'-',1);
		counter++;
	}
	if(n > 9)
		ft_printnb((nb / 10), counter++)
	nb = nb + '0';
	write(1,&nb,1);
	counter++;
	return (counter);	
}
