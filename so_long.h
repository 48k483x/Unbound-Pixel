/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:39:17 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:45:21 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "mlx.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define TW 106
# define TH 106
# define ANIMATION_SPEED 100
# define WINDOW_WID 1481
# define WINDOW_HEI 635
# define BUFFER_SIZE 10 
# define W 13
# define D 2
# define A 0
# define S 1
# define ESC 53
# define IMG mlx_put_image_to_window
# define WIN mlx_new_window
# define XPM mlx_xpm_file_to_image

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_mlx
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*background_img;
	void	*up;
	void	*up1;
	void	*right;
	void	*right1;
	void	*left;
	void	*left1;
	void	*down;
	void	*down1;
	void	*enemy;
	void	*enemy1;
	void	*collectible_img[6];
	void	*exit_img;
	void	*wall_img;
	void	*empty_img;
	int		player_frame;
	int		current_frame;
	int		player_x;
	int		player_y;
	int		start_x;
	int		start_y;
	int		map_wid;
	int		map_hei;
	int		collectible;
	int		player_direction;
	int		press;
	int		key;
	int		reached;
	int		frame_counter;
	int		moves;
	int		i;
	int		j;
	int		x;
	int		y;
	int		player_c;
	int		exit_c;
	int		playerx;
	int		playery;
	int		fd;
}	t_data;

int		found_newline(t_list *list);
t_list	*find_lst_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	polish_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
char	**add_to_map(char **map, char *new_line);
int		validate_map(t_data *data);
int		validate_map_walls(char **map, t_data *data);
int		window_init(t_data *data);
int		key_press(int key, t_data *d);
void	move_player(int key, t_data *d);
int		exit_game(t_data *data, char *s);
int		error_mssg(char *s, int ERR_TYPE);
int		draw_game(t_data *d);
int		init_game(t_data *data);
int		standar_animation(t_data *data);
int		check_map_row_len(t_data *data);
int		draw_background(t_data *data);
void	collectible_function(char **filenames);
int		init_player(t_data *data);
int		check(int c);
void	anime_right(t_data *data);
void	render_anime(t_data *data);
void	anime_left(t_data *data);
void	anime_up(t_data *data);
void	anime_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	all_moves(int key, t_data *data);
void	free_visited(t_data *data, int **visited);
int		ft_strlen(char *str);
int		dfs(t_data *data, int x, int y, int **visited);
int		validate_way(t_data *data);
void	collectibles_init(t_data *data, int wid, int hei);
size_t	count_word_str(long nb);
void	*allocation_str(size_t len);
char	*if_zero(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	init_var(t_data *data);
char	*ft_strnstr(const char *big, const char *little, size_t len);
#endif /* SO_LONG_H  */
