/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:53:40 by scamargo          #+#    #+#             */
/*   Updated: 2017/12/08 14:01:05 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int sqr;
	int root;

	sqr = 0;
	root = 1;
	while (sqr != nb)
	{
		sqr = root * root;
		if (sqr > nb)
			return (0);
	}
	return (root);
}
