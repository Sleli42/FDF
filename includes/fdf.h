/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 08:37:16 by lubaujar          #+#    #+#             */
/*   Updated: 2016/05/19 08:37:18 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h> 
# include <sys/stat.h> 

# include <mlx.h>
# include <libft.h>

typedef struct		s_win
{
	int				x;
	int				y;
	int				z;
}					t_win;

typedef struct		s_mlx
{
	void			*init;
	void			*window;
	int				**parse;
	int				map_len;
	int				line_len;
	// t_win			*win;
}					t_mlx;

#endif