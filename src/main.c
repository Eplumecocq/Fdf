/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:01:23 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 11:43:14 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

static int		close_win(int keycode, void *param)
{
	param = NULL;

	if (keycode == 53)
		exit(-1);
	else
		return (0);
}

t_mlx		create_mlx(int width, int height, char *name)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, width, height, name);
	mlx.width = width;
	mlx.height = height;
	return (mlx);
}

int			main(int ac, char **av)
{
	t_map	map;
	t_img	img;
	t_mlx	mlx;

	if (ac == 2)
	{
		map = parsing(av[1]);
		mlx = create_mlx (2000, 2000, av[1]);
		view(&mlx, &map);
		img = drawing (&mlx, &map);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
		mlx_key_hook(mlx.win, close_win, 0);
		mlx_loop(mlx.ptr);
	}
	return (0);
}
