#include "../Lib/Libft/inc/libft.h"
#include "../Lib/Libft/inc/get_next_line.h"
#include "../Lib/minilibx/mlx.h"

#include <fcntl.h>
#include <stdbool.h>

/* char position in map struct, kquetat- */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_config
{
	char	**data;
	char	**map;
	char	**file;
	int		file_size;
	int		map_loc;
	int		map_len;
	bool	anomaly; // kquetat-
	int		player; // kquetat-
	int		count_data; // epraduro
	char	*no_text;// epraduro
	char 	*so_text;// epraduro
	char 	*we_text;// epraduro
	char 	*ea_text;// epraduro
	int		no_find;
	int		so_find;
	int		we_find;
	int		ea_find;
	int 	f_find;// epraduro
	int 	c_find;// epraduro
	char	**f_color;// epraduro
	char	**c_color;// epraduro
	/*
	mlx window
	donnees parsing
	map**
	*/
}	t_config;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

/* --- PARSING --- kquetat- */
int		parse_data(t_config **conf, char **av);
int		find_map(t_config **conf);
int		map_len(t_config **conf);
int		text_size(char **av, int fd);
char	*trim_newline(char *str, char c);
bool	inspect_line(t_config **conf, char *map_line, char *to_find);
int		longest_line(char **map);

/* INSPECT_MAP functions kquetat- */
char	*fill_map(char *map, char *tmp, int line_len);
char	*fill_extremities(char *tmp, int line_len);
bool	flood_fill(t_config **conf, char **tmp);

/* PRINT MAP WHEN ALREADY STOCKED (must be removed before push) */
void	print_map(char **map);


/* --- epraduro --- */

/*	GET_TEXTURE.C	*/
int		skip(char *line);
int	get_colors(t_config **conf, int i);
int	get_textures(t_config **conf, int i);
int		get_texture_path(char *str, char **store_data, int *data);

/*	CHECK_COLOR.C	*/
int	ft_strcmp(char *s1, char *s2);
int	same_color(t_config **conf);
int	len_tab(char **tab);
int	valid_color(char **color);
int	check_color(char ***color, char *str, int *data);

/*	MAP_DATA.C	*/
bool	is_dir(char *arg);
int	check_path(char *arg);
int check_data(t_config **conf);

char *format_path_texture(char *str);

int ft_contain(char *str, char *find);

// int	ft_close(t_vars *vars);