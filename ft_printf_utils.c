/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:20:19 by long              #+#    #+#             */
/*   Updated: 2023/11/02 21:21:07 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags_init(void)
{
	t_flags	a;

	a.type = 0;
	a.left = 0;
	a.space = 0;
	a.plus = 0;
	a.zero = 0;
	a.hash = 0;
	a.dot = 0;
	a.width = 0;
	a.precision = 1;
	return (a);
}

static int	numlen(unsigned long long n, int i)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= i;
	}
	return (count);
}

char	*ft_htoa(unsigned long long n, int i)
{
	int		len;
	char	*str;
	int		start;
	char	*hex;

	if (n == 0)
		return (ft_strdup("0"));
	len = numlen(n, 16);
	hex = "0123456789abcdef";
	if (i == 'X')
		hex = "0123456789ABCDEF";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	start = 0;
	while (--len >= start)
	{
		str[len] = hex[(int)(n % 16)];
		n = n / 16;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;
	int		start;

	if (n == 0)
		return (ft_strdup("0"));
	len = numlen((unsigned long long)n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	start = 0;
	while (--len >= start)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
