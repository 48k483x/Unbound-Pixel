/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twichiat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:06:04 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:07:37 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collectible_function(char **filenames)
{
	filenames[0] = "assets/coll/1.xpm";
	filenames[1] = "assets/coll/2.xpm";
	filenames[2] = "assets/coll/3.xpm";
	filenames[3] = "assets/coll/4.xpm";
	filenames[4] = "assets/coll/5.xpm";
	filenames[5] = "assets/coll/6.xpm";
}

int	standar_animation(t_data *data)
{
	char	*n;

	n = ft_itoa(data->moves);
	data->frame_counter++;
	draw_game(data);
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFF00, "Moves Number : ");
	mlx_string_put(data->mlx, data->win, 210, 50, 0xFFFF00, \
						ft_itoa(data->moves));
	free(n);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_map_row_len(t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

void	free_visited(t_data *data, int **visited)
{
	int	i;

	i = 0;
	while (i < data->map_hei)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
