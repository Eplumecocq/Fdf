/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:03:35 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/09 17:08:02 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	iso_view(t_mlx *mlx, t_map *map)
{
	int		middle_h;
	int		middle_w;
	t_coord	coord;

	middle_w = ((*mlx).width / 2) - (((*map).columns_nb * TILE_SIZE) / 4);
	middle_h = ((*mlx).height / 2) - (((*map).lines_nb * TILE_SIZE) / 2);
	(*map).tab = (t_coord**)ft_memalloc(sizeof(t_coord *) * (*map).lines_nb);
	coord.y = 0;
	while (coord.y < (*map).lines_nb)
	{
		(*map).tab[coord.y] = (t_coord*)ft_memalloc(sizeof(t_coord) 
						* (*map).columns_nb);
		coord.x = 0;
		while (coord.x < (*map).columns_nb)
		{
			(*map).tab[coord.y][coord.x].x = (coord.x + coord.y) *
					(TILE_SIZE / 2) + middle_h - 
					((*map).parse[coord.y][coord.x] * 3);
			(*map).tab[coord.y][coord.x].y = (coord.x - coord.y) * 
					TILE_SIZE + middle_w;
			coord.x++;
		}
		coord.y++;
	}
}
