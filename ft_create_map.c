#include "cub3d.h"

int	ft_check_textures(char *str)
{
	static int	control[4];
	static int	check[2];
	
	if (!ft_strncmp(str, "NO", 3))
		control[0] = !ft_strncmp(str, "NO", 3);
	if (!ft_strncmp(str, "SO", 3))
		control[1] = !ft_strncmp(str, "SO", 3);
	if (!ft_strncmp(str, "EA", 3))
		control[2] = !ft_strncmp(str, "EA", 3);
	if (!ft_strncmp(str, "WE", 3))
		control[3] = !ft_strncmp(str, "WE", 3);
	if (!ft_strncmp(str, "C", 2))
		check[0] = !ft_strncmp(str, "C", 2);
	if (!ft_strncmp(str, "F", 2))
		check[0] = !ft_strncmp(str, "F", 2);
	if (control[0] == 1 && control[1] == 1 && control[2] == 1 && control[3] == 1
		&& check[0] == 1 && check[1] == 1)
		return (1);
	else
		return (0);
}

void	ft_parse_textures(char *line, t_parse *parse)
{
	char *str;
	char **path;
	char **c_f;

	str = ft_strtrim(line, " ");
	path = ft_split(str, str[1]);
	if (ft_check_textures(str))
	{
		if (!ft_strncmp(str, "N0", 3))
			parse->NO_path = path[1];
		else if (!ft_strncmp(str, "S0", 3))
			parse->SO_path = path[1];
		else if (!ft_strncmp(str, "WE", 3))
			parse->EA_path = path[1];
		else if (!ft_strncmp(str, "EA", 3))
			parse->WE_path = path[1];
		else if (str[0] == 'F')
		{
			c_f = ft_split(str, ',');
			parse->F_rgb[0] = ft_atoi(c_f[0]);
			parse->F_rgb[1] = ft_atoi(c_f[1]);
			parse->F_rgb[2] = ft_atoi(c_f[2]);
		}
		else if (str[0] == 'C')
		{
			c_f = ft_split(str, ',');
			parse->C_rgb[0] = ft_atoi(c_f[0]);
			parse->C_rgb[1] = ft_atoi(c_f[1]);
			parse->C_rgb[2] = ft_atoi(c_f[2]);
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
	size_t	x;
	char	*str;
	int		pos_counter;

	pos_counter = 0;
	y = 0;
	while (map[y])
	{
		str = ft_strtrim(map[y], " ");
		x = 0;
		while (str[x])
		{
			if (y == 0 && str[x] != '1')
				return (0);
			if ((x == 0 && str[x] != '1') || (x == ft_strlen(str) - 1 && str[x]
				!= '1'))
				return (0);
			if (str[x] == 'N' || str[x] == 'W' || str[x] == 'E' || str[x] == 'S')
				pos_counter++;
			x++;
		}
		y++;
	}
	if (pos_counter != 1)
		return (0);
	while (str[x])
	{	
		if (str[x] != '1')
			return (0);
		x++;
	}
	return (map);
}

/*void	open_map()
{
	check int F_rgb && C_rgb >= 0 && <= 255

}*/


char	**ft_read_map(t_game *game, char *argv, t_parse *parse)
{
	int	fd;
	int	i;
	int	j;
	char	*line;
	char	**map;
	
	(void)game;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		ft_parse_textures(line, parse);
		if (*line == '\0')
			;
		else if (j < 6)
			j++;
		else
			break ;
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	map = malloc(sizeof(char *) * 100);
	while (line)
	{
		if (*line != '\0')
		{
			map[i] = malloc(sizeof(char) * ft_strlen(line));
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	map[i] = 0;
	close(fd);
	if (ft_check_map(map))
		return (map);
	else
	{
		while (map);
		printf("Error: invalid map\n");
		return (0);
	}
}
