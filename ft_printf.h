/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:17:46 by iidzim            #+#    #+#             */
/*   Updated: 2019/12/27 18:50:35 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int g_r;
typedef struct	s_flags
{
	int zero;
	int align;
	int width;
	int prec;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_more_flags(va_list args, char *str, int *i, t_flags *flg);
void			ft_convert_c(va_list args, t_flags flg);
void			ft_convert_per(t_flags flg);
void			ft_convert_s(va_list args, t_flags flg);
int				ft_convert_p(va_list args, t_flags flg);
void			ft_convert_hexa(va_list args, t_flags flg, char x);
void			ft_convertx_w_noalign(int espace, int len, t_flags flg);
void			ft_convert_u(va_list args, t_flags flg);
void			ft_convert_d(va_list args, t_flags flg);
void			ft_convertd_w_noalign_posneg(int espace, int n);
void			ft_convertd_wp_neg(t_flags flg, int zero, int n);
void			ft_convertd_wp_positif(t_flags flg, int zero, int n);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strlen(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr_minus(int n);
void			ft_putnbr(int n);
void			ft_putunsign(unsigned int i);
void			ft_address(size_t n);
void			ft_hexa(unsigned int n, char c);
char			*ft_strchr(const char *str, int c);
int				ft_size_nbr(int n);
int				ft_size_unsig(unsigned int n);
int				ft_size_hexa(size_t n);

#endif
