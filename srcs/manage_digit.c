/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:21:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/19 13:39:06 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_nbr_len(t_printf *var)
{
	long long	d;
	long long	l;
	int			len;

	l = var->digit;
	len = (l == 0) ? 1 : 0;
	if (l < 0)
	{
		l *= -1;
		var->width -= 1;
		(var->flags[1] == '-') ? var->position = -1 : 0;
		var->negative = 1;
	}
	d = l;
	while (d > 0)
	{
		d /= 10;
		len++;
	}
	return (len);
}

void			ft_putnbr(int n, t_printf *var)
{
	long int nbr;

	nbr = n;
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, var);
		ft_putnbr(nbr % 10, var);
	}
	else
		ft_putchar(nbr + '0', var);
}

static void		digit_flag(t_printf *var)
{
	var->zeros = var->prec - var->nbr_len;
	if (var->zeros < 0)
		var->zeros = 0;
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && var->digit == 0))
		ft_putnbr(var->digit, var);
	var->width = (var->width < 0) ? -var->width : var->width;
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !var->digit) ? ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
}

void			digit_no_flag(t_printf *var)
{
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !var->digit) ? ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
	if (var->negative == 1)
		ft_putchar('-', var);
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && var->digit == 0))
	{
		if (var->negative == 1 && var->position == -1)
			ft_putchar('-', var);
		ft_putnbr(var->digit, var);
		if (var->valid == 1 && var->width < 0)
		{
			var->width = -var->width;
			(var->negative == 1) ?
			(var->space = var->width - (var->zeros + var->nbr_len + 2)) :
			(var->space = var->width - (var->zeros + var->nbr_len));
			ft_print_flag(var->space, ' ', var);
		}
	}
	else if (var->valid == 1 && var->width < 0)
		ft_digit_help2(var);
}

void			handle_digit(t_printf *var)
{
	var->digit = va_arg(var->ap, int);
	var->nbr_len = ft_nbr_len(var);
	if (var->negative == 1 && var->position == -1)
		ft_putchar('-', var);
	if (var->flags[1] == '-')
	{
		(var->negative == 1 && var->valid == 1) ? (var->width += 2) : 0;
		digit_flag(var);
	}
	else if (var->flags[0] == '0' && var->prec == -1)
	{
		var->zeros = var->width - var->nbr_len;
		(var->negative == 1) ? ft_putchar('-', var) : 0;
		(var->negative == 1 && var->valid == 1) ? (var->width += 2) : 0;
		ft_print_flag(var->zeros, '0', var);
		ft_putnbr(var->digit, var);
		if (var->valid == 1)
		{
			var->space = -var->width - var->nbr_len;
			ft_print_flag(var->space, ' ', var);
		}
	}
	else
		ft_digit_help(var);
}
