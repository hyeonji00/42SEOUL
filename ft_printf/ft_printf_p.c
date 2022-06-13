/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:38:39 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 00:48:12 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_p(size_t tmp, int *len)
{
	char	ch;

	ch = '0';
	if (tmp < 16)
	{
		if (tmp < 10)
			ch = tmp + '0';
		else
			ch = tmp - 10 + 'a';
		len += write(1, &ch, 1);
	}
	else
	{
		ft_put_p(tmp / 16, len);
		ft_put_p(tmp % 16, len);
	}
}

int	ft_printf_p(va_list ap)
{
	size_t	tmp;
	int		print_len;

	print_len = 0;
	tmp = (size_t)va_arg(ap, size_t);
	print_len += write(1, "0x", 2);
	if (tmp == 0)
		return (write(1, "0", 1));
	ft_put_p(tmp, &print_len);
	return (print_len);
}
