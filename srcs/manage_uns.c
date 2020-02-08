/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:40:14 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:53:55 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putnbr_u(unsigned long n, t_printf *var)
{
	long long	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10, var);
		ft_putnbr_u(nbr % 10, var);
	}
	else
		ft_putchar(nbr + '0', var);
}

static int		ft_nbr_len_u(t_printf *var)
{
	long long	d;
	long long	l;
	int			len;

	l = var->uns;
	len = (l == 0) ? 1 : 0;
	d = l;
	while (d > 0)
	{
		d /= 10;
		len++;
	}
	return (len);
}

static void		uns_flag(t_printf *var)
{
	var->zeros = var->prec - var->nbr_len;
	if (var->zeros < 0)
		var->zeros = 0;
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && var->uns == 0))
		ft_putnbr_u(var->uns, var);
	var->width = (var->width < 0) ? -var->width : var->width;
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !var->uns) ? ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
}

static void		uns_no_flag(t_printf *var)
{
	var->space = var->width - (var->zeros + var->nbr_len);
	(!var->prec && !var->uns) ? ft_print_flag(var->space + 1, ' ', var) :
	ft_print_flag(var->space, ' ', var);
	ft_print_flag(var->zeros, '0', var);
	if (!(var->prec == 0 && var->uns == 0))
	{
		ft_putnbr_u(var->uns, var);
		if (var->valid == 1 && var->width < 0)
		{
			var->width = -var->width;
			var->space = var->width - (var->zeros + var->nbr_len);
			ft_print_flag(var->space, ' ', var);
		}
	}
	else if (var->valid == 1 && var->width < 0)
	{
		var->width = -var->width;
		(!(var->prec == 0 && var->uns == 0)) ? ft_putnbr_u(var->uns, var) : 0;
		(var->uns > 0) ?
		(var->space = var->width - (var->zeros + var->nbr_len)) :
		(var->space = var->width - var->zeros);
		var->space = var->width - (var->zeros + var->nbr_len);
		(var->prec <= 0) ? ft_print_flag(var->space, ' ', var) :
		ft_print_flag(var->space - 2, ' ', var);
	}
}

void			handle_uns(t_printf *var)
{
	var->uns = va_arg(var->ap, unsigned int);
	var->nbr_len = ft_nbr_len_u(var);
	if (var->flags[1] == '-')
		uns_flag(var);
	else if (var->flags[0] == '0' && var->prec == -1)
	{
		var->zeros = var->width - var->nbr_len;
		ft_print_flag(var->zeros, '0', var);
		ft_putnbr_u(var->uns, var);
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
		uns_no_flag(var);
	}
}
