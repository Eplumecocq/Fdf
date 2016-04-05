/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:18:55 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/05 17:25:38 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_map
{
	int			columns_nb;
	int			lines_nb;
	int			**parse;
	t_coord		**array;
}				t_map;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
}				t_mlx;

typedef struct	s_img
{
	void		*ptr;
	void		*addr;
	int			size_line;
	int			dian;
	int			bpp;
	int			mlx_width;
}				t_img;

typedef	struct	s_math
{
	int			dx;
	int			dy;
	int			steep;
	int			error;
	int			derror;
	t_coord		dot;
}				t_math;

typedef struct	s_move
{
	t_coord		direc;
	int			up;
}				t_move;

typedef struct	s_source
{
	t_mlx		*mlx;
	t_map		*map;
	t_img		*img;
	t_move		*mov;
}				t_source;


void			create_map(char *filename, t_map *map);
t_map			parsing(char *filename);
int				lines_nb(char *filename);
int				columns_nb(char *filename, int line_nb);
void			draw_lines(t_img *img, t_coord a, t_coord b, int color);
void			check_valid_tab(char **tab);
void			check_lines(char *filename);
t_img			drawing(t_mlx *mlx, t_map *map);
int				key_commands(int key_pressed, t_source *src);
void			view(t_mlx *mlx, t_map *map, t_move *mov);
void			movement_up(t_mlx *mlx, t_map *map, t_img *img, t_move *mov);
void			movement_down(t_mlx *mlx, t_map *map, t_img *img, t_move *mov);
void			movement_left(t_mlx *mlx, t_map *map, t_img *img, t_move *mov);
void			movement_right(t_mlx *mlx, t_map *map, t_img *img, t_move *mov);

#endif
