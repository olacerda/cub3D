/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:53:26 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/18 00:29:40 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include "mlx.h"

# define FAIL -1
# define BUFFER_SIZE 25
# define SUBJECT_ERROR "Error\n"
# define MAPS_FOLDER "assets/maps/"

typedef unsigned long t_ul;

typedef struct s_gnl
{
	int		start;
	int		end;
	int		readbytes;
}				t_gnl;

typedef	struct s_map
{
	char	**map;
	char	*name;
	char	*adress;
	int		lines;
	int		columns;
}				t_map;

typedef struct s_all
{
	t_map	*maps;
	int		argc;
	char	**argv;
}				t_all;


#endif