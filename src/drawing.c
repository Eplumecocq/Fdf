/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c					                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:04:25 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/09 16:43:51 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

void	put_pixel_to_img(t_img *img, int y, int x, int color)
{
	((int*)((*img).addr))[y * (*img).mlx.width + x] = color;
}

void	create_line(t_math *calc, t_coord *a, t_coord *b)
{
	(*calc).steep = 0;
	if (ft_absolut((*a).x - (*b).x) < ft_absolut((*a).y - (*b).y))
	{
		ft_swap(&(*a).x, &(*b).x);
		ft_swap(&(*a).y, &(*b).y);
	}
	(*calc).dx = (*b).x - (*a).x;
	(*calc).dy = (*b).y - (*a).y;
	(*calc).error = 0;
	(*calc).derror = ft_absolut((*calc).dy) * 2;
	(*calc).dot.x = (*a).x;
	(*calc).dot.y = (*a).y;
}

void	draw_lines(t_img *img, t_coord a, t_coord b, int color)
{
	t_math	line;

	create_line(&line, &a, &b);
	while (line.dot.x <= b.x)
	{
		if (line.steep == 1)
				put_pixel_to_img(img, line.dot.y, line.dot.x, color);
		else
				put_pixel_to_img(img, line.dot.x, line.dot.y, color);
		line.error += line.derror;
		if(line.error > line.dx)
		{
			line.dot.y += (b.y > a.y ? 1 : -1);
			line.error -= line.dx * 2;
		}
		line.dot.x++;
	}
}

t_img	drawing(t_mlx *mlx, t_map *map)
{
	t_img	img;
	t_coord coord;

	(void)map;
	img.ptr = mlx_new_image((*mlx).ptr, (*mlx).width, (*mlx).height);
	img.size_line = (*mlx).width;
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.ndian);
	coord.y = 0;
	while (coord.y < (*map).lines_nb - 1)
	{
		coord.x = 0;
		while (coord.x < (*map).columns_nb - 1)
		{
			if (check_tab_lines(mlx, map) == 1)
			{
				draw_lines(&img, map->tab[coord.y][coord.x], 
								map->tab[coord.y][coord.x + 1], 0x00FF00);
				coord.x++;
			}
			draw_lines(&img, map->tab[coord.y][map->columns_nb - 1], 
							map->tab[coord.y + 1]
							[map->columns_nb - 1], 0x00FF00);
			coord.y++;
		}
	}
	coord.x = 0;
	while (coord.x < (*map).columns_nb - 1)
	{
		coord.y = 0;
		while (coord.y < (*map).lines_nb - 1)
		{
			if (check_tab_columns(mlx, map) == 1)
			{
				draw_lines(&img, map->tab[coord.y][coord.x], 
								map->tab[coord.y + 1][coord.x], 0x00FF00);
				coord.y++;
			}
			draw_lines(&img, map->tab[map->lines_nb - 1][coord.x], 
							map->tab[map->lines_nb - 1][coord.x + 1], 0x00FF00);
			coord.x++;
		}
	}
	return (img);
}
