/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:16:33 by spatel            #+#    #+#             */
/*   Updated: 2022/08/01 16:26:17 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	print unsigned int in hexadecimal 
	a == 'x'	|  lowercase format '7b3fe'
	a == 'X'	|  uppercase format '7B3FE'
	a == 'p'	|  memory location '0x7ff683844003'
*/

void	ft_print_nbr(long long int n, char a, int base)
{
	if (a == 'p')
	{
		write(1, "0x", 2);
		return (ft_print_nbr(n, 'x', 16));
	}
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_print_nbr(-n, a, base));
	}
	if (n >= base)
	{
		ft_print_nbr(n / base, a, base);
		ft_print_nbr(n % base, a, base);
	}
	else
	{
		if (n > 9 && (a == 'x' || a == 'p'))
			ft_putchar((int)n % 16 + 87);
		else if (n > 9 && a == 'X')
			ft_putchar((int)n % 16 + 55);
		else
			ft_putchar((int)n + '0');
	}
}
