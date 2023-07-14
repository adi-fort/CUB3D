/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/07/14 12:14:56 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window (game.mlx, 1920, 1080, "CUB3D");
		if (argv[1])
			ft_read_map(&game, &argv[1]);
		else
			return (1);
		mlx_loop(game.mlx);
	}
	return (0);
}
