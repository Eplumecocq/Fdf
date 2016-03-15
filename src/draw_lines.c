/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:35:45 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 14:45:01 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

void	put_pixel_to_img(t_img *img, int y, int x, int color)
{
	((int*)((*img).addr))[y * (*img).mlx.width + x] = color;
}

void	create_line(t_math *line, t_coord *a, t_coord *b)
{
	line->steep = 0;
	if (ft_absolut(a->x - b->x) < ft_absolut(a->y - b->y))
	{
		ft_swap(&a->x, &a->y);
		ft_swap(&b->x, &b->y);
		line->steep = 1;
	}
	if (a->x > b->x)
	{
		ft_swap(&a->x, &b->x);
		ft_swap(&a->y, &b->y);
	}
	line->dx = b->x - a->x;
	line->dy = b->y - a->y;
	line->error = 0;
	line->derror = ft_absolut(line->dy) * 2;
	line->dot.x = a->x;
	line->dot.y = a->y;
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
		line.error = line.derror + line.error;
		if (line.error > line.dx)
		{
			line.dot.y += (b.y > a.y ? 1 : -1);
			line.error -= line.dx * 2;
		}
		line.dot.x++;
	}
}
