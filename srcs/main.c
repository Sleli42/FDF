/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 08:36:31 by lubaujar          #+#    #+#             */
/*   Updated: 2016/05/19 08:36:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_mlx *ptr)
{
	ptr->init = mlx_init();
	ptr->window = mlx_new_window(ptr->init, 1000, 750, "Fdf");
}

int		len_array(int **array)
{
	int	ct;

	ct = 0;
	while (array && array[ct])
		ct++;
	return (ct);
}

void	get_map_infos(t_mlx *ptr, int fd)
{
	char	*buff;
	int		i;

	buff = NULL;
	i = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		printf("buff: [%s]\n", buff);
		i++;
	}
	ptr->map_len = i;
	i = 0;
	while (buff[i])
		i++;
	ptr->line_len = i;
	(buff || *buff) ? ft_strdel(&buff) : NULL;
}

int		**parse_map(t_mlx *ptr, int fd)
{
	int		i;
	int		**ret;
	char	*buff;

	buff = NULL;
	i = 0;
	get_map_infos(ptr, fd);
	printf("maplen: %d && linelen: %d\n", ptr->map_len, ptr->line_len);
	if (!(ret = (int **)malloc(sizeof(int *) * i + 1)))
		return (NULL);
	// printf("buf: [ %s ]\n", buff);
	// while (i < save)
	// ret[i] = NULL;
	return (NULL);
}

void	get_map(t_mlx *ptr, int ac, char **av)
{
	int		fd;

	if (ac == 2 && !ft_strcmp(ft_strchr(av[1], '.'), ".fdf"))
	{
		if ((fd = open(av[1], O_RDONLY)))
			ptr->parse = parse_map(ptr, fd);
		int i = 0;
		int	j = 0;
		while (i < len_array(ptr->parse))
		{
			j = 0;
			while (j < (int)ft_strlen((char *)ptr->parse[i]))
				printf("%d ", ptr->parse[i][j++]);
			i++;
		}
	}
	else
		ft_putstr("Bad nb params or bad map name\n");
}

int		main(int ac, char **av)
{
	t_mlx	*ptr;

	if (!(ptr = (t_mlx *)malloc(sizeof(t_mlx))))
		perror("Malloc");
	init_fdf(ptr);
	get_map(ptr, ac, av);
	// mlx_loop(ptr->init);
	return (0);
}