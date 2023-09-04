/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

void	check_cub (char *str)
{
	int		i;
	char	*str2;

	i = ft_strlen(str);
	str2 = &str[i - 4];
	if (ft_strncmp((const char *)str2, ".cub", 4) != 0)
	{
		write(2, "Error: need .cub file\n", 23);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_cub(argv[1]);
	if (parsing(argc, argv, &game) != 0)
		return (1);
	init(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, input_on_press, (void *)&game);
	mlx_hook(game.mlx_win, 3, 1L << 1, input_on_release, (void *)&game);
	mlx_loop_hook(game.mlx, draw_frame, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
