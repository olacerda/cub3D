/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:01:16 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/14 21:57:32 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "utils.h"

//=====- parse.c -==============================================================
int		parse(t_all *all); //Do the whole parse of the project
int     check_map_type(char *map_name);
int     check_close_walls(char **map);

//=====- parse_utils.c -========================================================
int     is_valid(char xar); //Verify if it is one of the permitted characters
int     check_axis(char **map, int *line, int *column, int *axis);

//=====- data_structure.c -=====================================================
int		create_map(t_map *maps);
int		get_map_lines(char *map_name); //Return line count of the map
char	*get_map_adress(char *map_name);

#endif
