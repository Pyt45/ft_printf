/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:41:30 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/16 19:46:06 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	pro_no_flag(t_printf *var)
{
	if (var->width >= 0)
	{
		ft_print_flag(var->width - 1, ' ', var);
		ft_putchar('%', var);
	}
	else if (var->valid == 1)
	{
		ft_putchar('%', var);
		ft_print_flag(-var->width - 1, ' ', var);
	}
	else
		ft_putchar('%', var);
}

void		handle_proc(t_printf *var)
{
	if (var->flags[1] == '-')
	{
		ft_putchar('%', var);
		ft_print_flag(var->width - 1, ' ', var);
	}
	else if (var->flags[0] == '0')
	{
		ft_print_flag(var->width - 1, '0', var);
		ft_putchar('%', var);
	}
	else
		pro_no_flag(var);
}
