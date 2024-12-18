/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:32:39 by mmorente          #+#    #+#             */
/*   Updated: 2024/11/05 09:32:39 by mmorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_printstr(const char *str, int counter);
int		ft_printnb(int n, int counter);
int		ft_putchar(char c);
int		ft_print_dec_numb(unsigned int nb, int counter);
int		ft_print_ptr(unsigned long long mem_dir, int counter);
int		ft_print_hex(unsigned long long num_hex, int counter);

#endif
