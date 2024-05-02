/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:24:04 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 05:51:18 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	anime_right(t_data *data)
{
	static int	j;

	if (j <= 0)
		j = 106;
	j -= 5;
	if (data->frame_counter % 2 == 0)
	{
		IMG(data->mlx, data->win, data->right, \
			(data->player_x * TW + 40) - j, \
			data->player_y * TH + 40);
	}
	else
	{
		IMG(data->mlx, data->win, data->right1, \
			(data->player_x * TW + 40) - j, \
			data->player_y * TH + 40);
	}
	if (j <= 0)
	{
		data->press = 0;
		data->reached = 1;
		j = 0;
	}
}

void	anime_left(t_data *data)
{
	static int	i;

	if (i <= 0)
		i = 106;
	i -= 5;
	if (data->frame_counter % 2 == 0)
	{
		IMG(data->mlx, data->win, data->left, \
			(data->player_x * TW + 40) + i, \
			data->player_y * TH + 40);
	}
	else
	{
		IMG(data->mlx, data->win, data->left1, \
			(data->player_x * TW + 40) + i, \
			data->player_y * TH + 40);
	}
	if (i <= 0)
	{
		data->press = 0;
		data->reached = 1;
		i = 0;
	}
}

void	anime_up(t_data *data)
{
	static int	i;

	if (i <= 0)
		i = 106;
	i -= 5;
	if (data->frame_counter % 2 == 0)
	{
		IMG(data->mlx, data->win, data->up, \
			(data->player_x * TW + 40), \
			(data->player_y * TH + 40) + i);
	}
	else
	{
		IMG(data->mlx, data->win, data->up1, \
			(data->player_x * TW + 40), \
			(data->player_y * TH + 40) + i);
	}
	if (i <= 0)
	{
		data->press = 0;
		data->reached = 1;
		i = 0;
	}
}

void	anime_down(t_data *data)
{
	static int	i;

	if (i <= 0)
		i = 106;
	i -= 5;
	if (data->frame_counter % 2 == 0)
	{
		IMG(data->mlx, data->win, data->down, \
			(data->player_x * TW + 40), \
			(data->player_y * TH + 40) - i);
	}
	else
	{
		IMG(data->mlx, data->win, data->down1, \
			(data->player_x * TW + 40), \
			(data->player_y * TH + 40) - i);
	}
	if (i <= 0)
	{
		data->press = 0;
		data->reached = 1;
		i = 0;
	}
}

void	render_anime(t_data *data)
{
	if (!data->press && data->key == D)
		IMG(data->mlx, data->win, data->right, (data->player_x * \
			TW + 40), data->player_y * TH + 40);
	if (!data->press && data->key == A)
		IMG(data->mlx, data->win, data->left, (data->player_x * \
			TW + 40), data->player_y * TH + 40);
	if (!data->press && data->key == W)
		IMG(data->mlx, data->win, data->up, (data->player_x * \
			TW + 40), data->player_y * TH + 40);
	if (!data->press && data->key == S)
		IMG(data->mlx, data->win, data->down, (data->player_x * \
			TW + 40), data->player_y * TH + 40);
	else if (data->press && data->key == D)
		anime_right(data);
	else if (data->press && data->key == A)
		anime_left(data);
	else if (data->press && data->key == W)
		anime_up(data);
	else if (data->press && data->key == S)
		anime_down(data);
}
