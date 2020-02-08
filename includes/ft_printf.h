/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:40:04 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:57:58 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_printf
{
	int				width;
	char			flags[2];
	int				prec;
	char			type;
	int				valid;
	int				space;
	int				zeros;
	int				negative;
	va_list			ap;
	char			*hex;
	unsigned int	uns;
	unsigned long	ptr;
	int				position;
	int				digit;
	int				total;
	int				nbr_len;
}					t_printf;

void				ft_putchar(char ch, t_printf *var);
void				ft_putstr(char *str, t_printf *var);
void				ft_print_flag(int q, char ch, t_printf *var);
char				ft_check_char(long long n, char ch);
void				handle_char(t_printf *var);
void				handle_proc(t_printf *var);
void				handle_str(t_printf *var);
void				handle_hex(t_printf *var);
void				handle_adr(t_printf *var);
void				ft_print_address(char **adr, t_printf *var);
void				ft_add_flags(char **fmt, t_printf *var);
void				ft_add_width(char **fmt, t_printf *var);
void				ft_print_address(char **adr, t_printf *var);
void				ft_add_prec(char **fmt, t_printf *var);
void				ft_putnbr(int n, t_printf *var);
void				handle_digit(t_printf *var);
void				handle_uns(t_printf *var);
void				ft_digit_help(t_printf *var);
void				ft_digit_help2(t_printf *var);
void				digit_no_flag(t_printf *var);
int					ft_printf(const char *fmt, ...);
void				ft_putnstr(const char *str, int len, t_printf *var);
#endif
