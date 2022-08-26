/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:41:04 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:09:21 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count(char const *s, char c)

{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_split_putstr(char const *s, char c, char **split)
{
	size_t	splen;
	size_t	i;
	size_t	spi;

	i = 0;
	splen = 0;
	spi = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			splen++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[spi] = (char *)malloc(sizeof(char) * (splen + 1));
			if (split[spi] == NULL)
				return (ft_free_split(split));
			ft_strlcpy(split[spi], &s[i - splen + 1], splen + 1);
			spi++;
			splen = 0;
		}
		i++;
	}
	split[spi] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**split;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	if (!ft_split_putstr(s, c, split))
		return (NULL);
	return (split);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
// 	printf("-------------------test------------------\n");
// 	char test1[] = "test sample    42 ";
// 	char test2 = ' ';
// 	char **dst1 = ft_split(test1, test2);
// 	printf("case:\t\ttest sampleをスペースで区切る\n");
// 	int i = 0;
// 	while (dst1[i])
// 	{
// 		printf("word[%d]:	%s\n", i, dst1[i]);
// 		i++;
// 	}
// 	int j = 0;
// 	while (j <= i)
// 	{
// 		free(dst1[j]);
// 		dst1[j] = NULL;
// 		j++;
// 	}
// 	free(dst1);
// 	return (0);
// }
