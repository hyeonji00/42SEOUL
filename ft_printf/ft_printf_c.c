/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:48:53 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/07 17:54:38 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(va_list *ap)
{
	char	tmp;
	int		num;

	num = 0;
	tmp = (char)va_arg(*ap, int);
	num = write(1, &tmp, 1);
	return (num);
}
