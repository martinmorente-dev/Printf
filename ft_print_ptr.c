/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:12:22 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/18 13:08:50 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long mem_dir, int counter)
{
	char	*base;

	if (!mem_dir)
		return (-1);
	counter += write(1, "0x", 2);
	ft_print_hex(mem_dir, counter);
	return (counter);
}
