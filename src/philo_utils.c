/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:05:53 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/08 17:41:25 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philosophers.h"

uint64_t	atouint64(char	*num)
{
	uint64_t	converted;
	int			i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
	}
	i = -1;
	converted = 0;
	while (num[++i])
	{
		converted += (num[i] - '0');
		if (num[i + 1] != '\0')
			converted *= 10;
	}
	return (converted);
}
