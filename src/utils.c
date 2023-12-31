/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:30:59 by aydemir           #+#    #+#             */
/*   Updated: 2022/12/05 20:22:10 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xy_operation(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*x = 0;
		*y += 64;
	}
	else
		*x += 64;
}

void	ft_render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	ft_put_image(data);
}

int	ft_check_movement(t_data *data, int x, int y)
{
	if (data->map2[y][x] != '1')
	{
		if (data->map2[y][x] == 'C')
			data->food_count--;
		else if (!data->food_count && data->map2[y][x] == 'E')
		{
			ft_printf("Move: %d\nCongratulations!", ++(data->move_count));
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
		if (data->map2[y][x] == 'E')
			return (0);
		ft_printf("Move: %d\n", ++(data->move_count));
		return (1);
	}
	return (0);
}

void	ft_fe_count_check(t_data *data)
{
	if (data->food_count < 1 || data->exit_count != 1
		|| data->player_count != 1)
		ft_error("Error! Map must include 1P or 1C or 1E.", data);
}

void	ft_score(t_data *data)
{
	data->move_count_screen = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 30, 30, 0xFFFFFF, \
	"Move: ");
	mlx_string_put(data->mlx, data->window, 65, 30, 0xFFFFFF, \
		data->move_count_screen);
	free(data->move_count_screen);
}
