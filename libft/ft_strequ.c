/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:17:24 by eneto             #+#    #+#             */
/*   Updated: 2018/04/07 18:50:16 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((s1 && !s2) || (!s1 && s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	else
		return (1);
}
