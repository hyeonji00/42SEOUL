/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:48:53 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 01:17:42 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(va_list ap)
{
	char	tmp;
	int		print_len;

	print_len = 0;
	tmp = (char)va_arg(ap, int);
	print_len = write(1, &tmp, 1);
	return (print_len);
}
