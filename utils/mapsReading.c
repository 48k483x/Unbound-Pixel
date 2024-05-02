/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsReading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 06:43:40 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:51:27 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**add_to_map(char **map, char *new_line)
{
	int		i;
	int		size;
	char	**new_map;

	i = 0;
	size = 0;
	while (map && map[size])
		size++;
	new_map = malloc(sizeof(char *) * (size + 2));
	if (!new_map)
		return (NULL);
	while (i < size)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

int	validate_map_walls(char **map, t_data *data)
{
	int	i;
	int	size;

	size = 0;
	while (map[size])
		size++;
	i = 0;
	while (map[0][i] && map[size - 1][i])
	{
		if (map[0][i] != '1' || map[size - 1][i] != '1')
			return (0);
		i++;
	}
	data->map_wid = i;
	i = 0;
	while (i < size)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
			return (1);
		i++;
	}
	data->map_hei = i;
	return (1);
}

int	dfs(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->map_hei || y < 0 || y >= data->map_wid || \
			data->map[x][y] == '1' || visited[x][y])
		return (0);
	if (data->map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (dfs(data, x + 1, y, visited) || dfs(data, x - 1, y, visited) || \
			dfs(data, x, y + 1, visited) || dfs(data, x, y - 1, visited))
		return (1);
	return (0);
}

int	validate_way(t_data *data)
{
	int		i;
	int		j;
	int		result;
	int		**visited;

	visited = malloc(sizeof(int *) * data->map_hei);
	if (!visited)
		return (0);
	i = 0;
	while (i < data->map_hei)
	{
		visited[i] = malloc(data->map_wid * sizeof(int));
		if (!visited[i])
			return (0);
		j = 0;
		while (j < data->map_wid)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	result = dfs(data, data->playerx, data->playery, visited);
	free_visited(data, visited);
	return (result);
}

int	validate_map(t_data *data)
{
	init_var(data);
	while (data->map[data->x])
	{
		data->y = 0;
		while (data->map[data->x][data->y])
		{
			if (data->map[data->x][data->y] == 'P')
			{
				data->player_c++;
				data->playerx = data->x;
				data->playery = data->y;
			}
			else if (data->map[data->x][data->y] == 'E')
				data->exit_c++;
			else if (data->map[data->x][data->y] == 'C')
				data->collectible++;
			data->y++;
		}
		data->x++;
	}
	if (data->player_c != 1 || data->exit_c != 1 || data->collectible < 1 || \
			!validate_map_walls(data->map, data) || \
			!validate_way(data))
		return (0);
	return (1);
}
