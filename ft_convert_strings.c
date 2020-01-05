/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:02:04 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 18:19:14 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converts_pw_noalign(t_flags flg, char *s, int espace)
{
	int i;

	i = 0;
	while (espace-- > 0)
		ft_putchar(' ');
	while (flg.prec-- > 0 && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_converts_pw(char *s, int size, t_flags flg)
{
	int		i;
	int		p;
	int		espace;

	i = 0;
	p = flg.prec;
	if (p > size)
		espace = flg.width - size;
	else
		espace = flg.width - flg.prec;
	if (flg.align == 1)
	{
		while (p-- > 0 && s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
		while (espace-- > 0)
			ft_putchar(' ');
	}
	else
		ft_converts_pw_noalign(flg, s, espace);
}

void	ft_converts_w(char *s, int size, t_flags flg)
{
	int espace;

	espace = flg.width - size;
	if (flg.align == 0)
	{
		while (espace-- > 0)
			ft_putchar(' ');
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		while (espace-- > 0)
			ft_putchar(' ');
	}
}

void	ft_converts_p(char *s, int size, t_flags flg)
{
	int		i;
	int		space;

	i = 0;
	space = flg.width - flg.prec;
	if (flg.prec > size)
		ft_putstr(s);
	else
	{
		if (flg.align == 0)
		{
			while (space-- > 0)
				ft_putchar(' ');
			while (flg.prec-- > 0)
				ft_putchar(s[i++]);
		}
		else
		{
			while (flg.prec-- > 0)
				ft_putchar(s[i++]);
			while (space-- > 0)
				ft_putchar(' ');
		}
	}
}

void	ft_convert_s(va_list args, t_flags flg)
{
	char	*s;
	int		size;

	s = va_arg(args, char*);
	s = (s == NULL) ? "(null)" : s;
	size = ft_strlen((char *)s);
	if (flg.width <= size && (flg.prec >= size || flg.prec == -1))
	{
		ft_putstr(s);
		return ;
	}
	if (flg.width > size && (flg.prec < size && flg.prec != -1))
		ft_converts_pw(s, size, flg);
	if (flg.width > size && (flg.prec >= size || flg.prec == -1))
		ft_converts_w(s, size, flg);
	if (flg.width <= size && (flg.prec < size || flg.prec != -1))
		ft_converts_p(s, size, flg);
}
