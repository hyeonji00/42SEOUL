/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:53:34 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 17:34:46 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list **ap)
{
	char	*tmp;
	int		print_len;

	print_len = 0;
	tmp = (char *)va_arg(**ap, char *);
	if (tmp == 0)
		tmp = "(null)";
	print_len = write(1, tmp, ft_strlen(tmp));
	return (print_len);
}
