/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/07/11 15:21:44 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window (game.mlx, 1920, 1080, "CUB3D");
	mlx_loop(game.mlx);
	if (argv[1])
		ft_read_map(&game, argv[1]);
	else
		return (1);
	//inserire texture
	//inserire personaggio
	//
	//keyhook
	
}
