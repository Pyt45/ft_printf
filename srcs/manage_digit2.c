/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_digit2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:58:06 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/19 13:39:24 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_digit_help(t_printf *var)
{
	var->zeros = var->prec - var->nbr_len;
	if (var->flags[0] == '0' && var->prec < 0)
		var->zeros = var->width - var->nbr_len;
	(var->zeros < 0) ? (var->zeros = 0) : 0;
	digit_no_flag(var);
}

void	ft_digit_help2(t_printf *var)
{
	var->width = -var->width;
	if (!(var->prec == 0 && var->digit == 0))
	{
		if (var->negative == 1 && var->position == -1)
			ft_putchar('-', var);
		ft_putnbr(var->digit, var);
	}
	(!var->digit) ? (var->space = var->width - (var->zeros)) :
	(var->space = var->width - (var->zeros + var->nbr_len));
	(var->prec <= 0) ? ft_print_flag(var->space, ' ', var) :
	ft_print_flag(var->space - 2, ' ', var);
}
