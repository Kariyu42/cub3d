#include "cub3d.h"
#include "err_type.h"

int	skip(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

char	*get_texture_path_no(t_config **conf)
{
	int		len;
	int		i;
	int		j;
	char	*path;
	char	*texture;

	texture = (*conf)->file[(*conf)->no_find];
	i = skip(texture);
	len = i;
	while (texture[len] && texture[len] != ' ' && texture[len] != '\t')
		len++;
	path = malloc(sizeof(char) * (len - (*conf)->no_find + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (texture[i] && texture[i] != ' ' && texture[i] != '\t' && \
	texture[i] != '\n')
		path[j++] = texture[i++];
	path[j] = '\0';
	while (texture[i] && (texture[i] == ' ' || texture[i] == '\t'))
		i++;
	if (texture[i] && texture[i] != '\n')
	{
		free(path);
		path = NULL;
	}
	texture[i] = '\0';
	return (path);
}

char	*get_texture_path_so(t_config **conf)
{
	int		len;
	int		i;
	int		j;
	char	*path;
	char	*texture;

	texture = (*conf)->file[(*conf)->so_find];
	i = skip(texture);
	len = i;
	while (texture[len] && texture[len] != ' ' && texture[len] != '\t')
		len++;
	path = malloc(sizeof(char) * (len - (*conf)->no_find + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (texture[i] && texture[i] != ' ' && texture[i] != '\t' && \
	texture[i] != '\n')
		path[j++] = texture[i++];
	path[j] = '\0';
	while (texture[i] && (texture[i] == ' ' || texture[i] == '\t'))
		i++;
	if (texture[i] && texture[i] != '\n')
	{
		free(path);
		path = NULL;
	}
	texture[i] = '\0';
	return (path);
}

char	*get_texture_path_we(t_config **conf)
{
	int		len;
	int		i;
	int		j;
	char	*path;
	char	*texture;

	texture = (*conf)->file[(*conf)->we_find];
	i = skip(texture);
	len = i;
	while (texture[len] && texture[len] != ' ' && texture[len] != '\t')
		len++;
	path = malloc(sizeof(char) * (len - (*conf)->no_find + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (texture[i] && texture[i] != ' ' && texture[i] != '\t' && \
	texture[i] != '\n')
		path[j++] = texture[i++];
	path[j] = '\0';
	while (texture[i] && (texture[i] == ' ' || texture[i] == '\t'))
		i++;
	if (texture[i] && texture[i] != '\n')
	{
		free(path);
		path = NULL;
	}
	texture[i] = '\0';
	return (path);
}

char	*get_texture_path_ea(t_config **conf)
{
	int		len;
	int		i;
	int		j;
	char	*path;
	char	*texture;

	texture = (*conf)->file[(*conf)->ea_find];
	i = skip(texture);
	len = i;
	while (texture[len] && texture[len] != ' ' && texture[len] != '\t')
		len++;
	path = malloc(sizeof(char) * (len - (*conf)->no_find + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (texture[i] && texture[i] != ' ' && texture[i] != '\t' && \
	texture[i] != '\n')
		path[j++] = texture[i++];
	path[j] = '\0';
	while (texture[i] && (texture[i] == ' ' || texture[i] == '\t'))
		i++;
	if (texture[i] && texture[i] != '\n')
	{
		free(path);
		path = NULL;
	}
	texture[i] = '\0';
	return (path);
}
