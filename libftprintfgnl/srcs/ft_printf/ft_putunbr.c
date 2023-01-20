/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:37:34 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/25 00:41:11 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putunbr(unsigned int n, int i)
{
	unsigned int	nb;

	nb = n;
	if (n > 9)
		i = putunbr(n / 10, i);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (putunbr(n * -1, 1));
	}
	return (putunbr(n, 0));
}
