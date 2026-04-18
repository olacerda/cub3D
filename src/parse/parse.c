/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:17:51 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/18 01:38:00 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// int	check_close_walls(t_map *maps)
// {
// 	char **map;
// 	int line;
// 	int column;

// 	if(!map)
// 		return (0);
// 	line = 0;
// 	column = 0;
// 	map = maps->map;
// 	while (map[line])
// 	{
// 		while (map[line][column])
// 		{
			
// 			column++;
// 		}
// 		line++;
// 	}
// }

// int	validate_map_type(char *map_name)
// {
	
// }

int	parse(t_all *all)
{
	if (all->argc != 2)
		return (put_error("Wrong argument count"), 0);
	create_map(all->maps);
	// printf("Passou de create_map!!\n");
	// int	line = 0;
	// while (all->maps->map[line])
	// 	printf("%s\n", all->maps->map[line++]);
	// printf("here5\n");
	// exit(1);
	return (1);
}
