/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:37:34 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/24 22:39:45 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putnbr_base(unsigned long long n, char *base,
		unsigned long long size, int i)
{
	unsigned long long	nb;

	nb = n;
	if (n >= size)
		i = putnbr_base(n / size, base, size, i);
	i += ft_putchar(base[nb % size]);
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char *base, int nb)
{
	if (n < 0)
		return (putnbr_base(n * -1, base, nb, 0) + 1);
	return (putnbr_base(n, base, nb, 0));
}
