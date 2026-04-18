/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:23:52 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/18 03:36:24 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"

//=====- allocation.c -=========================================================
void	*re_allocker(void *ptr, t_ul size, t_ul new_size, t_ul type_sz); // Returns a new memory of new_size's size, with the content of *ptr inside
char	*string_duplicate(char *string); // Returns an allocated copy of the string

//=====- allocation_free.c -====================================================
int	free_array_string(char **array_string, int size); // Size is optional, send 0 for std

//=====- string_advanced.c -====================================================
int		string_appender(char **string, char *adition); // Reallocs 'string' memory to add 'adition' in front of it
int		string_cat(char *string1, char *string2); // Concatenates a string2 in string1
int		string_compare(char *string1, char *string2, int until); //'Until' is optional, send 0 for std.
int		memory_zero(void *memory, t_ul size, t_ul type_size); // Sets every byte to zero

//=====- get_next_line_no_breakline.c -======================================================
char	*get_next_line_no_breakline(int fd); // Returns next line of file pointed by 'fd'
char	*liner(char *line, t_gnl *x, int *all_end, char *buffer); //Helper of get_next_line_no_breakline

//=====- string_basic.c -=======================================================
int		string_length(char *string); // Returns the length of the string passed

//=====- print.c -==============================================================
int		put_error(char *message);//Writes the string in stderr, and writes '\n'
int		put_message(char *message, int fd, int break_line); //Writes the string in the specific file descriptor. Send "break_line" to 'true' to end with '\n'
int     print_map(char **map); // Print an array[string]'s "map";

//=====- data.c -===============================================================
t_all	*init_structs();//Mallocs and sets '0' all structs of the project
t_all	*get_all_reference(t_all *all);//Returns all adress when arg is NULL
int		fill_structs(t_all *all, int argc, char **argv);//At beginning of main
void	end_program(char *error_message, int status);//Error is optional ~ NULL for std

#endif