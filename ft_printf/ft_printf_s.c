/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:53:34 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/07 17:56:20 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list *ap)
{
	char	*tmp;
	int		num;

	num = 0;
	tmp = (char *)va_arg(*ap, char *);
	if (tmp == 0)
		tmp = "(null)";
	num = write(1, tmp, ft_strlen(tmp));
	return (num);
}
