/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:05:02 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/05 17:21:27 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		tile_size(t_mlx *mlx, t_map *map)
{
	int		l;
	int		a;
	int		n;
	int		d;

	l = 0;
	a = 0;
	while (a < mlx->width)
	{
		n = ((map->columns_nb - 1) - 0) * l;
		d = (0 - (map->lines_nb - 1)) * l;
		a = ft_absolut(n) + ft_absolut(d);
		l++;
	}
	return (l - 8);
}

t_coord		map_center(t_mlx *mlx, t_map *map, int tile_size)
{
	t_coord	coord;
	int		c;
	int		n;
	int		t;
	int		r;

	c = ((map->columns_nb - 1) - 0) * tile_size;
	n = (0 - (map->lines_nb - 1) * tile_size);
	t = (0 + 0) * (tile_size / 2);
	r = ((map->columns_nb - 1) + (map->lines_nb - 1)) * (tile_size / 2);
	coord.x = (mlx->width / 2) - ((ft_absolut(c) - ft_absolut(n)) / 2);
	coord.y = (mlx->height / 2) - ((ft_absolut(t) - ft_absolut(r)) / 2);
	return(coord);
}

void	isometric_view(t_mlx *mlx, t_map *map, t_move *mov)
{
	t_coord	a;
	t_coord	b;
	int		tile;

	map->array = (t_coord**)ft_memalloc(sizeof(t_coord *) * map->lines_nb);
	tile = tile_size(mlx, map);
	b = map_center(mlx, map, tile);
	a.y = 0;
	while (a.y < map->lines_nb)
	{
		a.x = 0;
		map->array[a.y] = (t_coord*)ft_memalloc(sizeof(t_coord) 
				* map->columns_nb);
		while (a.x < map->columns_nb)
		{
			map->array[a.y][a.x].x = (a.x - a.y) * tile + b.x + mov->direc.x;
			map->array[a.y][a.x].y = (a.x + a.y) * (tile / 2) + b.y - 
				(map->parse[a.y][a.x] * mov->up) + mov->direc.y;
			a.x++;
		}
		a.y++;
	}
}

void	view(t_mlx *mlx, t_map *map, t_move *mov)
{
	isometric_view(mlx, map, mov);
}
