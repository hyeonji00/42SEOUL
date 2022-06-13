/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:20:20 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 00:53:50 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_if_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == 0)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int	ft_numlen(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			len;
	long long	nb;

	nb = n;
	if (nb == 0)
		return (ft_if_zero());
	len = ft_numlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	i = len - 1;
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}
