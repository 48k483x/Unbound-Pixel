/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:47:32 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 06:55:51 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collectibles_init(t_data *data, int wid, int hei)
{
	int		i;
	char	*collectibles[6];

	collectible_function(collectibles);
	i = 0;
	while (i < 6)
	{
		data->collectible_img[i] = \
			mlx_xpm_file_to_image(data->mlx, collectibles[i], &wid, &hei);
		if (!data->collectible_img[i])
			exit_game(data, "Error loading images\n");
		i++;
	}
	data->exit_img = XPM(data->mlx, "assets/e1.xpm", &wid, &hei);
}

int	init_game(t_data *data)
{
	int	wid;
	int	hei;

	hei = 0;
	wid = 0;
	collectibles_init(data, wid, hei);
	data->press = 0;
	data->key = S;
	data->reached = 1;
	data->moves = 0;
	data->up = XPM(data->mlx, "assets/up.xpm", &wid, &hei);
	data->up1 = XPM(data->mlx, "assets/up1.xpm", &wid, &hei);
	data->left = XPM(data->mlx, "assets/lf.xpm", &wid, &hei);
	data->left1 = XPM(data->mlx, "assets/lf1.xpm", &wid, &hei);
	data->right = XPM(data->mlx, "assets/rt.xpm", &wid, &hei);
	data->right1 = XPM(data->mlx, "assets/rt1.xpm", &wid, &hei);
	data->down = XPM(data->mlx, "assets/dn.xpm", &wid, &hei);
	data->down1 = XPM(data->mlx, "assets/dn1.xpm", &wid, &hei);
	data->empty_img = XPM(data->mlx, "assets/wk.xpm", &wid, &hei);
	data->wall_img = XPM(data->mlx, "assets/wl.xpm", &wid, &hei);
	data->enemy = XPM(data->mlx, "assets/sk.xpm", &wid, &hei);
	data->enemy1 = XPM(data->mlx, "assets/sk1.xpm", &wid, &hei);
	if (!data->empty_img || !data->wall_img || !data->exit_img || !data->enemy)
		exit_game(data, "Error loading tile images\n");
	return (1);
}

int	draw_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_hei)
	{
		j = 0;
		while (j < data->map_wid)
		{
			if (data->map[i][j] == '1')
				IMG(data->mlx, data->win, data->wall_img, j * TW, \
					i * TH);
			else
				IMG(data->mlx, data->win, data->empty_img, j * TW, \
					i * TH);
			j++;
		}
		i++;
	}
	return (1);
}

int	draw_game(t_data *d)
{
	d->i = 0;
	while (d->i < d->map_hei)
	{
		d->j = 0;
		while (d->j < d->map_wid)
		{
			if (d->map[d->i][d->j] == '0')
				IMG(d->mlx, d->win, d->empty_img, d->j * TW, d->i * TH);
			else if (d->map[d->i][d->j] == '1')
				IMG(d->mlx, d->win, d->wall_img, d->j * TW, d->i * TH);
			else if (d->map[d->i][d->j] == 'E')
				IMG(d->mlx, d->win, d->exit_img, d->j * TW, d->i * TH + 40);
			else if (d->map[d->i][d->j] == 'C')
				IMG(d->mlx, d->win, \
					d->collectible_img[d->current_frame % 6], \
					d->j * TW, d->i * TH);
			else if (d->map[d->i][d->j] == 'X')
				IMG(d->mlx, d->win, d->enemy, d->j * TW, d->i * TH);
			d->j++;
		}
		d->i++;
	}
	render_anime(d);
	return (1);
}

int	window_init(t_data *data)
{
	int	window_wid;
	int	window_hei;

	window_wid = data->map_wid * TW;
	window_hei = data->map_hei * TH;
	data->mlx = mlx_init();
	data->win = WIN(data->mlx, window_wid, window_hei, "So Long");
	if (!data->mlx || !data->win)
		return (0);
	mlx_hook(data->win, 17, 0, exit_game, data);
	if (!init_game(data))
		error_mssg("Error initializing game\n", 0);
	if (!draw_background(data))
		error_mssg("Error drawing game\n", 0);
	// init_player(data);
	// mlx_hook(data->win, 2, 0, key_press, data);
	// mlx_loop_hook(data->mlx, standar_animation, data);
	mlx_loop(data->mlx);
	return (1);
}
