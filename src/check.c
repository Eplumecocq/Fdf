/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:24:25 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/10 14:55:56 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"


int		check_tab_lines(t_mlx *mlx, t_map *map, t_coord coord)
{
	if (map->tab[coord.y][coord.x].x < mlx->width &&
			map->tab[coord.y][coord.x + 1].x < mlx->width &&
			 map->tab[coord.y][coord.x].y < mlx->height &&
			 map->tab[coord.y][coord.x + 1].y < mlx->height)
			return (1);
	else
			return (0);
}

int		check_tab_columns(t_mlx *mlx, t_map *map, t_coord coord)
{
	if (map->tab[coord.y][coord.x].x < mlx->width &&
			map->tab[coord.y + 1][coord.x].x < mlx->width &&
			 map->tab[coord.y][coord.x].y < mlx->height &&
			 map->tab[coord.y + 1][coord.x].y < mlx->height)
			return (1);
	else
			return (0);
}
