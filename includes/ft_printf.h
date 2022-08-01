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

// SRC
int		ft_printf(const char *str, ...);
int		ft_conversion_specifier(char a, va_list ap);
int		ft_str(char *str);
int		ft_putchar(char c);
void	ft_putnbr(long long int n);
void	ft_putnbr_hex(unsigned int n, char a);
int		ft_calculate_bytes(long long n, char a, int base);


#endif