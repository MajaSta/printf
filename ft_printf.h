#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define BUF_SIZE 1024
#define OK 0
#define MALLOC_ERROR -1
#define PARSE_ERROR -2

// Data structure for formatting
typedef struct s_format
{
    int width_value;
    int precision_value;
    int padding_spaces;
    bool zero_pad;
    bool plus;
    bool space;
    bool hash;
    bool left_justified;
    bool signed_value;
    bool is_negative;
    char specifier;
    int base;
    bool upper_case;
} t_format;

// Data structure to hold all the information
typedef struct s_data
{
    int chars_written;
    char *buf;
    int buffer_index;
    va_list ap;
    const char *s;
    t_format format;
} t_data;

// Function prototypes
bool in(const char *s, char c);
static void parse_flags(t_data *data);
static int my_atoi(t_data *data);
static void get_value(t_data *data, int *value);
void print_char(t_data *data, int c);
void my_memset(void *ptr, int value, size_t n);
int parse_format(t_data *data);
static void set_str_padding_spaces(t_data *data, char *s);
void print_str(t_data *data, char *s);
void write_buf(t_data *data, char c);
void putchar_buf_n(char c, int precision, t_data *data);
void flush_buf(t_data *data);
void render_format(t_data *data);
static int init_data(t_data *data, const char *fmt);
int ft_printf(const char *fmt, ...);

#endif // FT_PRINTF_H
