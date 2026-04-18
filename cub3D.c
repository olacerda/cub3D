/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:52:17 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/17 20:28:55 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char *argv[])
{
	t_all *all;

	all = init_structs();
	if (!all)
		return (1);
	fill_structs(all, argc, argv);
	if (!parse(all))
		return (end_program(NULL, 1), 1);
	end_program(NULL, 0);
	return (0);
}
