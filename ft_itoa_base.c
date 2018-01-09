/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:18:21 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/08 19:24:33 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char 	hex[] = "0123456789ABCDEF";

static void		itoa_base(long num, char **str_ptr, int base)
{
	if (num < base)
	{
		**str_ptr = hex[num];
		(*str_ptr)++;
		return ;
	}
	itoa_base(num / base, str_ptr, base);
	itoa_base(num % base, str_ptr, base);
	return ;
}

char			*ft_itoa_base(int nbr, int base)
{
	char *str;
	if ((str = ft_memalloc(sizeof(char) * 30)) == NULL)
		return NULL;
	char *str_cpy = str;
	long num = (long)nbr;

	if (num < 0)
	{
		if (base == 10)
		{
			*str_cpy = '-';
			str_cpy++;
		}
		num *= -1;
	}	
	itoa_base(num, &str_cpy, base);
	*str_cpy = '\0';
	return (str);
 }


