/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:26:48 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:27:52 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Return a substring from string *s from start to len
 **/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!(s))
		return (NULL);
	if (ft_strlen(s) < len + 1)
		len = ft_strlen(s);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(*ptr) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0x00;
	return (ptr);
}
