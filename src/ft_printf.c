/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:03:04 by spatel            #+#    #+#             */
/*   Updated: 2022/08/07 22:01:41 by spatel           ###   ########.fr       */
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

int	ft_index(char a, va_list ap)
{
	size_t	store_arg;
	size_t	base;

	if (a == '%')
		return (ft_putchar('%'));
	else if (a == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (a == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (a == 'd' || a == 'i' || a == 'u' || a == 'x'
		|| a == 'X' || a == 'p')
	{
		store_arg = va_arg(ap, size_t);
		if (a == 'd' || a == 'i' || a == 'u')
			base = 10;
		else
			base = 16;
		ft_print_nbr(store_arg, a, base);
		return (ft_calculate_bytes(store_arg, a, base));
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
	int		i;
	int		printed_bytes;
	va_list	ap;

	i = 0;
	printed_bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i]) == '%' && (str[i + 1] != '%' ||
		if (str[i] == '%' && str[i + 1])
			printed_bytes += ft_index(str[++i], ap);
		else if (str[i] && str[i] != '%')
			printed_bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (printed_bytes);
}

/*
int	main(void)
{
	printf("\n%i\n", ft_printf("%i %u %d", -10, -10, -10));
	printf("\n%i\n", printf("%i %u %d", -10, -10, -10));
}*/
