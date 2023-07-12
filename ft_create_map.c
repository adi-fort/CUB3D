#include "cub3d.h"

void	ft_parse_textures(t_game *game, char *line, t_parse *parse)
{
	char *str;
	char *path[2];

	str = ft_strtrim(line, " ");
	path = ft_split(str, str[1]); 
	if (!strcmp(str[0], "N") && !strcmp(str[1], "O"))
		parse->NO_path = path;
	else if (!strcmp(str[0], "S") && !strcmp(str[1], "O"))
		parse->SO_path = path;
	else if (!strcmp(str[0], "W") && !strcmp(str[1], "E"))
		parse->EA_path = path;
	else if (!strcmp(str[0], "E") && !strcmp(str[1], "A"))
		parse->WE_path = path;
	else if (str[0] == "F")
		parse->F_rgb = ft_atoi(path[2]);
	else if (str[0] == "C")
		parse->C_rgb = ft_atoi(path[2]);
	else
	{
		printf("Error: file .cub\n");
		exit(1);	
	}
}

char	**ft_check_map(char **map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	//checK:
	//tutti 1 intorno
	//solo un NWES
	//gli spazi valgono come 1
	//almeno 4x4
	
	return (map);
}

void	open_map() //legge il parse e apre la mappa con funzioni di minilbx


char	**ft_read_map(t_game *game, char *argv, t_parse *parse) //stora le 6 info di .cub nella struct e ritorna la mappa allocata
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
		if (!strcmp(line, "")) //se la stringa é vuota
			i++;
		else if (j < 6) //se la stringa non é vuota e se sono meno di 6 stringhe
			j++; //arriva fino a sei
		else //quando arrivi a 6
			break ; //esci dal ciclo
	}
	i = 0;
	while (line)
	{
		map[i] = malloc(sizeof(char) * ft_strlen(line))
		i++;
	}
	close(fd);
	if (ft_check_map(map))
	{
		
		//free(un sacco di robba);
		printf("Error: invalid map\n");
		exit(1);
	}
	else
		return (map);
}
