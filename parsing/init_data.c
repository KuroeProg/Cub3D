#include "../cub3d.h"

void init_data(t_data *data)
{
    data->map_width = 0;
    data->map_height = 0;
    data->dirX = 0;
    data->dirY = 0;
    data->PlaneX = 0;
    data->PlaneY = 0;
    data->i = 0;
    data->j = 0;
	// deplace dans le main
    // if (!get_map_info(file_path, data))
    //     return (0);
	//Deja present dans get_map_info
    // if (!ft_parsing(data))
    //     return (0);
}
