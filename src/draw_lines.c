/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:55:25 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/01 16:56:23 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	put_pixel_to_image(t_img *img, int y, int x, int color)
{
	((int *)(img->addr))[y * img->mlx_width + x] = color;
}

void	create_line(t_math *math, t_coord *a, t_coord *b)
{
	math->steep = 0;
	if (ft_absolut(a->x - b->x) < ft_absolut(a->y - b->y))
	{
		ft_swap(&a->x, &a->y);
		ft_swap(&b->x, &b->y);
		math->steep = 1;
	}
	if (a->x > b->x)
	{
		ft_swap(&a->x, &b->x);
		ft_swap(&a->y, &b->y);
	}
	math->dx = b->x - a->x;
	math->dy = b->y - a->y;
	math->derror = ft_absolut(math->dy) * 2;
	math->error = 0;
	math->dot.x = a->x;
	math->dot.y = a->y;
}

void	draw_lines(t_img *img, t_coord a, t_coord b, int color)
{
	t_math math;

	create_line(&math, &a, &b);
	while (math.dot.x <= b.x)
	{
		if (math.dot.x < img->mlx_width && math.dot.y < img->mlx_width &&
				math.dot.x >= 0 && math.dot.y >= 0)
		{
			if (math.steep == 1)
				put_pixel_to_image(img, math.dot.x, math.dot.y, color);
			else
				put_pixel_to_image(img, math.dot.y, math.dot.x, color);
		}
		math.error = math.error + math.derror;
		if (math.error > math.dx)
		{
			math.dot.y += (b.y > a.y ? 1 : -1);
			math.error -= math.dx * 2;
		}
		math.dot.x++;
	}
}
