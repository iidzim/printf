/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:22:53 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 18:07:59 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_r++;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_convert_c(va_list args, t_flags flg)
{
	char	c;
	int		w;

	c = va_arg(args, int);
	w = flg.width - 1;
	if (flg.align == 0)
	{
		while (w-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		while (w-- > 0)
			ft_putchar(' ');
	}
}

void	ft_convert_per(t_flags flg)
{
	int w;

	w = flg.width - 1;
	if (flg.align == 0)
	{
		if (flg.zero == 0)
		{
			while (w-- > 0)
				ft_putchar(' ');
		}
		else
		{
			while (w-- > 0)
				ft_putchar('0');
		}
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		while (w-- > 0)
			ft_putchar(' ');
	}
}
