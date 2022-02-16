/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:21:36 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 22:44:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

unsigned int	ft_strlen(char *s1)
{
	unsigned int	count;

	count = 0;
	while (*s1++)
		count++;
	return (count);
}

void	ft_rev(char *s1, int size)
{
	int		ini;
	char	aux;

	ini = 0;
	while (ini < size)
	{
		aux = s1[ini];
		s1[ini] = s1[size];
		s1[size] = aux;
		ini++;
		size--;
	}
}

void	convert(int nb, char *number, int index)
{
	if (nb >= 0)
	{
		while (nb > 0)
		{
			number[index++] = '0' + (nb % 10);
			nb /= 10;
		}
		if (index == 0)
			number[index++] = '0';
		number[index] = '\0';
	}
	else
	{
		number[index++] = '0' + ((nb % -10) * -1);
		nb /= -10;
		while (nb > 0)
		{
			number[index++] = '0' + (nb % 10);
			nb /= 10;
		}
		number[index++] = '-';
		number[index] = '\0';
	}
}

void	ft_putnbr(int nb)
{
	char	number[12];

	convert(nb, number, 0);
	ft_rev(number, ft_strlen(number) - 1);
	write(1, number, ft_strlen(number));
}
