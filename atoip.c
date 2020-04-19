/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hminowa <hminowa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:45:43 by ytanooka          #+#    #+#             */
/*   Updated: 2020/04/09 19:27:46 by hminowa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		atoip(char **str)
{
	char	*nbr;
	int		i;

	i = 0;
	while ((*str)[i] != 0)
	{
		if ((*str)[i] != 45 && ((*str)[i] < '0' || (*str)[i] > '9'))
			break ;
		else
			i++;
	}
	nbr = (char*)malloc(sizeof(char) * i);
	ft_strncpy(nbr, *str, i);
	(*str) = &((*str)[i]);
	return (ft_to_num(nbr));
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		ft_to_num(char *nb)
{
	int		number;
	int		i;
	int		flag;

	number = 0;
	i = 0;
	flag = 0;
	while (nb[i] != 0)
	{
		if (nb[i] == '-')
			flag = 1;
		else if (nb[i] >= '0' && nb[i] <= '9')
			number = (number * 10) + (nb[i] - '0');
		else
			break ;
		++i;
	}
	return (flag == 1 ? -number : number);
}
