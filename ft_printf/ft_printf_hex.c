/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:08 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/13 18:38:01 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int tmp, const char c, int *len)
{
	char	ch;

	ch = '0';
	if (tmp < 16)
	{
		if (tmp < 10)
			ch = tmp + '0';
		else
		{
			ch = tmp - 10 + 'a';
			if (c == 'X')
				ch = ft_toupper(ch);
		}
		len += write(1, &ch, 1);
	}
	else
	{
		ft_put_hex(tmp / 16, c, len);
		ft_put_hex(tmp % 16, c, len);
	}
}

int	ft_printf_hex(va_list ap, const char c)
{
	unsigned int	tmp;
	int				print_len;

	print_len = 0;
	tmp = (unsigned int)va_arg(ap, unsigned int);
	ft_put_hex(tmp, c, &print_len);
	return (print_len);
}
