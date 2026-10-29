#include "dp_entity.h"

void    dp_entity_push_back(t_entity **list, t_entity *new)
{
    t_entity    *current;

    if (list == NULL || new == NULL)
        return ;
    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    current = *list;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
}

t_entity    *dp_entity_at(t_entity *list, int x, int y)
{
    t_entity    *tmp;

    tmp = list;
    while (tmp != NULL)
    {
        if (tmp->x == x && tmp->y == y)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void    dp_entity_remove_at(t_entity **list, int x, int y)
{
    t_entity    *tmp;
    t_entity    *prev;

    if (list == NULL || *list == NULL)
        return ;
    if ((*list)->x == x && (*list)->y == y)
    {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
        return ;
    }
    prev = *list;
    tmp = (*list)->next;
    while (tmp != NULL)
    {
        if (tmp->x == x && tmp->y == y)
        {
            prev->next = tmp->next;
            free(tmp);
            return ;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void    dp_entity_clear(t_entity **list)
{
    t_entity    *tmp;

    if (list == NULL)
        return ;
    while (*list != NULL)
    {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
    *list = NULL;
}