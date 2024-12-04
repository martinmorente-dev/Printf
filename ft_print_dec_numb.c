/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_numb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:02:49 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/04 11:16:15 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Nota: Cuando se realiza esta función no puede terminar inesperadamente tal como dice en el subject lo que quiere decir que cualquier forma inesperada sera evaluada con un 0

int ft_print_dec_numb(unsigned int nb, int counter)
{
	while (nb > 9)
	{
		counter = ft_print_dec_numb(nb, counter);
		nb = (nb % 10) + '0';
		write(1, &nb, 1);
		counter++;
	}
}
