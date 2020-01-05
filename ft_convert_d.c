/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 09:42:17 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 14:03:23 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertd_noflg(t_flags flg)
{
	int espace;

	espace = flg.width;
	while (espace-- > 0)
		ft_putchar(' ');
}

void	ft_convertd_wp(t_flags flg, int n, int len)
{
	int zero;

	zero = flg.prec - len;
	if (n >= 0)
		ft_convertd_wp_positif(flg, zero, n);
	else
		ft_convertd_wp_neg(flg, zero, n);
}

void	ft_convertd_w_noalign(int espace, int n, t_flags flg)
{
	int len;

	len = ft_size_nbr(n);
	if (flg.zero == 0 && flg.prec <= len && flg.prec >= 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
	}
	if (flg.zero == 1 && flg.prec == -1)
		ft_convertd_w_noalign_posneg(espace, n);
	else
	{
		while (espace-- > 0)
			ft_putchar(' ');
		ft_putnbr_minus(n);
	}
}

void	ft_convertd_w(t_flags flg, int n, int len)
{
	int espace;

	if (n == 0 && flg.prec == 0)
		ft_convertd_noflg(flg);
	else
	{
		if (n >= 0)
			espace = flg.width - len;
		else
			espace = flg.width - len - 1;
		if (flg.align == 0)
			ft_convertd_w_noalign(espace, n, flg);
		else
		{
			ft_putnbr_minus(n);
			while (espace-- > 0)
				ft_putchar(' ');
		}
	}
}

void	ft_convert_d(va_list args, t_flags flg)
{
	int	n;
	int	len;
	int	zero;

	n = va_arg(args, int);
	len = ft_size_nbr(n);
	if ((flg.width == 0 || flg.width < len) && (flg.prec == -1 ||
				flg.prec <= len))
	{
		if (flg.zero == 0 && flg.align == 0)
			(n == 0 && flg.prec == 0) ? ft_convertd_noflg(flg) :
				ft_putnbr_minus(n);
		else
			ft_putnbr_minus(n);
	}
	flg.width >= len && flg.prec >= len ? ft_convertd_wp(flg, n, len) : 0;
	flg.width >= len && flg.prec < len ? ft_convertd_w(flg, n, len) : 0;
	if (flg.width < len && flg.prec > len)
	{
		zero = flg.prec - len;
		(n < 0) ? ft_putchar('-') : 0;
		while (zero-- > 0)
			ft_putchar('0');
		ft_putnbr(n);
	}
}
