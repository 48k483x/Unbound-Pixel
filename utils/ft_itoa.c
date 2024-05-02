/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:44:44 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/07 16:03:58 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenght;

	lenght = ft_strlen((char *)s) + 1;
	dup = malloc(sizeof(char) * lenght);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, lenght);
	return (dup);
}

size_t	count_word_str(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0)
	{
		len++;
		return (len);
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	*allocation_str(size_t len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!(str))
		return (NULL);
	return (str);
}

char	*if_zero(char *str)
{
	str[0] = 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_word_str((long)n);
	str = allocation_str(len);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		if_zero(str);
	while (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
