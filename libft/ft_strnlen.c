/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:23:03 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/12/16 13:45:04 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnlen(char *str, int q)
{
	int		i;

	i = 0;
	while (i < q && str[i] != '\0')
		i++;
	return (i);
}