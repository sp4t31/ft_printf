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

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//	ft_printf.c
int	conversion_specifier(const char *str, va_list ap);
int	ft_printf(const char *, ...);

//ft_char.c
int	ft_char(unsigned char c);

//ft_str.c
int	ft_str(char *str);

//ft_hex_void_ptr.c
int	ft_hex_void_ptr(void *ptr);

#endif