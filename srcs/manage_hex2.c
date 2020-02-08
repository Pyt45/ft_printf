/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hex2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:36:00 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:51:21 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_print_hex2(unsigned int n, char c, int opt)
{
	static char str[18];
	static int	i;

	i = 0;
	(!opt) ? ft_bzero(str, 18) : 0;
	if (n / 16)
		ft_print_hex2(n / 16, c, 1);
	str[i++] = ft_check_char(n % 16, c);
	return (str);
}

static void		hex_flag(t_printf *var)
{
	var->zeros = var->prec - var->nbr_len;
	if (var->zeros < 0)
		var->zeros = 0;
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && !ft_strcmp(var->hex, "0")))
		ft_putstr(var->hex, var);
	var->width = (var->width < 0) ? -var->width : var->width;
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !ft_strcmp(var->hex, "0")) ?
	ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
}

static void		ft_hex_help(t_printf *var)
{
	var->width = -var->width;
	if (!(var->prec == 0 && !ft_strcmp(var->hex, "0")))
		ft_putstr(var->hex, var);
	(ft_strcmp(var->hex, "0")) ?
	(var->space = var->width - (var->zeros + var->nbr_len)) :
	(var->space = var->width - var->zeros);
	(var->prec <= 0) ? ft_print_flag(var->space, ' ', var) :
	ft_print_flag(var->space - 2, ' ', var);
}

static void		hex_no_flag(t_printf *var)
{
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !ft_strcmp(var->hex, "0")) ?
	ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && !ft_strcmp(var->hex, "0")))
	{
		ft_putstr(var->hex, var);
		if (var->valid == 1 && var->width < 0)
		{
			var->width = -var->width;
			var->space = var->width - (var->zeros + var->nbr_len);
			ft_print_flag(var->space, ' ', var);
		}
	}
	else if (var->valid == 1 && var->width < 0)
		ft_hex_help(var);
}

void			handle_hex(t_printf *var)
{
	var->digit = va_arg(var->ap, int);
	var->hex = ft_print_hex2(var->digit, var->type, 0);
	var->nbr_len = ft_strlen(var->hex);
	if (var->flags[1] == '-')
		hex_flag(var);
	else if (var->flags[0] == '0' && var->prec == -1)
	{
		var->zeros = var->width - var->nbr_len;
		ft_print_flag(var->zeros, '0', var);
		ft_putstr(var->hex, var);
		if (var->valid == 1)
		{
			var->space = -var->width - var->nbr_len;
			ft_print_flag(var->space, ' ', var);
		}
	}
	else
	{
		var->zeros = var->prec - var->nbr_len;
		if (var->flags[0] == '0' && var->prec < 0)
			var->zeros = var->width - var->nbr_len;
		if (var->zeros < 0)
			var->zeros = 0;
		hex_no_flag(var);
	}
}
