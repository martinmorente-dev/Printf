/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:38:25 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/09 21:43:45 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printstr(const char *str, int *i, int *counter)
{
	while (str[*i] != '%' && str[*i] != '\0')
	{
		write(1, &str[*i], 1);
		(*i)++;
		(*counter)++;
	}
}