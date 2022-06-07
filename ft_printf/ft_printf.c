/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:19:47 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/07 18:24:46 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(const char *str, va_list *ap)
{
	int	num;

	num = 0;
	if (str[0] == 'c')
		num = ft_printf_c(ap);
	else if (str[0] == 's')
		num = ft_printf_s(ap);
	else if (str[0] == 'p')
		num = ft_printf_p(ap);
	else if (str[0] == 'd')
		num = ft_printf_d(ap);
	else if (str[0] == 'i')
		num = ft_printf_i(ap);
	else if (str[0] == 'u')
		num = ft_printf_u(ap);
	else if (str[0] == 'x')
		num = ft_printf_x(ap);
	else if (str[0] == 'X')
		num = ft_printf_X(ap);
	else if (str[0] == '%')
		num = write(1, "%%", 1);
	return (num);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		prev_num;

	i = 0;
	num = 0;
	va_start(ap, str);
	while (str[i] != 0)
	{
		prev_num = num;
		if (str[i] == '%')
			num += ft_printf_type(&str[i++], &ap);
		else
			num += write(1, &str[i], 1);
		if (prev_num > num)
		{
			va_end(ap);
			return (-1);
		}
		i++;
	}
	va_end(ap);
	return (num);
}
