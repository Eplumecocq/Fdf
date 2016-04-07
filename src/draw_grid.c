/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:55:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/07 14:00:11 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	draw_vertical(t_map *map, t_img *img)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < map->lines_nb - 1)
	{
		coord.x = 0;
		while (coord.x < map->columns_nb - 1)
		{
			draw_lines(img, map->array[coord.y][coord.x],
					map->array[coord.y][coord.x + 1], 0x4876FF);
			coord.x++;
		}
		draw_lines(img, map->array[coord.y][map->columns_nb - 1],
				map->array[coord.y + 1][map->columns_nb - 1], 0x008B8B);
		coord.y++;
	}
}

void	draw_horizontal(t_map *map, t_img *img)
{
	t_coord	coord;

	coord.x = 0;
	while (coord.x < map->columns_nb - 1)
	{
		coord.y = 0;
		while (coord.y < map->lines_nb - 1)
		{
			draw_lines(img, map->array[coord.y][coord.x],
					map->array[coord.y + 1][coord.x], 0x008B8B);
			coord.y++;
		}
		draw_lines(img, map->array[map->lines_nb - 1][coord.x],
				map->array[map->lines_nb - 1][coord.x + 1], 0x4876FF);
		coord.x++;
	}
}

t_img	drawing(t_mlx *mlx, t_map *map)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	img.mlx_width = mlx->width;
	img.size_line = mlx->width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.dian);
	draw_vertical(map, &img);
	draw_horizontal(map, &img);
	return (img);
}
