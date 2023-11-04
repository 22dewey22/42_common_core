/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:28:44 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 00:36:24 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bsd/bsd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p_big;
	char	*p_lit;

	i = 0;
	while (little[i])
		i++;
	if (i == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	p_big = (char *)big;
	p_lit = (char *)little;
	while (p_big[i] && i < len)
	{
		j = 0;
		while (p_lit[j] && p_big[i + j] == p_lit[j] && i + j < len)
			j++;
		if (p_lit[j] == 0)
			return (&p_big[i]);
		i++;
	}
	return (0);
}
/*
char	*strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	const char	*big = "banana prout chiotte";
	const char	*lit = "ana";
	size_t		len;

	len = 12;
	__builtin_printf("strnstr => %s\nft_strnstr => %s\n", strnstr(big, lit,
			len), ft_strnstr(big, lit, len));
	return (0);
}
*/
