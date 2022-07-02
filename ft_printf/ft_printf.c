/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:19:47 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/07/03 02:32:51 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_type(const char c, va_list *ap)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len = ft_printf_c(&ap);
	else if (c == 's')
		print_len = ft_printf_s(&ap);
	else if (c == 'p')
		print_len = ft_printf_p(&ap);
	else if (c == 'd' || c == 'i')
		print_len = ft_printf_dec(&ap);
	else if (c == 'u')
		print_len = ft_printf_u(&ap);
	else if (c == 'x' || c == 'X')
		print_len = ft_printf_hex(&ap, c);
	else if (c == '%')
		print_len = write(1, "%%", 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			print_len += ft_printf_type(str[i], &ap);
		}
		else
			print_len += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (print_len);
}
