/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:36:54 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/11 12:44:54 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	divisor;
	int		sign;

	result = 0;
	sign = 1;
	divisor = 0.1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
		if ('-' == *str++)
			sign = -1;
	while ((*str >= '0' && *str <= '9'))
		result = (result * 10.0) + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while ((*str >= '0' && *str <= '9'))
		{
			result = result + (*str - '0') * divisor;
			divisor *= 0.1;
			str++;
		}
	}
	return (sign * (result));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
