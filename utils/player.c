/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:43:42 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:16:36 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_data *data, char *s)
{
	perror(s);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
	return (1);
}

int	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_hei)
	{
		j = 0;
		while (j < data->map_wid)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				data->map[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	data->start_x = data->player_x;
	data->start_y = data->player_y;
	return (0);
}

void	move_player(int key, t_data *d)
{
	int	old_x;
	int	old_y;

	old_x = d->player_x;
	old_y = d->player_y;
	all_moves(key, d);
	if (d->player_x < 0 || d->player_x >= d->map_wid || d->player_y < 0 || \
		d->player_y >= d->map_hei || d->map[d->player_y][d->player_x] == '1')
	{
		d->player_x = old_x;
		d->player_y = old_y;
	}
	else if (d->map[d->player_y][d->player_x] == 'X')
		exit_game(d, "You Lose");
	else if (d->map[d->player_y][d->player_x] == 'C')
	{
		d->collectible--;
		d->map[d->player_y][d->player_x] = '0';
		draw_background(d);
	}
	else if (d->map[d->player_y][d->player_x] == 'E' &&
				d->collectible == 0)
		exit_game(d, "You Won");
	draw_background(d);
	draw_game(d);
}

int	key_press(int key, t_data *d)
{
	if (d->reached == 1)
	{
		if (key == W && d->map[d->player_y - 1][d->player_x] != '1')
			move_player(W, d);
		else if (key == S && d->map[d->player_y + 1][d->player_x] != '1')
			move_player(S, d);
		else if (key == A && d->map[d->player_y][d->player_x - 1] != '1')
			move_player(A, d);
		else if (key == D && d->map[d->player_y][d->player_x + 1] != '1')
			move_player(D, d);
	}
	if (key == ESC)
		exit_game(d, "You Exited Game");
	return (0);
}
