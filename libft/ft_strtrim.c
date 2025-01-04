/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:11:27 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:27:12 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trim string s1 with the contents of set
 * returns the trimmed string
 **/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s = ft_strlen(s1);
	while (s && ft_strchr(set, s1[s]))
		s--;
	str = ft_substr((char *)s1, 0, s + 1);
	return (str);
}
