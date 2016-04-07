/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 19:18:34 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/07 11:58:36 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	height_up(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->up += 1;
	isometric_view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}

void	height_down(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->up -= 1;
	isometric_view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}
