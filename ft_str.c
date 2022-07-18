/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:31:53 by spatel            #+#    #+#             */
/*   Updated: 2022/07/18 17:41:57 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_str(char *str)
{
	int	bytes;

	bytes = 0;
	while (str)
	{
		write(1, &str, 1);
		str++;
		bytes++;
	}
	return (bytes);
}