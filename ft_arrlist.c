/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:27:31 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/09 16:29:46 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	resize_array(t_array *arr)
{
	int		index;
	char	*new_str;

	index = 0;
	arr->size = arr->size * 2;
	new_str = malloc(((arr->size) + 1) * sizeof(char));
	while (arr->str[index])
	{
		new_str[index] = arr->str[index];
		index++;
	}
	free(arr->str);
	arr->str[arr->used] = '\0';
	arr->str = new_str;
}

void		arr_insert(t_array *arr, char c)
{
	if (arr->used == arr->size)
		resize_array(arr);
	arr->str[arr->used++] = c;
}

t_array		*arr_init(int initial_size)
{
	t_array *buff;

	if (!(buff = ft_memalloc(sizeof(t_array))))
			return (0);
	buff->size = initial_size;
	buff->used = 0;
	if (!(buff->str = ft_memalloc(buff->size * sizeof(char))))
		return (0);
	return (buff);
}
