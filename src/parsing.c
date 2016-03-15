/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:10:54 by eplumeco          #+#    #+#             */
/*   Updated: 2016/03/15 14:43:48 by eplumeco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

int		lines_nb(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
			i++;
		free(line);
	}
	close(fd);
	return(i);
}

int		columns_nb(char *filename, int line_nb)
{	
	int		j;
	int		fd;
	int		null;
	char	*line;
	char	**tab;

	j = 0;
	null = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		null++;
		if (null == line_nb)
		{
			tab = ft_strsplit(line, ' ');
			while (tab[j])
					j++;
			free(tab);
		}
		free(line);
	}
	close(fd);
	return(j);
}

void	check_valid_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{	
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
				j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j++]))
			{
				ft_putendl("an error has occurred");
				exit(0);
			}
		}
		i++;
	}
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
		map->parse[coord.y] = (int*)ft_memalloc(sizeof(int) * map->columns_nb);
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		while (coord.x < map->columns_nb)
		{
			check_valid_tab(tab);
			map->parse[coord.y][coord.x] = ft_atoi(tab[coord.x]);
			coord.x++;
		}
		free(line);
		free(tab);
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
