/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:01:08 by long              #+#    #+#             */
/*   Updated: 2023/11/02 23:57:45 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *i, t_flags flag)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_htoa((unsigned long long)i, flag.type);
	flag.width -= ((int)ft_strlen(str) + 2);
	if (!flag.left)
	{
		len += ft_putpad_len(' ', flag.width);
		len += ft_putstr_len("0x");
		len += ft_putstr_len(str);
	}
	else
	{
		len += ft_putstr_len("0x");
		len += ft_putstr_len(str);
		len += ft_putpad_len(' ', flag.width);
	}
	free(str);
	return (len);
}

static int	ft_printhex_helper(char *str, char *hash, t_flags flag)
{
	int	len;

	len = 0;
	if (!flag.dot || flag.precision < (int)ft_strlen(str))
		flag.precision = (int)ft_strlen(str);
	flag.width -= flag.precision;
	flag.precision -= (int)ft_strlen(str);
	if (!flag.left)
	{
		if (flag.zero)
		{
			if (flag.dot)
				len += ft_putpad_len(' ', flag.width);
			len += ft_putstr_len(hash);
			if (!flag.dot)
				len += ft_putpad_len('0', flag.width);
		}
		else
			len += (ft_putpad_len(' ', flag.width) + ft_putstr_len(hash));
	}
	if (flag.dot)
		len += ft_putpad_len('0', flag.precision);
    if (!flag.left)
		return (len + ft_putstr_len(str));
	return (len + ft_putstr_len(str) + ft_putpad_len(' ', flag.width));
}

int	ft_print_hex(unsigned int i, t_flags flag)
{
	int		len;
	char	*str;
	char	*hash;

	hash = "";
	if (i == 0 && flag.precision == 0)
		str = ft_strdup("");
	else
	{
		if (flag.type == 'X' || flag.type == 'x')
			str = ft_htoa((unsigned long long)i, flag.type);
		else
			str = ft_utoa(i);
	}
	if (flag.hash && i != 0 && (flag.type == 'X' || flag.type == 'x'))
	{
		flag.width -= 2;
		if (flag.type == 'X')
			hash = "0X";
		else
			hash = "0x";
	}
	len = ft_printhex_helper(str, hash, flag);
	free(str);
	return (len);
}

// int	ft_print_hex(unsigned int i, t_flags flag)
// {
// 	int		len;
// 	char	*str;
// 	char	*hash;

// 	hash = "";
// 	if (i == 0 && flag.precision == 0)
// 		str = ft_strdup("");
// 	else
// 		str = ft_htoa((unsigned long long)i, flag.type);
// 	if (flag.hash && i != 0)
// 	{
// 		flag.width -= 2;
// 		if (flag.type == 'X')
// 			hash = "0X";
// 		else
// 			hash = "0x";
// 	}
// 	if (!flag.dot || flag.precision < (int)ft_strlen(str))
// 		flag.precision = (int)ft_strlen(str);
// 	flag.width -= flag.precision;
// 	flag.precision -= (int)ft_strlen(str);
// 	len = ft_printhex_helper(str, hash, flag);
// 	free(str);
// 	return (len);
// }