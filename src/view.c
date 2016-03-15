/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:43:30 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 14:53:26 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		iso_view(t_mlx *mlx, t_map *map)
{
	t_coord	coord;
	t_iso	iso;

	iso = ;
	map->array = (t_coord **)ft_memalloc(sizeof(t_coord *) * map->lines_nb);
	coord.y = 0;
	while (coord.y < map->lines_nb)
	{
		map->array[coord.y] = (t_coord *)ft_memalloc(sizeof(t_coord) * map->columns_nb);
		coord.x = 0;
		while (coord.x < map->columns_nb)
		{
			map->array[coord.y][coord.x].x = (coord.x + coord.y) * (iso.po / 2)
				+ iso.midh - (map->parse[coord.y][coord.x] * iso.pi);
			map->array[coord.y][coord.x].y = (coord.x - coord.y) * iso.po + iso.midw;
			coord.x++;
		}
		coord.y++;
	}
}
