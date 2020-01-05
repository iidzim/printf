/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 00:57:25 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 12:28:53 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertp_w(t_flags flg, size_t p, int size)
{
	int espace;

	espace = flg.width - size - 2;
	if (flg.align == 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_address(p);
	}
	else
	{
		ft_putstr("0x");
		ft_address(p);
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convertp_cas1(t_flags flg)
{
	int espace;

	espace = flg.width - 2;
	if (flg.align == 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
	}
	else
	{
		ft_putstr("0x");
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convertp_cas2(t_flags flg, int size, size_t p)
{
	int		zero;

	if (flg.width > size)
		ft_convertp_w(flg, p, size);
	else if (flg.width <= size && flg.prec == -1 && flg.zero == 0)
	{
		ft_putstr("0x");
		ft_address(p);
	}
	else if ((flg.prec <= size || flg.prec != -1) && flg.width < size)
	{
		zero = flg.prec - size;
		ft_putstr("0x");
		while (zero-- > 0)
			ft_putchar('0');
		ft_address(p);
	}
}

int		ft_convert_p(va_list args, t_flags flg)
{
	size_t	p;
	int		espace;
	int		size;

	p = (size_t)va_arg(args, void *);
	size = ft_size_hexa(p);
	espace = flg.width - 2;
	if (p == 0 && flg.prec == 0)
	{
		ft_convertp_cas1(flg);
		return (0);
	}
	if (flg.align == 0 && flg.zero == 0 && flg.prec == -1 &&
			(size > flg.width || flg.width == 0))
	{
		ft_putstr("0x");
		ft_address(p);
		return (0);
	}
	ft_convertp_cas2(flg, size, p);
	return (0);
}
