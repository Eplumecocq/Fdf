/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 11:18:40 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/07 13:55:39 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	check_valid_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j++]))
			{
				ft_putendl("An error has occurred. Please use a correct map");
				exit(0);
			}
		}
		i++;
	}
}

void	check_lines(char *filename)
{
	int		lines;
	int		i;
	int		nb_columns;

	lines = lines_nb(filename);
	if (lines < 2)
	{
		ft_putendl("An error has occurred. Please use a correct map");
		exit(0);
	}
	nb_columns = columns_nb(filename, 1);
	if (nb_columns < 2)
	{
		ft_putendl("An error has occured. Please use a correct map");
		exit(0);
	}
	i = 1;
	while (i <= lines)
	{
		if (columns_nb(filename, i++) != nb_columns)
		{
			ft_putendl("An error has occured. Please use a correct map");
			exit(0);
		}
	}
}
