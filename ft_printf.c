/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:03:34 by iidzim            #+#    #+#             */
/*   Updated: 2019/11/20 15:14:52 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init(t_flags *flg)
{
	flg->align = 0;
	flg->width = 0;
	flg->zero = 0;
	flg->prec = -1;
}

void		ft_check(int *i, va_list args, char *str, t_flags flg)
{
	if (str[*i] == 'd' || str[*i] == 'i')
		ft_convert_d(args, flg);
	if (str[*i] == 'u')
		ft_convert_u(args, flg);
	if (str[*i] == 'x' || str[*i] == 'X')
		ft_convert_hexa(args, flg, str[*i]);
	if (str[*i] == 'p')
		ft_convert_p(args, flg);
	if (str[*i] == 's')
		ft_convert_s(args, flg);
	if (str[*i] == 'c')
		ft_convert_c(args, flg);
	if (str[*i] == '%')
		ft_convert_per(flg);
}

int			ft_printf(const char *str, ...)
{
	va_list args;
	t_flags flg;
	int		i;

	i = -1;
	g_r = 0;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init(&flg);
			ft_more_flags(args, (char *)str, &i, &flg);
			ft_check(&i, args, (char *)str, flg);
		}
		else
			ft_putchar(str[i]);
	}
	va_end(args);
	return (g_r);
}
