/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:32:06 by vmelkony          #+#    #+#             */
/*   Updated: 2021/06/11 18:27:36 by vmelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_data *img, const int w, const int h, const int color);

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "Hi!");
	img.img = mlx_new_image(mlx, 200, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	draw_square(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 50, 50);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *img, const int w, const int h, const int color)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}
