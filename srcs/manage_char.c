/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:18:42 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 14:50:07 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		c_with_flags(char ch, t_printf *var)
{
	if (var->width > 0)
	{
		ft_print_flag(var->width - 1, ' ', var);
		ft_putchar(ch, var);
	}
	else if (var->width < 0 && var->valid == 1)
	{
		ft_putchar(ch, var);
		ft_print_flag(-(var->width) - 1, ' ', var);
	}
}

static void		ft_char_help(char ch, t_printf *var)
{
	if (var->width >= 0)
	{
		ft_print_flag(var->width - 1, '0', var);
		ft_putchar(ch, var);
	}
	else if (var->valid == 1)
	{
		ft_putchar(ch, var);
		ft_print_flag(-var->width - 1, ' ', var);
	}
}

void			handle_char(t_printf *var)
{
	char	ch;

	ch = (char)va_arg(var->ap, int);
	if (var->width != 0)
	{
		if (var->flags[1] == '-')
		{
			ft_putchar(ch, var);
			ft_print_flag(var->width - 1, ' ', var);
		}
		else if (var->flags[0] == '0')
			ft_char_help(ch, var);
		else
			c_with_flags(ch, var);
	}
	else
		ft_putchar(ch, var);
}
