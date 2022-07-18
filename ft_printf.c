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

int	conversion_specifier(const char *str, va_list ap)
{
	if (*str == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (*str == 's')
		return (ft_str(va_arg(ap, *char)));
	else if (*str == 'p')
		return (ft_void_ptr_hex(va_arg(ap, *void)));
	else if (*str == 'd' || *str == 'i')
		return (ft_signed_dec(va_arg(ap, double)));
	/*else if (*str == 'u')
		return (ft_unsint_unsdec(va_arg(ap, unsigned decimal?)));
	else if (*str == 'x')
		return (ft_unsint_unshex_lowercase(ap));
	else if (*str == 'X')
		return (ft_unsint_unshex_uppercase(ap));*/
	else 
		return(0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	return_bytes;
	va_list	ap;
	char	c;

	i = 0;
	c = '%';
	return_bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			return_bytes += write(1, &c, 1);
			i++;
		}
		else if (str[i] == '%')
			return_bytes += conversion_specifier(&str[i + 1], ap);
		else
			return_bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (return_bytes);
}

int	main(void)
{
	char*	str = "blah";
	char	b = 'B';
	char	c = 'C';
	ft_printf("%s %c %c", str , b , c);
}
