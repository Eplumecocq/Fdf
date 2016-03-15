/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:43:49 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 14:51:02 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TILE_SIZE 32

#include <fcntl.h>
#include <stdlib.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				width;
	int				height;
}					t_mlx;

typedef struct		s_img
{
	void			*ptr;
	void			*addr;
	int				bpp;
	int				ndian;
	int				size_line;
	int				mlx_width;
	t_mlx			mlx;
}					t_img;

typedef struct		s_math
{
	int				dx;
	int				dy;
	int				error;
	int				derror;
	int				steep;
	t_coord			dot;
}					t_math;

typedef struct		s_map
{
	t_coord			**array;
	int				**parse;
	int				lines_nb;
	int				columns_nb;
}					t_map;

typedef struct		s_iso
{
	int				midw;
	int				midh;
	int				pi;
	int				po;
}					t_iso;

typedef struct		s_land
{
	t_coord			m;
	t_coord			a;
	t_coord			r;
	t_coord			k;
}					t_land;


t_img				drawing(t_mlx *mlx, t_map *map);
t_map				parsing(char *filename);
void				view(t_mlx *mlx, t_map *map);
void				check_lines(char *filename);
void				check_valid_tab(char **tab);
int					numb_of_lines(char *filename);
int					numb_of_columns(char *filename);
void	draw_Vlines(t_mlx *mlx, t_map *map, t_img *img);
void	draw_Hlines(t_mlx *mlx, t_map *map, t_img *img);
void	draw_lines(t_img *img, t_coord a, t_coord b, int color);

#endif
