

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:23:07 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/17 18:18:17 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char *get_map_adress(char *map_name)
{
	char *full_adress;
	char *folder;
	int	append_necessity;

	if (!map_name)
		return (NULL);
	folder = MAPS_FOLDER;
	append_necessity = string_compare(map_name, folder, string_length(folder));
	if (append_necessity == false)
		return (map_name);
	full_adress = NULL;
	string_appender(&full_adress, folder);
	string_appender(&full_adress, map_name);
	return (full_adress);
}

int	create_map(t_map *maps)
{
	int	line;
	int	fd;

	if (!maps)
		return (0);
	maps->adress = get_map_adress(maps->name);
	maps->lines = get_map_lines(maps->adress);
	fd = open(maps->adress, O_RDONLY);
	if (fd < 0)
		return (end_program("Map not found, invalid fd in create_map", 1), 0);
	maps->map = malloc((maps->lines + 1) * sizeof(char *));
	if (!maps->map)
		return (end_program("Failed allocation in create_map", 1), 0);
	memory_zero(maps->map, maps->lines + 1, sizeof(maps->map));
	line = 0;
	while (line < maps->lines)
	{
		maps->map[line] = get_next_line_no_breakline(fd);
		if (!maps->map[line])
			break ;
		line++;
	}
	return (close(fd), 1);
}

int	get_map_lines(char *map_name)
{
	char *string;
	int	count;
	int	fd;

	if (!map_name)
		return (0);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (end_program("Map not found, invalid fd in get_map_lines", 1), 0);
	count = 0;
	string = " ";
	while (string != NULL)
	{
		string = get_next_line_no_breakline(fd);
		if (!string)
			break ;
		count++;
		free(string);
	}
	close(fd);
	return (count);
}
