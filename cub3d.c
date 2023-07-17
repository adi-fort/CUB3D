/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/07/17 11:04:24 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_parse	parse;
	char	**map;
	
	if (argc != 2)
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	else
	{
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window (game.mlx, 1920, 1080, "CUB3D");
		map = ft_read_map(&game, argv[1], &parse);
		mlx_loop(game.mlx);
	}
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	return (0);
}
