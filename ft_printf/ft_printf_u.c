/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:15:19 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/13 17:52:24 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(va_list **ap)
{
	unsigned int	tmp;
	char			*str;
	int				print_len;

	print_len = 0;
	tmp = (unsigned int)va_arg(**ap, unsigned int);
	str = ft_uitoa(tmp);
	print_len = write(1, str, ft_strlen(str));
	free(str);
	return (print_len);
}
