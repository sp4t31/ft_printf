/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:33:56 by spatel            #+#    #+#             */
/*   Updated: 2022/04/28 17:33:56 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_specifier(const char &str, va_list ap)
{
	if (*str == 'c')
		return (ft_char(va_arg(ap, int)));
		//convert to char
	else if (*str == 's')
		return (ft_str(va_arg(ap, *char)));
		//convert to string
	else if (*str == 'p')
		return (ft_void_ptr_hex(va_arg(ap, *void)));
		//convert to void pointer in hexadecimal format
	else if (*str == 'd' || *str == 'i')
		return (ft_signed_dec(va_arg(ap, double)));
		//convert to int
	else if (*str == 'u')
		return (ft_unsigned_dec(va_arg(ap, unsigned int)));
		//convert to unsigned int
	else if (*str == 'x')
		return (ft_unsigned_hex_lc(va_arg(ap, unsigned int)));
		//unsigned int to unsigned hex (lowercase)
	else if (*str == 'X')
		return (ft_unsigned_hex_uc(va_arg(ap, unsigned int)));
		//unsigned int to unsigned hex (uppercase)
	else 
		return(0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	printed_bytes;
	va_list	ap;
	char	c;

	i = 0;
	c = '%';
	printed_bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			printed_bytes += write(1, &c, 1);
			i++;
		}
		else if (str[i] == '%')
			printed_bytes += conversion_specifier(&str[i + 1], ap);
		else
			printed_bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (printed_bytes);
}

int	main(void)
{
	char*	str = "blah";
	char	b = 'B';
	char	c = 'C';
	ft_printf("%s %c %c", str , b , c);
}
