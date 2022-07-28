/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:16:33 by spatel            #+#    #+#             */
/*   Updated: 2022/07/28 18:11:41 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	print unsigned int in hexadecimal 
	a == 'x' || a == 'p'  |  lowercase format '7b3fe'
	a == 'X'			  |  uppercase format '7B3FE'

	can void ptr be printed? 
	ft_conv... calls with &n
*/

void	ft_putnbr_hex(void *n, char a)
{
	if (n > 15)
	{
		ft_putnbr(n / 16);
		ft_putnbr(n % 16);
	}
	else
	{
		if (n > 9 && (a == 'x' || a == 'p'))
			write(1, n % 16 + 87, 1);
		if (n > 9 && a == 'X')
			write(1, n % 16 + 55, 1);
		else if (n <= 9)
			write(1, n + '0', 1);
	}
}
