/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:16:33 by spatel            #+#    #+#             */
/*   Updated: 2022/08/01 16:26:17 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	print unsigned int in hexadecimal 
	a == 'x' || a == 'p'  |  lowercase format '7b3fe'
	a == 'X'			  |  uppercase format '7B3FE'

	can void ptr be printed? 
	ft_conv... calls with &n
*/

void	ft_putnbr_hex(unsigned int n, char a)
{
	if (n > 15)
	{
		ft_putnbr(n / 16);
		ft_putnbr(n % 16);
	}
	else
	{
		if (n > 9 && (a == 'x' || a == 'p'))
			ft_putchar(n % 16 + 87);
		if (n > 9 && a == 'X')
			ft_putchar(n % 16 + 55);
		else if (n <= 9)
			ft_putchar(n + '0');
	}
}
