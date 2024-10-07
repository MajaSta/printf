#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

// Główna funkcja printf
int		ft_printf(const char *str, ...);

/* Funkcje formatujące */
// Wydrukuj pojedynczy znak i zwiększ licznik
void	ft_putchar_pf(char c, size_t *counter);

// Wydrukuj ciąg znaków i zwiększ licznik. Jeśli NULL, wydrukuj "(null)"
void	ft_putstr_pf(char *str, size_t *counter);

// Wydrukuj liczbę całkowitą w systemie dziesiętnym i zwiększ licznik
void	ft_putnbr_pf(int num, size_t *counter);

// Wydrukuj liczbę całkowitą bez znaku w systemie dziesiętnym i zwiększ licznik
void	ft_putuint_pf(unsigned int num, size_t *counter);

// Wydrukuj liczbę w formacie szesnastkowym (małe lub duże litery) i zwiększ licznik
void	ft_puthex_pf(unsigned int num, size_t *counter, char *base);

// Wydrukuj adres wskaźnika w formacie szesnastkowym i zwiększ licznik
void	ft_putptr_pf(void *ptr, size_t *counter);

/* Funkcje pomocnicze */
// Konwertuje liczbę na ciąg znaków w określonym systemie liczbowym (np. szesnastkowym)
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

/* format functions */
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putstr_pf(char *str, size_t *counter);
void	ft_putnbr_pf(int num, size_t *counter);
void	ft_putuint_pf(unsigned int num, size_t *counter);
void	ft_puthex_pf(unsigned int num, size_t *counter, char *base);
void	ft_putptr_pf(void *ptr, size_t *counter);

/* auxiliary functions */
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
