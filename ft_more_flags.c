/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:41:25 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 12:12:30 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int		signe;
	long	x;
	int		i;

	signe = 1;
	x = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		x = (x * 10) + ((char)str[i] - '0');
		if (x > 4294967296)
			return ((signe > 0) ? -1 : 0);
		i++;
	}
	return (x * signe);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_width_arg(t_flags *f, va_list arg, int i)
{
	i += 1;
	f->width = va_arg(arg, int);
	if (f->width < 0)
	{
		f->align = 1;
		f->width *= -1;
	}
}

void	ft_precision(char *str, t_flags *f, va_list args, int *i)
{
	*i += 1;
	if (!(ft_isdigit(str[*i])) && str[*i] != '*')
		f->prec = 0;
	if (ft_isdigit(str[*i]) || str[*i] == '-')
	{
		f->prec = ft_atoi(str + (*i));
		while (ft_isdigit(str[*i]))
			*i += 1;
	}
	else if (str[*i] == '*')
	{
		f->prec = va_arg(args, int);
		if (f->prec < 0)
			f->prec = -1;
		*i += 1;
	}
}

void	ft_more_flags(va_list args, char *str, int *i, t_flags *f)
{
	(*i)++;
	while (!(ft_strchr("cspduixX%%", str[*i])))
	{
		while (str[*i] == '-')
		{
			f->align = 1;
			*i += 1;
		}
		if (str[*i] == '0')
		{
			f->zero = 1;
			*i += 1;
		}
		if (ft_isdigit(str[*i]))
		{
			f->width = ft_atoi(str + (*i));
			*i += ft_size_nbr(f->width);
		}
		else if (str[*i] == '*')
		{
			ft_width_arg(f, args, *i);
			*i += 1;
		}
		(str[*i] == '.') ? ft_precision(str, f, args, i) : 0;
	}
}
