/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:12:22 by mmorente          #+#    #+#             */
/*   Updated: 2024/12/30 11:31:09 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long mem_dir)
{
	int	i;

	i = 0;
	if (!mem_dir)
		return (ft_printstr("(nil)", 1));
	i += write(1, "0x", 2);
	i += ft_print_hex(mem_dir);
	return (i);
}
