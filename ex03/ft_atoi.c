/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:35:31 by jv                #+#    #+#             */
/*   Updated: 2022/02/17 10:35:37 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	jump_spaces(char **str, char **str_end)
{
	int	signals;
	int	stop;

	signals = 1;
	stop = 0;
	while (**str_end)
	{
		if (!(**str_end >= '0' && **str_end <= '9'))
		{
			if (stop)
				break ;
			if (**str_end == '+' || **str_end == '-')
				if (**str_end == '-')
					signals *= -1;
			(*str_end)++;
			(*str)++;
			continue ;
		}
		(*str_end)++;
		stop = 1;
	}
	(*str_end)--;
	return (signals);
}

int	ft_atoi(char *str)
{
	char	*str_end;
	int		mult;
	int		result;
	int		aux;
	int		s;

	str_end = str;
	mult = 1;
	result = 0;
	s = jump_spaces(&str, &str_end);
	while (str_end >= str)
	{
		aux = *str_end - '0';
		result += aux * mult;
		mult *= 10;
		str_end--;
	}
	return (result * s);
}
