#include "cub3d.h"

void	ft_check_textures(t_game *game, char *str)
{
	int	control[4];
	int	check[2];
	
	if (!strncmp(str, "NO", 2))
		control[0] == 1;
	if (!strncmp(str, "SO", 2))
		control[1] == 1;
	if (!strncmp(str, "EA", 2))
		control[2] == 1;
	if (!strncmp(str, "WE", 2))
		control[3] == 1;
	if (!strncmp(str, "C", 1))
		check[0] = 1;
	if (!strncmp(str, "F", 1))
		check[0] = 1;
	if (control[0] == 1 && control[1] == 1 && control[2] == 1 && control[3] == 1
		&& check[0] == 1 && check[1] == 1)
		return (1);
	else
		return 0;
}

void	ft_parse_textures(t_game *game, char *line, t_parse *parse)
{
	char *str;
	char *path[2];
	char **c_f;

	str = ft_strtrim(line);
	path = ft_split(str, str[1]);
	if (ft_check_textures(&game, str))
	{
		if (!strcmp(str[0], "N") && !strcmp(str[1], "O"))
			parse->NO_path = path;
		else if (!strcmp(str[0], "S") && !strcmp(str[1], "O"))
			parse->SO_path = path;
		else if (!strcmp(str[0], "W") && !strcmp(str[1], "E"))
			parse->EA_path = path;
		else if (!strcmp(str[0], "E") && !strcmp(str[1], "A"))
			parse->WE_path = path;
		else if (str[0] == "F")
		{
			c_f = ft_split(str, ",");
			F_rgb[0] = ft_atoi(c_f[0]);
			F_rgb[1] = ft_atoi(c_f[1]);
			F_rgb[2] = ft_atoi(c_f[2]);
		}
		else if (str[0] == "C")
		{
			c_f = ft_split(str, ",");
			F_rgb[0] = ft_atoi(c_f[0]);
			F_rgb[1] = ft_atoi(c_f[1]);
			F_rgb[2] = ft_atoi(c_f[2]);
		}
	}
	else
	{
		printf("Error: file .cub\n");
		exit(1);
	}
}

char	**ft_check_map(char **map)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	while (map[y])
	{
		str = ft_strtrim(map[y]);
		x = 0;
		while (str[x])
		{
			if (y == 0 && str[x] != "1")
				return (1);
			if ((x == 0 && str[x] != "1") || (x == ft_strlen(str) - 1 && str[x]
				!= "1"))
				return (1);
			x++;
		}
		y++;
	}
	while (str[x])
	{	
		if (str[x] != '1')
			return (1);
		x++;
	}
	return (map);
}

void	open_map() //legge il parse e apre la mappa con funzioni di minilbx


char	**ft_read_map(t_game *game, char *argv, t_parse *parse)
{
	int	fd;
	int	i;
	int	j;
	char	*line;
	char	**map;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		ft_parse_textures(&game, line, &parse);
		if (!strcmp(line, ""))
			;
		else if (j < 6)
			j++;
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	while (line)
	{
		if (!strcmp(line, ""))
			;
		map[i] = malloc(sizeof(char) * ft_strlen(line))
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (ft_check_map(map))
	{
		free(map);
		printf("Error: invalid map\n");
		exit(1);
	}
	else
		return (map);
}
