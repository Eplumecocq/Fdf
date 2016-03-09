/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:26:17 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/09 18:11:54 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TILE_SIZE 32

# include <fcntl.h>
# include <stdlib.h>

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
	int				size_line;
	int				ndian;
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
	int				**parse;
	t_coord			**tab;
	int				lines_nb;
	int				columns_nb;
}					t_map;

int					lines_nb(char *filename);
int					columns_nb(char *filename);
void				check_valid_tab(char **tab);
void				create_map(char *fiename, t_map *map);
t_map				parsing(char *filename);

void				put_pixel_to_img(t_img *img, int y, int x, int color);
void				create_line(t_math *calc, t_coord *a, t_coord *b);
void				draw_lines(t_img *img, t_coord a, t_coord b, int color);
t_img				drawing(t_mlx *mlx, t_map *map);

void				iso_view(t_mlx *mlx, t_map *map);

int					check_tab_lines(t_mlx *mlx, t_map *map);
int					check_tab_columns(t_mlx *mlx, t_map *map);


#endif
