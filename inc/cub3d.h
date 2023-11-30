#include "../Lib/Libft/inc/libft.h"
#include "../Lib/Libft/inc/get_next_line.h"
#include "../Lib/minilibx/mlx.h"

#include <fcntl.h>
#include <stdbool.h>

# define SIZE_MINMAP 11
# define MID_MIMMAP 6

/* char position in map struct, kquetat- */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;


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
	int		pos_x;
	int		pos_y;
	int		pos_p_x;
	int		pos_p_y;
	/*
	mlx window
	donnees parsing
	map**
	*/
}	t_config;

typedef struct s_bdd
{
	t_image		wall;
	t_image		floor;
	t_image		player;
	t_image		empty;
}				t_bdd;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	t_bdd	bdd;
	t_window	window;
}				t_vars;

/*	MINIMAP	*/


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

/*	MINI_MAP.C	*/

void	load_img(t_vars *vars);
int	load_map(t_config **conf, t_vars *vars);
int		create_trgb(int t, int r, int g, int b);

// int	ft_close(t_vars *vars);