/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:22:37 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/19 20:35:38 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	s_with_flag(char *str, t_printf *var)
{
	int		len;

	len = 0;
	if (var->prec == 0)
		str = "";
	else if (var->prec > 0)
		len = ft_strnlen(str, var->prec);
	else
		len = ft_strlen(str);
	ft_putnstr(str, var->prec, var);
	if (var->width >= 0)
		ft_print_flag(var->width - len, ' ', var);
	else if (var->width < 0)
		ft_print_flag(-(var->width) - len, ' ', var);
}

static void	ft_help_print(char *str, t_printf *var, int len)
{
	int		k;

	k = 0;
	(var->prec == 0) ? ft_print_flag(var->width, '0', var) : 0;
	(var->prec < 0) ? (var->prec = 0) : 0;
	var->zeros = var->width - (var->prec);
	(var->prec != 0) ? ft_print_flag(var->zeros, '0', var) : 0;
	ft_putnstr(str, len, var);
	(var->width < 0) ? (k = -var->width) : 0;
	if (var->prec <= (int)ft_strlen(str))
	{
		if (var->prec != 0)
			var->space = k - var->prec;
		else
			var->space = k - ft_strlen(str);
	}
	else
		var->space = k - ft_strlen(str);
	ft_print_flag(var->space, ' ', var);
}

static void	str_print(char *str, t_printf *var, int len)
{
	if (var->flags[0] != '0')
	{
		if (var->width >= 0)
		{
			if (var->prec == 0 && var->width != 0)
				ft_print_flag(var->width, ' ', var);
			else
				ft_print_flag(var->width - len, ' ', var);
			ft_putnstr(str, var->prec, var);
		}
		else if (var->width < 0 && var->valid == 1)
		{
			ft_putnstr(str, var->prec, var);
			if (var->prec == 0 && var->width != 0)
				ft_print_flag(-var->width, ' ', var);
			else
				ft_print_flag(-var->width - len, ' ', var);
		}
	}
	else
		ft_help_print(str, var, len);
}

static void	s_handle_warn_flag(char *str, t_printf *var)
{
	int		len;

	len = 0;
	if (var->prec == 0)
		str = "";
	else if (var->prec > 0)
		len = ft_strnlen(str, var->prec);
	else if (var->flags[0] == '0')
		ft_print_flag(var->width - ft_strlen(str), '0', var);
	else
		len = ft_strlen(str);
	str_print(str, var, len);
}

void		handle_str(t_printf *var)
{
	char	*str;
	int		len;

	str = va_arg(var->ap, char *);
	if (!str)
		str = "(null)";
	if (var->flags[1] == '-')
		s_with_flag(str, var);
	else if (var->flags[0] == '0' && var->width >= (int)ft_strlen(str))
	{
		if (var->prec >= 0)
			len = ft_strnlen(str, var->prec);
		else
			len = ft_strnlen(str, var->width);
		ft_print_flag(var->width - len, '0', var);
		(var->prec != 0) ? ft_putnstr(str, len, var) : 0;
	}
	else
		s_handle_warn_flag(str, var);
}
