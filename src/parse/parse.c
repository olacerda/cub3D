/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:17:51 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/18 07:22:18 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "parse.h"

int	check_map_type(char *map_name)
{
	int	name_size;
	char *type;
	int	type_size;

	if (!map_name)
		return (0);
	type = MAP_TYPE;
	type_size = string_length(type);
	name_size = string_length(map_name);
	if (name_size <= type_size)
		return (0);
	map_name += name_size - type_size;
	if (string_compare(map_name, type, 0) == 0)
		return (1);
	return (0);	
}

int	check_close_walls(char **map)
{
	int	line;
	int	column;

	if (!map)
		return (0);
	if (!check_axis(map, &line, &column, &line))
		return (0);
	if (!check_axis(map, &line, &column, &column))
		return (0);
	return (1);
}

int	parse(t_all *all)
{
	if (all->argc != 2)
		return (put_error("Wrong argument count"), 0);
	if (!check_map_type(all->maps->name))
		end_program("Wrong map type. Expected 'file.cub'.", 1);
	create_map(all->maps);
	print_map(all->maps->map);
	if (!check_close_walls(all->maps->map))
		end_program("Map is not properly enclosed by walls '1'", 1);
	// printf("Passou de create_map!!\n");
	// int	line = 0;
	// while (all->maps->map[line])
	// 	printf("%s\n", all->maps->map[line++]);
	// printf("here5\n");
	// exit(1);
	return (1);
}
