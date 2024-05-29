#include "fractol.h"

double ft_atof(const char *str)
{
	int		i;
	double	result;
	double divisor;
	int sign;

	result = 0;
	sign = 1;
	i = 0;
	divisor = 0.1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while ((str[i] >= '0' && str[i] <= '9'))
		{
			result = result + (str[i] - '0') * divisor;
			divisor *= 0.1;
			i++;
		}

	}
		return  (sign * (result));
}
