/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:52:49 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/05 17:29:20 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

#define STEP 10

void	movement_up(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, 
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->direc.y = mov->direc.y - STEP;
	view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}

void	movement_down(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, 
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->direc.y = mov->direc.y + STEP;
	view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}

void	movement_left(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, 
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->direc.x = mov->direc.x - STEP;
	view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}

void	movement_right(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, 
			&img->dian);
	ft_bzero(img->addr, mlx->width * mlx->height);
	mlx_clear_window(mlx->ptr, mlx->win);
	mov->direc.x = mov->direc.x + STEP;
	view(mlx, map, mov);
	*img = drawing(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}
