/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:25:04 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/05 16:58:05 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

t_mlx	create_mlx(int width, int height, char *title)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, title);
	mlx.width = width;
	mlx.height = height;
	return(mlx);
}

t_move		create_mov()
{
	t_move	mov;

	mov.up = 1;
	mov.direc.x = 0;
	mov.direc.y = 0;
	return (mov);
}

t_source	create_source(t_mlx *mlx, t_map *map, t_img *img, t_move *mov)
{
	t_source	src;

	src.mov = mov;
	src.mlx = mlx;
	src.map = map;
	src.img = img;
	return (src);
}

int		main(int ac, char **av)
{
	t_source	src;
	t_mlx		mlx;
	t_map		map;
	t_img		img;
	t_move		mov;

	if (ac == 2)
	{
		map = parsing(av[1]);
		mlx = create_mlx(1000, 1000, "FDF");
		mov = create_mov();
		view(&mlx, &map, &mov);
		img = drawing(&mlx, &map);
		src = create_source(&mlx, &map, &img, &mov);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
		mlx_hook(mlx.win, 2, 0, key_commands, &src);
		mlx_loop(mlx.ptr);
	}
	return (0);
}
