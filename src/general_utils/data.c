/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:21:29 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/17 20:22:14 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:59:59 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/16 21:44:53 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_all	*init_structs()
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (put_error("Failed malloc of \"all\" struct"), NULL);
	*all = (t_all){0};
	all->maps = malloc(sizeof(t_map));
	if (!all->maps)
		return (end_program("Failed malloc of \"all\" struct", 1), NULL);
	*all->maps = (t_map){0};
	return (all);
}

t_all	*get_all_reference(t_all *all)
{
	static t_all *reference;

	if (all != NULL)	
	{
		reference = all;
		end_program(NULL, 0);
		return (NULL);
	}
	return (reference);
}

int	fill_structs(t_all *all, int argc, char **argv)
{
	if (!all)
		return (0);
	get_all_reference(all);
	all->argc = argc;
	all->argv = argv;
	if (argc > 0)
		all->maps->name = string_duplicate(argv[1]);
	return (1);
}

void	end_program(char *error, int status)
{
	static t_all *all;

	if (all == NULL)
	{
		all = get_all_reference(NULL);
		return ;
	}
	if (all->maps)
	{
		if (all->maps->name)
			free(all->maps->name);
		free_array_string(all->maps->map, 0);
		free(all->maps);
	}
	if (all)
		free(all);
	if (error != NULL)
		put_error(error);
	exit(status);
}
