/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:12:22 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/19 13:22:05 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long mem_dir, int counter)
{
	if (!mem_dir)
		return (ft_printstr("(nil)", counter));
	counter += write(1, "0x", 2);
	ft_print_hex(mem_dir);
	return (counter);
}
