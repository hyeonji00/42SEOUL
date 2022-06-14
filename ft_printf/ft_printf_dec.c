/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:57:03 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 17:34:17 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dec(va_list **ap)
{
	int		tmp;
	char	*str;
	int		print_len;

	print_len = 0;
	tmp = (int)va_arg(**ap, int);
	str = ft_itoa(tmp);
	print_len = write(1, str, ft_strlen(str));
	free(str);
	return (print_len);
}
