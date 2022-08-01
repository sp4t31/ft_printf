/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:03:04 by spatel            #+#    #+#             */
/*   Updated: 2022/08/01 16:29:56 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
-- error checking
-- hex void pointer
-- write return
-- write percentage error
-- can convert char to *char? double on them
-- passing & to not create duplicate variables?
*/


int	ft_conversion_specifier(char a, va_list ap)
{
	unsigned int	store_arg;

	if (a == 'c' || a == 's')
		return (ft_str(va_arg(ap, char*)));
	else if (a == 'd' || a == 'i' || a == 'u')
	{
		store_arg = va_arg(ap, long long int);
		ft_putnbr(store_arg);
		return (ft_calculate_bytes(store_arg, a, 10));
	}
	else if (a == 'x' || a == 'X' || a == 'p')
	{
		store_arg = va_arg(ap, unsigned int);
		ft_putnbr_hex(store_arg, a);
		return (ft_calculate_bytes(store_arg, a, 16));
	}
	else
		return (0);
}

/*	writes in the console arguments aerted to specific types 
	based on specifiers following '%' and returns the number 
	of bytes printed
*/

int	ft_printf(const char *str, ...)
{
	int	i;
	int	printed_bytes;
	va_list	ap;

	i = 0;
	printed_bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			printed_bytes += ft_putchar('%');
			i++;
		}
		else if (str[i] == '%')
			printed_bytes += ft_conversion_specifier(str[i + 1], ap);
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
