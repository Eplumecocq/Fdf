/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:36:20 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/05 17:25:36 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

int		key_commands(int key_pressed, t_source *src)
{
	if (key_pressed == KEY_ESC)
		exit(0);
	if (key_pressed == KEY_UP)
		movement_up(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_DOWN)
		movement_down(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_LEFT)
		movement_left(src->mlx, src->map, src->img, src->mov);
	if (key_pressed == KEY_RIGHT)
		movement_right(src->mlx, src->map, src->img, src->mov);
	return (0);
}
