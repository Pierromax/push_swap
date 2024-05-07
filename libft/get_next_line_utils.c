/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:29:13 by ple-guya          #+#    #+#             */
/*   Updated: 2024/05/07 19:23:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_pro_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int nl)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_pro_strlen(s1);
	if (nl)
		len2 = nl;
	else
		len2 = ft_pro_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	str[len2 + len1] = '\0';
	while (len2--)
		str[len1 + len2] = s2[len2];
	while (len1--)
		str[len1] = s1[len1];
	free(s1);
	return (str);
}
