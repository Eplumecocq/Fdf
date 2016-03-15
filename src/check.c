/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:33:40 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/14 17:51:19 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int			check_tab_lines(t_mlx *mlx, t_map *map, t_coord coord)
{
	if (map->tab[coord.y][coord.x].x < mlx->width &&
			map->tab[coord.y][coord.x + 1].x < mlx->width &&
			map->tab[coord.y][coord.x].y < mlx->height &&
			map->tab[coord.y][coord.x +1].y < mlx->height)
		return (1);
	else
		return (0);
}

int			check_tab_columns(t_mlx *mlx, t_map *map, t_coord coord)
{	
	if (map->tab[coord.y][coord.x].x < mlx->width &&
			map->tab[coord.y + 1][coord.x].x < mlx->width &&
			map->tab[coord.y][coord.x].y < mlx->height &&
			map->tab[coord.y + 1][coord.x].y < mlx->height)
		return (1);
	else
		return (0);
}

void		check_lines(char *filename)
{
	int		lines;
	int		i;
	int		columns;
	lines = numb_of_lines(filename);
	if (lines == 0)
	{
		ft_putendl("an error has occurred");
		exit(0);
	}
	columns = numb_of_columns(filename);
	i = 1;
	while (i <= lines)
		if (numb_of_columns(filename) != columns)
		{
			ft_putendl("an error has occurred");
			exit(0);
		}
}

void		check_valid_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j++]))
			{
				ft_putendl("an error has occurred");
				exit(0);
			}
		}
		i++;
	}
}
