/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 06:16:26 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 15:15:22 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertu_noflg(t_flags flg)
{
	int espace;

	espace = flg.width;
	while (espace-- > 0)
		ft_putchar(' ');
}

void	ft_convertu_wp(t_flags flg, unsigned int n, int len)
{
	int espace;
	int zero;

	espace = flg.width - flg.prec;
	zero = flg.prec - len;
	if (flg.align == 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
		while (zero-- > 0)
			ft_putchar('0');
		ft_putunsign(n);
	}
	else
	{
		while (zero-- > 0)
			ft_putchar('0');
		ft_putunsign(n);
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convertu_w(t_flags flg, unsigned int n, int len)
{
	int espace;

	if (n == 0 && flg.prec == 0)
		ft_convertu_noflg(flg);
	else
	{
		espace = flg.width - len;
		if (flg.align == 0)
		{
			ft_convertx_w_noalign(espace, len, flg);
			ft_putunsign(n);
		}
		else
		{
			ft_putunsign(n);
			while (espace-- > 0)
				ft_putchar(' ');
		}
	}
}

void	ft_convert_u(va_list args, t_flags flg)
{
	unsigned int	n;
	int				len;
	int				zero;

	n = va_arg(args, unsigned int);
	len = ft_size_unsig(n);
	if ((flg.width == 0 || flg.width < len) && (flg.prec == -1 ||
				flg.prec < len))
	{
		if (flg.align == 0 && flg.zero == 0)
			(n == 0 && flg.prec == 0) ? ft_convertu_noflg(flg) :
				ft_putunsign(n);
		else
			ft_putunsign(n);
	}
	(flg.width >= len && flg.prec >= len) ? ft_convertu_wp(flg, n, len) : 0;
	(flg.width >= len && flg.prec < len) ? ft_convertu_w(flg, n, len) : 0;
	if (flg.width < len && flg.prec >= len)
	{
		zero = flg.prec - len;
		while (zero-- > 0)
			ft_putchar('0');
		ft_putunsign(n);
	}
}
