/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:15:19 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/13 19:27:19 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int n)
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

int	ft_printf_u(va_list ap)
{
	unsigned int	tmp;
	char			*str;
	int				print_len;

	print_len = 0;
	tmp = (unsigned int)va_arg(ap, unsigned int);
	str = ft_uitoa(tmp);
	print_len = write(1, str, ft_strlen(str));
	free(str);
	return (print_len);
}
