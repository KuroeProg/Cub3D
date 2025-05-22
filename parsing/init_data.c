#include "../cub3d.h"

int init_data(t_data *data, char *file_path)
{
    data->map_width = 0;
    data->map_height = 0;
    data->dirX = 0;
    data->dirY = 0;
    data->PlaneX = 0;
    data->PlaneY = 0;
    data->i = 0;
    data->j = 0;
    if (!get_map_info(file_path, data))
        return (0);
    if (!ft_parsing(data))
        return (0);
    return (1);
}
