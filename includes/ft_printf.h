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
# include <stddef.h>
//# include <stdlib.h> --malloc
# include <unistd.h>

// SRC
int		ft_printf(const char *, ...);
int		ft_conversion_specifier(const char &str, va_list ap);
int		ft_char(unsigned char c);
int		ft_str(char *str);
int		ft_hex_void_ptr(void *ptr);
void	ft_putnbr(int n);
int		ft_calculate_bytes(unsigned int x, int base);
void	ft_putnbr(int n);
void	ft_putnbr_hex(unsigned int n, int case);

#endif