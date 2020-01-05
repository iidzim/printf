/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:35:50 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 16:04:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_minus(int n)
{
	unsigned int i;

	if (n >= 0)
		i = n;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * (-1);
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n >= 0)
		i = n;
	if (n < 0)
		i = n * (-1);
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void	ft_putunsign(unsigned int i)
{
	if (i >= 10)
	{
		ft_putunsign(i / 10);
		ft_putunsign(i % 10);
	}
	else
		ft_putchar(i + '0');
}

void	ft_address(size_t n)
{
	if (n > 15)
	{
		ft_address(n / 16);
		ft_address(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 87);
}

void	ft_hexa(unsigned int n, char c)
{
	if (n > 15)
	{
		ft_hexa((n / 16), c);
		ft_hexa((n % 16), c);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + c - 33);
}
