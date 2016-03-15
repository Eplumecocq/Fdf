/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:37:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 15:34:53 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	draw_Vlines(t_mlx *mlx, t_map *map, t_img *img)
{
	t_coord	coord;
	int		color;

	color = 0x00FF00;
	coord.y = 0;
	while (coord.y < map->lines_nb - 1)
	{
		coord.x = 0;
		while (coord.x < map->columns_nb - 1)
		{
			if (map->array[coord.y][coord.x].x < mlx->width 
					&& map->array[coord.y][coord.x + 1].x < mlx->width 
					&& map->array[coord.y][coord.x].y < mlx->height 
					&& map->array[coord.y][coord.x + 1].y < mlx->height)
				draw_lines(img, map->array[coord.y][coord.x],
								map->array[coord.y][coord.x + 1], color);
			coord.x++;
		}
		draw_lines(img, map->array[coord.y][map->columns_nb - 1], 
						map->array[coord.y + 1][map->columns_nb - 1], color);
		coord.y++;
	}
}

void	draw_Hlines(t_mlx *mlx, t_map *map, t_img *img)
{
	t_coord	coord;
	int		color;

	color = 0x00FF00;
	coord.x = 0;
	while (coord.x < map->columns_nb - 1)
	{
		coord.y = 0;
		while (coord.y < map->lines_nb - 1)
		{
			if (map->array[coord.y][coord.x].x < mlx->width 
					&& map->array[coord.y + 1][coord.x].x < mlx->width 
					&& map->array[coord.y][coord.x].y < mlx->height 
					&& map->array[coord.y + 1][coord.x].y < mlx->height)
				draw_lines(img, map->array[coord.y][coord.x],
								map->array[coord.y + 1][coord.x], color);
			coord.y++;
		}
		draw_lines(img, map->array[map->lines_nb - 1][coord.x],
						map->array[map->lines_nb - 1][coord.x + 1], color);
		coord.x++;
	}
}

t_img	drawing(t_mlx *mlx, t_map *map)
{
	t_img	img;

	(void)map;
	img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	img.size_line = mlx->width;
	img.mlx_width = mlx->width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.ndian);
	draw_Vlines(mlx, map, &img);
	draw_Hlines(mlx, map, &img);
	return(img);
}
