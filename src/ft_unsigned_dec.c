/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:25:56 by spatel            #+#    #+#             */
/*   Updated: 2022/07/22 17:08:00 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_unsigned_dec(unsigned int u);
{
	int	printed_bytes;
	
	if (u)
	{
		//write unsigned int n
		ft_putnbr(unsigned int n);
		//calculate no.bytes printed
		printed_bytes = 0;
		if (u = 0)
			printed_bytes++;
		while (u != 0)
		{
			u /= 10;
			printed_bytes++;
		}
		return (printed_bytes);
	}
	return (0);
}
