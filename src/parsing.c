/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:38:59 by eplumeco          #+#    #+#             */
/*   Updated: 2016/04/07 12:07:11 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void	free_tab(char **tab)
{
	int		j;

	j = 0;
	while (tab[j])
		free(tab[j++]);
	free(tab);
}

int		lines_nb(char *filename)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(filename, O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
		free(line);
	}
	close(fd);
	return (nb_line);
}

int		columns_nb(char *filename, int line_nb)
{
	int		fd;
	int		i;
	int		nb_columns;
	char	*line;
	char	**tab;

	fd = open(filename, O_RDONLY);
	nb_columns = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		if (i == line_nb)
		{
			tab = ft_strsplit(line, ' ');
			while (tab[nb_columns])
				nb_columns++;
			free_tab(tab);
		}
		free(line);
	}
	close(fd);
	return (nb_columns);
}

void	create_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**tab;
	t_coord	coord;

	map->parse = (int**)ft_memalloc(sizeof(int *) * map->lines_nb);
	fd = open(filename, O_RDONLY);
	coord.y = 0;
	while (coord.y < map->lines_nb)
	{
		coord.x = 0;
		map->parse[coord.y] = (int *)ft_memalloc(sizeof(int) * map->columns_nb);
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		while (coord.x < map->columns_nb)
		{
			check_valid_tab(tab);
			map->parse[coord.y][coord.x] = ft_atoi(tab[coord.x]);
			coord.x++;
		}
		free(line);
		free_tab(tab);
		coord.y++;
	}
	close(fd);
}

t_map	parsing(char *filename)
{
	t_map	map;

	check_lines(filename);
	map.lines_nb = lines_nb(filename);
	map.columns_nb = columns_nb(filename, 1);
	create_map(filename, &map);
	return (map);
}
