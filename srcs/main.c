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
	int		j;

	buff = NULL;
	i = 0;
	j = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		if (!j)
		{
			while (buff[j])
			{
				if (ft_isdigit(buff[j]))
					i++;
				j++;
			}
			ptr->line_len = i;
			i = 0;
		}
		printf("buff: [%s]\n", buff);
		i++;
	}
	ptr->map_len = i;
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

int		check_file_error(char *file, int *fd)
{
	struct stat	buff;

	file = ft_strjoin("./", file);
	if (stat(file, &buff) == -1)
	{
		perror(file);
		return (0);
	}
	else if ((*fd = open(file, O_RDONLY)) == -1)
	{
		perror("Open");
		return (0);
	}
	return (1);
}

void	get_map(t_mlx *ptr, char **av)
{
	int		fd;
	char	*tmp;

	tmp = ft_strchr(av[1], '.');
	if (tmp && !ft_strcmp(tmp, ".fdf"))
	{
		init_fdf(ptr);
		if (!check_file_error(av[1], &fd))
			return ;
		else
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
		ft_putstr("Bad name\n");
}

int		main(int ac, char **av)
{
	t_mlx	*ptr;

	if (!(ptr = (t_mlx *)malloc(sizeof(t_mlx))))
		perror("Malloc");
	if (ac == 2)
		get_map(ptr, av);
	else
		ft_putstr("Bad nb params\n");
	return (0);
}