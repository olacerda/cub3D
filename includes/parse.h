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

//=====- data_structure.c -=====================================================
int		create_map(t_map *maps);
int		get_map_lines(char *map_name); //Return line count of the map
char	*get_map_adress(char *map_name);

#endif
