/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:45:16 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 14:21:00 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_zero(int n, int zero)
{
	while (zero-- > 0)
		ft_putchar('0');
	ft_putnbr(n);
}

void	ft_convertd_w_noalign_posneg(int espace, int n)
{
	if (n >= 0)
	{
		while (espace-- > 0)
			ft_putchar('0');
		ft_putnbr(n);
	}
	else
	{
		ft_putchar('-');
		while (espace-- > 0)
			ft_putchar('0');
		ft_putnbr(n);
	}
}

void	ft_convertd_wp_neg(t_flags flg, int zero, int n)
{
	int espace;

	if (flg.width > flg.prec)
	{
		espace = flg.width - flg.prec - 1;
		if (flg.align == 0)
		{
			while (espace-- > 0)
				ft_putchar(' ');
			ft_putchar('-');
			ft_print_zero(n, zero);
		}
		else if (flg.align == 1)
		{
			ft_putchar('-');
			ft_print_zero(n, zero);
			while (espace-- > 0)
				ft_putchar(' ');
		}
	}
	else
	{
		ft_putchar('-');
		ft_print_zero(n, zero);
	}
}

void	ft_convertd_wp_positif(t_flags flg, int zero, int n)
{
	int espace;

	if (flg.width > flg.prec)
	{
		espace = flg.width - flg.prec;
		if (flg.align == 0)
		{
			while (espace-- > 0)
				ft_putchar(' ');
			ft_print_zero(n, zero);
		}
		else if (flg.align == 1)
		{
			ft_print_zero(n, zero);
			while (espace-- > 0)
				ft_putchar(' ');
		}
	}
	else
		ft_print_zero(n, zero);
}
