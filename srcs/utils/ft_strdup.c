#include "dp_utils.h"

char	*ft_strdup(const char *src) {
    size_t  len;
    char    *dst;
    int     i;

    if (src == NULL)
        return NULL;
    len = ft_strlen(src);
    dst = malloc(sizeof(char) * (len + 1));
    if (!dst)
        return NULL;
    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}