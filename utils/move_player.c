/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:44:33 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:04:13 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_data *data)
{
	data->player_x++;
	data->moves++;
	data->key = D;
	data->press = 1;
	data->reached = 0;
}

void	move_left(t_data *data)
{
	data->player_x--;
	data->moves++;
	data->key = A;
	data->press = 1;
	data->reached = 0;
}

void	move_up(t_data *data)
{
	data->player_y--;
	data->moves++;
	data->key = W;
	data->press = 1;
	data->reached = 0;
}

void	move_down(t_data *data)
{
	data->player_y++;
	data->moves++;
	data->key = S;
	data->press = 1;
	data->reached = 0;
}

void	all_moves(int key, t_data *data)
{
	if (key == D)
		move_right(data);
	else if (key == A)
		move_left(data);
	else if (key == W)
		move_up(data);
	else if (key == S)
		move_down(data);
}
