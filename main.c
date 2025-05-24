#include "./cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (argc != 2)
		return (0);
	if (!get_map_info(&data, argv[1]))
		ft_printf(1, "Invalide\n");
	else
		ft_printf(1, "Valide\n");
	display_map(&data);
	return (0);
	// if (!init_data(data, argv[1]))
	// {
	// 	// free function	
	// 	return (0);
	// }
}
