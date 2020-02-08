/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:52:44 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/16 12:12:17 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_flags(char **fmt, t_printf *var)
{
	while (1)
	{
		if (**fmt == '0')
			var->flags[0] = **fmt;
		else if (**fmt == '-')
			var->flags[1] = **fmt;
		else
			break ;
		++*fmt;
	}
}

void	ft_add_width(char **fmt, t_printf *var)
{
	if ((var->width = ft_atoi(*fmt)))
		while (ft_isdigit(**fmt))
			++*fmt;
	else if (**fmt == '*')
	{
		var->width = va_arg(var->ap, int);
		if (var->width < 0)
			var->valid = 1;
		++*fmt;
	}
}

void	ft_add_prec(char **fmt, t_printf *var)
{
	if (**fmt == '.')
	{
		++*fmt;
		while (**fmt == '-' || **fmt == '0' || **fmt == '.')
			++*fmt;
		if ((var->prec = ft_atoi(*fmt)))
			while (ft_isdigit(**fmt))
				++*fmt;
		else if (**fmt == '*')
		{
			var->prec = va_arg(var->ap, int);
			++*fmt;
		}
		else if (**fmt == '0')
		{
			var->prec = 0;
			++*fmt;
		}
		else
			var->prec = 0;
	}
}
