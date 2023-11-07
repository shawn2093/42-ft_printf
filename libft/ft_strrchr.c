/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:33 by long              #+#    #+#             */
/*   Updated: 2023/11/08 05:56:29 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*ptr;
	int		i;

	i = (int) ft_strlen(s);
	while (i > 0)
	{
		ptr = &s[i];
		if (s[i] == (unsigned char) c)
			return (ptr);
		i--;
	}
	return (0);
}
