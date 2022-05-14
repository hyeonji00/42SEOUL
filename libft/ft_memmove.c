/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:45 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/05/07 13:33:17 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	if (dst == src)
		return (dst);
	i = 0;
	dst_tmp = dst;
	src_tmp = src;
	if (dst_tmp > src_tmp)
		while (len--)
			dst_tmp[len] = src_tmp[len];
	else
	{
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
