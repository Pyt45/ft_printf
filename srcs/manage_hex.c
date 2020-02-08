/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:14:29 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/18 15:47:08 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				ft_check_char(long long n, char ch)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else
	{
		if (ch == 'x')
			return ('a' + n - 10);
		else if (ch == 'X')
			return ('A' + n - 10);
	}
	return (0);
}

static char			*ft_print_hex(unsigned long n, char ch, int opt)
{
	static char	str[18];
	static int	i;

	i = 2;
	(!opt) ? ft_bzero(str, 18) : 0;
	str[0] = '0';
	str[1] = 'x';
	if (n / 16 > 0)
		ft_print_hex(n / 16, ch, 1);
	str[i++] = ft_check_char(n % 16, ch);
	return (str);
}

static char			*ft_print_add(char **adr, unsigned long long p)
{
	*adr = ft_print_hex(p, 'x', 0);
	return (*adr);
}

void				ft_print_address(char **adr, t_printf *var)
{
	var->ptr = (unsigned long)va_arg(var->ap, void *);
	ft_print_add(adr, (unsigned long)var->ptr);
}
