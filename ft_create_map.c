#include "cub3d.h"

char	*ft_parse_textures(t_game *game, char *argv)
{
		
}

char	**ft_parse_map(t_game *game, char *argv)
{
	
}

char	**ft_read_map(t_game *game, char *argv)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		ft_parse_textures(t_game *game, char *argv);
		if (!strcmp(line, "")) //se la stringa é vuota
			i++;
		else if (j < 6) //se la stringa non é vuota e se sono meno di 6 stringhe
			j++; //arriva fino a sei
		else //quando arrivi a 6
			break ; //esci dal ciclo
	}
	while (line)
		ft_parse_map(t_game *game, char *argv)
	close(fd);
}
