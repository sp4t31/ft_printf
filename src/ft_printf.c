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

/*
-- error checking
-- hex void pointer
-- write return
-- write percentage error
-- can convert char to *char? double on them
*/

int	ft_conversion_specifier(char a, va_list ap)
{
	if (a == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (a == 's')
		return (ft_str(va_arg(ap, *char)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(ap, long int)));
	else if (a == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (a == 'p')
		return (ft_void_ptr_hex(va_arg(ap, *void)));
	else if (a == 'x')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), 0));
	else if (a == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), 1));
	else
		return (0);
}

/*	writes in the console arguments aerted to specific types 
	based on specifiers following '%' and returns the number 
	of bytes printed
*/

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
			printed_bytes += ft_conversion_specifier(&str[i + 1], ap);
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
