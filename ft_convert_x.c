/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:31:11 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 15:51:24 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertx_noflg(t_flags flg)
{
	int p;

	p = flg.prec;
	if (flg.prec == 0)
	{
		while (flg.width-- > 0)
			ft_putchar(' ');
	}
	else if (flg.prec > 0)
	{
		while (p-- > 0)
			ft_putchar('0');
	}
	else if (flg.prec < 0)
		ft_putchar('0');
}

void	ft_convertx_w_noalign(int espace, int len, t_flags flg)
{
	if (flg.zero == 0 && flg.prec <= len && flg.prec >= 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
	}
	if (flg.zero == 1 && flg.prec == -1)
	{
		while (espace-- > 0)
			ft_putchar('0');
	}
	else
	{
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convertx_w(t_flags flg, unsigned int n, char x)
{
	int espace;
	int len;

	len = ft_size_hexa(n);
	if (n == 0 && flg.prec == 0)
	{
		espace = flg.width;
		while (espace-- > 0)
			ft_putchar(' ');
	}
	else
	{
		espace = flg.width - len;
		if (flg.align == 0)
		{
			ft_convertx_w_noalign(espace, len, flg);
			ft_hexa(n, x);
		}
		else
		{
			ft_hexa(n, x);
			while (espace-- > 0)
				ft_putchar(' ');
		}
	}
}

void	ft_convertx_wp(t_flags flg, unsigned int n, char x)
{
	int espace;
	int zero;
	int len;

	len = ft_size_hexa(n);
	zero = flg.prec - len;
	espace = flg.width - flg.prec < 0 ? 0 : flg.width - flg.prec;
	if (flg.align == 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
		while (zero-- > 0)
			ft_putchar('0');
		ft_hexa(n, x);
	}
	else
	{
		while (zero-- > 0)
			ft_putchar('0');
		ft_hexa(n, x);
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convert_hexa(va_list args, t_flags flg, char x)
{
	unsigned int	n;
	int				espace;
	int				len;

	n = va_arg(args, unsigned int);
	len = ft_size_hexa(n);
	if ((flg.prec == -1 || flg.prec <= len) && (flg.width == 0 ||
				flg.width <= len))
	{
		if (flg.align == 0 && flg.zero == 0)
			(n == 0) ? ft_convertx_noflg(flg) : ft_hexa(n, x);
		else
			ft_hexa(n, x);
	}
	else if (flg.prec >= len && flg.width <= len)
	{
		espace = flg.prec - len;
		while (espace-- > 0)
			ft_putchar('0');
		ft_hexa(n, x);
	}
	if (flg.width > len && flg.prec >= len)
		ft_convertx_wp(flg, n, x);
	if (flg.width > len && flg.prec <= len)
		ft_convertx_w(flg, n, x);
}
