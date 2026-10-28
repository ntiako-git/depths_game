#include "dp_utils.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    // --- Test de ft_strlen ---
    assert(ft_strlen("") == 0);
    assert(ft_strlen("Hello") == 5);
    assert(ft_strlen("C is awesome") == 12);

    // --- Test de ft_strcmp ---
    assert(ft_strcmp("abc", "abc") == 0);
    assert(ft_strcmp("abc", "abd") < 0);
    assert(ft_strcmp("abd", "abc") > 0);
    assert(ft_strcmp("", "") == 0);

    // --- Test de ft_strdup ---
    char *dup = ft_strdup("Test de duplication");
    assert(dup != NULL);
    assert(strcmp(dup, "Test de duplication") == 0);
    free(dup);

    char *empty_dup = ft_strdup("");
    assert(empty_dup != NULL);
    assert(ft_strlen(empty_dup) == 0);
    free(empty_dup);

    // --- Test de ft_putstr & ft_putnbr ---
    ft_putstr("--- Debut des tests d'affichage ---\n");

    ft_putstr("Test putstr : Succes !\n");

    ft_putstr("Test putnbr (0)     : ");
    ft_putnbr(0);
    ft_putstr("\n");

    ft_putstr("Test putnbr (42)    : ");
    ft_putnbr(42);
    ft_putstr("\n");

    ft_putstr("Test putnbr (-42)   : ");
    ft_putnbr(-42);
    ft_putstr("\n");

    ft_putstr("Test putnbr (INT_MIN): ");
    ft_putnbr(INT_MIN);
    ft_putstr("\n");

    ft_putstr("--- Tous les assertions ont passe avec succes ! ---\n");
    return (0);
}