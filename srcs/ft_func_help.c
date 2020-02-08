/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:30:22 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:55:25 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char ch, t_printf *var)
{
	write(1, &ch, 1);
	var->total += 1;
}

void	ft_putstr(char *str, t_printf *var)
{
	while (*str != '\0')
	{
		ft_putchar(*str, var);
		str++;
	}
}

void	ft_print_flag(int q, char ch, t_printf *var)
{
	while (q > 0)
	{
		ft_putchar(ch, var);
		q--;
	}
}

void	ft_putnstr(const char *str, int len, t_printf *var)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], var);
		i++;
		if (i == len)
			break ;
	}
}
