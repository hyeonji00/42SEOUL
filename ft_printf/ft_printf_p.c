/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:38:39 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/15 15:55:01 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p_len(unsigned long long tmp)
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

static void	ft_put_p(unsigned long long tmp)
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
	unsigned long long	tmp;
	int					print_len;

	print_len = 0;
	tmp = (unsigned long long)va_arg(**ap, unsigned long long);
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
