/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_advanced.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:03:46 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/17 19:41:47 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	string_compare(char *string1, char *string2, int until)
{
	int	index;

	if (!string1 || !string2)
		return (0);
	index = 0;
	while (string1[index] && string2[index]
		&& (string1[index] == string2[index]))
	{
		if ((until != 0) && index >= until)
			break ;
		index++;
	}
	return (string1[index] - string2[index]);
}

int	string_cat(char *string1, char *string2)
{
	int	index2;
	int	index;

	if (!string1 || !string2)
		return (0);
	index = 0;
	while (string1[index])
		index++;
	index2 = 0;
	while (string2[index2])
	{
		string1[index] = string2[index2];
		index++;
		index2++;
	}
	string1[index] = '\0';
	return (1);
}

int	memory_zero(void *memory, t_ul size, t_ul type_size)
{
	char *string;
	int	index;
	int	limit;

	if (!memory)
		return (0);
	limit = size * type_size;
	string = (char *)memory;
	index = 0;
	while (index < limit)
	{
		string[index] = 0;
		index++;
	}
	return (1);
}

// int	main(void)
// {
// 	printf("result: %d\n", string_compare("Tudo bem", "Tudo bem"));
// }