/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:45:52 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 14:55:31 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_addr_flag(char *str, t_printf *var)
{
	var->zeros = var->prec - var->nbr_len;
	(!var->prec && !ft_strcmp(str, "0")) ?
	(var->zeros = var->prec - (var->nbr_len - 1)) :
	(var->zeros = var->prec - (var->nbr_len + 2));
	(var->zeros < 0) ? (var->zeros = 0) : 0;
	ft_putstr("0x", var);
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && !ft_strcmp(str + 2, "0")))
		ft_putstr(str + 2, var);
	var->width = (var->width < 0) ? -var->width : var->width;
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !ft_strcmp(str, "0")) ?
	ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
}

static void	ft_help_flag(char *str, t_printf *var)
{
	var->width = -var->width;
	if (!(var->prec == 0 && !ft_strcmp(str + 2, "0")))
		ft_putstr(str, var);
	(ft_strcmp(str, "0")) ?
	(var->space = var->width - (var->zeros + var->nbr_len)) :
	(var->space = var->width - var->zeros);
	(var->prec <= 0) ? ft_print_flag(var->space, ' ', var) :
	ft_print_flag(var->space - 2, ' ', var);
}

static void	adr_no_flag(char *str, t_printf *var)
{
	(!var->prec && !ft_strcmp(str + 2, "0")) ?
	(var->space = var->width - (var->zeros + var->nbr_len - 1)) :
	(var->space = var->width - (var->zeros + var->nbr_len));
	ft_print_flag(var->space, ' ', var);
	ft_putstr("0x", var);
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && !ft_strcmp(str + 2, "0")))
	{
		ft_putstr(str + 2, var);
		if (var->valid && var->width < 0)
		{
			var->width = -var->width;
			var->space = var->width - (var->zeros + var->nbr_len);
			ft_print_flag(var->space, ' ', var);
		}
	}
	else if (var->valid == 1 && var->width < 0)
		ft_help_flag(str, var);
}

static void	ft_help_adr(char *str, t_printf *var)
{
	var->zeros = var->prec - (var->nbr_len - 2);
	if (var->flags[0] == '0' && var->prec < 0)
		var->zeros = var->width - var->nbr_len;
	(var->zeros < 0) ? (var->zeros = 0) : 0;
	adr_no_flag(str, var);
}

void		handle_adr(t_printf *var)
{
	char	*ptr;

	ft_print_address(&ptr, var);
	var->nbr_len = ft_strlen(ptr);
	if (var->flags[1] == '-')
		ft_addr_flag(ptr, var);
	else if (var->flags[0] == '0' && var->prec == -1)
	{
		var->zeros = var->width - var->nbr_len;
		ft_putstr("0x", var);
		ft_print_flag(var->zeros, '0', var);
		ft_putstr(ptr + 2, var);
		if (var->valid == 1)
		{
			var->space = -var->width - var->nbr_len;
			ft_print_flag(var->space, ' ', var);
		}
	}
	else
		ft_help_adr(ptr, var);
}
