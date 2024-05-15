/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:08:21 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:02:46 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_str;
	size_t	len_sub;
	char	*substr;

	len_str = ft_strlen(str);
	if (str == NULL || len_str <= start)
		return (ft_strdup(""));
	len_sub = len_str - start;
	if (len_sub > len)
		len_sub = len;
	substr = (char *)malloc(len_sub +1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
