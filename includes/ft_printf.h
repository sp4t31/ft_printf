/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:06:10 by marvin            #+#    #+#             */
/*   Updated: 2022/04/10 11:06:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// SRC
int		ft_printf(const char *str, ...);
int		ft_index(char a, va_list ap, int *i);
int		ft_print_str(char *str);
void	ft_print_unsigned(long long int n, char a, int base);
void	ft_print_int(int n);
int		ft_print_nbr(long long int n, char a, int base);
int		ft_putchar(int c);

#endif
