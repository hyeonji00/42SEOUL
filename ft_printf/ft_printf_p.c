/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:38:39 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 17:45:08 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p_len(size_t tmp)
{
	int	len;

	len = 0;
	while (tmp != 0)
	{
		len++;
		tmp /= 16;
	}
	return (len);
}

static void	ft_put_p(size_t tmp)
{
	char	ch;

	ch = '0';
	if (tmp < 16)
	{
		if (tmp < 10)
			ch = tmp + '0';
		else
			ch = tmp - 10 + 'a';
		write(1, &ch, 1);
	}
	else
	{
		ft_put_p(tmp / 16);
		ft_put_p(tmp % 16);
	}
}

int	ft_printf_p(va_list **ap)
{
	size_t	tmp;
	int		print_len;

	print_len = 0;
	tmp = (size_t)va_arg(**ap, size_t);
	print_len += write(1, "0x", 2);
	if (tmp == 0)
	{
		print_len += write(1, "0", 1);
		return (print_len);
	}
	ft_put_p(tmp);
	print_len += ft_p_len(tmp);
	return (print_len);
}
