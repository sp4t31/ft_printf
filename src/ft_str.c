/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:31:53 by spatel            #+#    #+#             */
/*   Updated: 2022/07/28 18:12:31 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*	prints char or string type
*/

int	ft_str(char *str)
{
	int	printed_bytes;

	printed_bytes = 0;
	while (*str)
	{
		write(1, &str, 1);
		str++;
		printed_bytes++;
	}
	return (printed_bytes);
}
