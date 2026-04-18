/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 04:55:03 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/18 07:26:41 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "parse.h"

int	is_valid(char xar)
{
	char *valid;
	int	index;

	if (!xar)
		return (0);
	valid = VALID_CHARACTERS;
	index = 0;
	while (valid[index])
	{
		if (xar == valid[index])
			return (1);
		index++;
	}
	return (0);
}

//descondensar essa função em 2 mais simples. (repetir código, por legibilidade)
int	check_axis(char **map, int *line, int *column, int *axis)
{
	(*line) = -1;
	while (map[++(*line)])
	{
		(*column) = 0;
		while (map[(*line)][(*column)])
		{
			if (is_valid(map[(*line)][(*column)]))
			{
				if ((map[(*line)][(*column)] != '1') &&  ++(*axis))
                    return (0);
				while (map[(*line)] && is_valid(map[(*line)][(*column)]))
                    (*axis)++;
				if ((--(*axis) >= 0) && map[(*line)][(*column)] != '1')
                    return (0);
			}
            (void)((axis == line) && ++(*axis));
            if ((axis == line) && map[(*line)] && map[(*line)][(*column)])
                continue ;
            (void)((++(*column)) && (axis == line) && (*axis = 0));
		}
		if (axis == line)
			return (1);
	}
	return (1);
}
