/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:19:42 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/06/14 01:09:56 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_printf_c(va_list ap);
int	ft_printf_s(va_list ap);
int	ft_printf_dec(va_list ap);
int	ft_printf_u(va_list ap);
int	ft_printf_hex(va_list ap, const char c);
int	ft_printf_p(va_list ap);

#endif