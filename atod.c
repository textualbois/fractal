#include "./fractol.h"

static double atod_decimal_part(double res, int sign, const char *nptr, int i)
{
	double	d_part;
	int		dev;

	d_part = 0;
	dev = 10;
	if (nptr[i] == '\0')
		return (sign * res + (sign == 0) * res);
	else if (nptr[i] != '.' && nptr[i] != ',')
		return (NULL);
	else
	{
		i++;
		while (ft_isdigit(nptr[i]))
		{
			d_part = d_part + ((double)(nptr[i] - 48)) / dev;
			i++;
			dev = dev * 10;
		}

	}
}


double	ft_atod(const char *nptr)
{
	int		i;
	double	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (sign != 0)
			return (0);
		if (nptr[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (atod_decimal_part(res, sign, nptr, i));
	return (sign * res + (sign == 0) * res);
}
