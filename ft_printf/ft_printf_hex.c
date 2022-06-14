/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:08 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 17:47:10 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int tmp)
{
	int	len;

	len = 0;
	if (tmp == 0)
		return (1);
	while (tmp != 0)
	{
		len++;
		tmp /= 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int tmp, const char c)
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
		write(1, &ch, 1);
	}
	else
	{
		ft_put_hex(tmp / 16, c);
		ft_put_hex(tmp % 16, c);
	}
}

int	ft_printf_hex(va_list **ap, const char c)
{
	unsigned int	tmp;
	int				print_len;

	print_len = 0;
	tmp = (unsigned int)va_arg(**ap, unsigned int);
	ft_put_hex(tmp, c);
	print_len = ft_hex_len(tmp);
	return (print_len);
}
