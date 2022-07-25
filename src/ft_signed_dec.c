/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:20:58 by spatel            #+#    #+#             */
/*   Updated: 2022/07/22 17:06:24 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*	conversion to int type
*/

int	ft_signed_dec(int d);
{
	int	printed_bytes;

	if (d)
	{
		//write int d
		ft_putnbr(int d);
		//calculate no.bytes printed
		printed_bytes = 0;
		if (d <= 0)
			printed_bytes++;
		while (d != 0)
		{
			d /= 10;
			printed_bytes++;
		}
		return (printed_bytes);
	}
	return (0);
}
