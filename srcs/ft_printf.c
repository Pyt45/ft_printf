/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:58:48 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:06:10 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		flags_init(t_printf *var)
{
	ft_bzero(var->flags, sizeof(char) * 2);
	var->width = 0;
	var->valid = 0;
	var->prec = -1;
	var->nbr_len = 0;
	var->space = 0;
	var->zeros = 0;
	var->digit = 0;
	var->hex = NULL;
	var->ptr = 0;
	var->uns = 0;
	var->negative = 0;
	var->position = 0;
	var->type = 0;
}

static void		ft_arg_found(char **fmt, t_printf *var)
{
	flags_init(var);
	ft_add_flags(fmt, var);
	ft_add_width(fmt, var);
	ft_add_prec(fmt, var);
	if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' ||
		**fmt == 'd' || **fmt == 'i' || **fmt == 'u' ||
		**fmt == 'x' || **fmt == 'X' || **fmt == '%')
	{
		var->type = **fmt;
	}
	(var->type == 'c') ? handle_char(var) : 0;
	(var->type == 's') ? handle_str(var) : 0;
	(var->type == 'p') ? handle_adr(var) : 0;
	(var->type == 'x' || var->type == 'X') ? handle_hex(var) : 0;
	(var->type == 'u') ? handle_uns(var) : 0;
	(var->type == 'd' || var->type == 'i') ? handle_digit(var) : 0;
	(var->type == '%') ? handle_proc(var) : 0;
}

int				ft_printf(const char *fmt, ...)
{
	t_printf	var;

	va_start(var.ap, fmt);
	var.total = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_arg_found((char **)&fmt, &var);
		}
		else
			ft_putchar(*fmt, &var);
		fmt++;
	}
	va_end(var.ap);
	return (var.total);
}
