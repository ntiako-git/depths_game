#include "dp_map.h"

static int	dp_fetch_file_size(const char *path, size_t *size)
{
    int     fd;
    ssize_t bytes_read;
    char    buffer[4096];

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    *size = 0;
    while (1)
    {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            close(fd);
            return -1; // Handle error
        }
        if (bytes_read == 0)
            break; // End of file
        *size += bytes_read;
    }
    close(fd);
    return 0;
}

static int	dp_read_file(const char *path, char *content, size_t total_size)
{
    int		fd;
    ssize_t	bytes_read;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    bytes_read = read(fd, content, total_size);
    close(fd);
    if (bytes_read < 0)
        return -1;
    content[bytes_read] = '\0';
    return 0;
}

static int	dp_check_line_len(char *content, int *i, int target_w)
{
    int	current_w;

    current_w = 0;
    while (content[*i] && content[*i] != '\n' && content[*i] != '\r')
    {
        current_w++;
        (*i)++;
    }
    if (current_w > 0 && current_w != target_w)
        return -1;
    return current_w;
}

static t_map_err    dp_parse_dimensions(char *content, t_map *map)
{
    int	i;
    int	h;
    int current_w;

    map->w = 0;
    while (content[map->w] && content[map->w] != '\n' && content[map->w] != '\r')
        map->w++;
    if (map->w == 0)
        return MAP_ERR_SHAPE;
    h = 0;
    i = 0;
    while (content[i])
    {
        current_w = dp_check_line_len(content, &i, map->w);
        if (current_w == -1)
            return (MAP_ERR_SHAPE);
        if (current_w > 0)
            h++;
        while (content[i] == '\n' || content[i] == '\r')
            i++;
    }
    map->h = h;
    return MAP_OK;
}

static t_map_err	dp_build_grid(char *content, t_map *map)
{
    int	i;
    int	y;
    int	x;

    map->grid = malloc(sizeof(char *) * map->h);
    if (!map->grid)
        return MAP_ERR_ALLOC;
    i = 0;
    y = -1;
    while (++y < map->h)
    {
        map->grid[y] = malloc(sizeof(char) * (map->w + 1));
        if (!map->grid[y])
        {
            dp_map_free(map);
            return MAP_ERR_ALLOC;
        }
        x = -1;
        while (++x < map->w)
            map->grid[y][x] = content[i + x];
        map->grid[y][map->w] = '\0';
        i += map->w;
        while (content[i] == '\n' || content[i] == '\r')
            i++;
    }
    return MAP_OK;
}

t_map_err	dp_map_load(const char *path, t_map *map)
{
    size_t  total_size;
    char    *content;
    t_map_err	err;

    if (dp_fetch_file_size(path, &total_size) == -1)
        return MAP_ERR_IO;
    if (total_size == 0)
        return MAP_ERR_SHAPE;
    content = malloc(sizeof(char) * (total_size + 1));
    if (!content)
        return MAP_ERR_ALLOC;
    if (dp_read_file(path, content, total_size) == -1)
    {
        free(content);
        return MAP_ERR_IO;
    }
    err = dp_parse_dimensions(content, map);
    if (err == MAP_OK)
        err = dp_build_grid(content, map);
    free(content);
    return err;
}