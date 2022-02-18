/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:52:25 by jv                #+#    #+#             */
/*   Updated: 2022/02/17 22:39:17 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print(char *num, int size)
{
	while (size)
	{
		write(1, (num + size), 1);
		size--;
	}
}

int	validate(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (ft_len(base) < 2)
		return (0);
	while (base[i])
	{
		while (base[j])
		{
			if ((base[i] == base[j]) || base[j] == '-' || base[j] == '+')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		rest;
	char	num[100];
	int		i;
	int		aux;

	i = 1;
	aux = nbr;
	if (!validate(base))
		return ;
	while (nbr != 0)
	{
		if (nbr < 0)
			rest = nbr % ft_len(base) * -1;
		else
			rest = nbr % ft_len(base);
		num[i++] = base[rest];
		nbr /= ft_len(base);
	}
	if (aux < 0)
		num[i++] = '-';
	ft_print(num, i - 1);
}
