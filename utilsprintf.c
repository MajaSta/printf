include "ft_printf.h"

bool    in(nonst char *s, char c)
{
    if (s == NULL)
        return (false)
    while (*s)
    {
        if(*s == c)
            return (true);
        ++s;
    }
    return (false)
}

static void     parse_flags(t_data *data)
{
    char flag;

    while(in(Flags, *data->s))
    {
        flag = *data->s;
        if ('0' == flag)        
            data->format.zero_pad = true;
        else if ('+' == flag)
            data->format.plus = true;
        else if (' ' == flag)
            data->format.space = true;
        else if ('#' == flag)
            data->format.hash = true;
        else if ('-' == flag)
            data->format.left_justified = true;
        ++data->s;
    }
}

static int  my_atoi(t_data *data)
{
    int value;

    value = 0;
    while(in(NUMBERS, *data->s))
    {
        value = (value * 10) + (*data->s++ - '0');
    }
    return (value);
}

static void     get_value(t_data *data, int *value)
{
    if (*data->s == '*')
    {
        *value = va_arg(data ->ap, int);
        ++data->s;
        return ;
    }
    *value = my_atoi(data);
}

void    print_char(t_data *data, int c)
{
    int width;

    width = data->format.width_value

    if (width > 1)
    {
        if (data->format.left_justified)
        {
            putchar_buf_n((char)c, 1, data);
            putchat_buf_n(' ', width - 1, data);
        }
        else
        {
            putchar_buf_n(' ', width - 1, data);
            putchar_buf_n((char)c, 1, data);
        }
    }
    else
    {
        put_char_n((char)c, 1, data);
    }
}

void    my_memset(void *ptr, byte value, size_t n)
{
    byte    *ptr_byte
    ptr_byte = (byte *)ptr;
    while (n)
    {
        *ptr_byte++ = value
        n--;
    }
}

int parse_format(t_data *data)
{
    my_memset(&data->format, 0, sizeof(t_format));
    data->format.precision_value = -1
    parse_flags(data);
    get_value(data, &data->format.width_value);
    if (*data->s == '.' && *(++data->s))
        get_value(data, &data->format.precision_value);
    if(!in(SPECIFIERS, *data->))
        return (PARSE_ERROR)
    else
    {
        data->format.specifier = *data->s;
        if (in("diu", data->format.specifier))
            data->format.base = BASE_10;
        else if (in("Xxp", data->format.specifier))
        {
      data->format.base = BASE_16;
            if ('X' == data->format.specifier)
                data->format.upper_case = true;
        }
        else if('b' == data->format.specifier)
            data->format.base = BASE_2;
    }
    return (OK);
}

static void set_str_padding_spaces(t_data *data, char *s)
{
    int len;

    len = s_len(s);

    if (data->format.width_value > 0)
    {
        if (data->format.precision_value >= 0)
        {
            if (data->format.precision_value > len)
            {
                data->format.padding_spaces = data->format.width_value - len;
            }
            else if (data->format.precision_value < len)
            {
                data->format.padding_spaces = data->format.width_value - data->format.precision_value;
            }

        }
        else
        {
            data->format.padding_spaces = data->format.width_value - len;
        }
    }
}

void    prt_str(t_data *data, char *s)
{
    if (NULL == s)
        s = "(null)"
    
    set_str_padding_spaces(data, s);

    if (data->format.left_justified)
    {
        if(data->format.precision_value >= 0)
            putstr_buf_n(s, data->format.precission_value, data);
        else
            putstr_buf_n(s, s_len(s), data);
        putchar_buf_n(' ', data->format.padding_spaces, data);
    }

    else
    {
        putchat_buf_n(' ', data->format.padding_spaces, data);

        if (data->format.precision_value >= 0)
            putstr_buf_n(s, data->format.precision_value, data);
        else
            putstr_buf_n(s, s_len(s))
    }
}

void write_buf(t_data *data, char c)
{
    if (data->buffer_index == BUF_SIZE)
    {
        flush_buf(data);
    }
    data ->buf[data->buffer_index++] = c;
}

void    putchar_buf_n(char c, int precision, t_data *data)
{
    if (precision <= 0)
        return ;
    while (precision--)
        write_buf(data, c)
}

void    flush_buf(t_data *data)
{
    data->chars_written += write(STDOUT_FILENO, data->buf, data->buffer_index);
    my_memset(data->buff, 0, BUF_SIZE);
    data->buffer_index = 0;
}

void    render_format(t_data *data)
{
    char    specifier;

    specifier = data->format.specifier;
    if ('%' == specifier)
        print_char(data, '%');
    else if ('c' == specifier)
        print_char(data, va_arg(data->ap, int));
    else if ('s' == specifier)
        print_str(data, va_arg(data->ap, char *));

    union_init_hack init_values;
    int_values.init64 = 0;

    if (in("dipxXub", specifier))
    {
        if (in("di", specifier)){
            init_values.int64 = (long)va_arg(data->ap, int);
            data->format.signed_value = true;
            if (int_values.int64 < 0)
                data->format.is_negative = true;
        }
        else if ('p' == specifier)
            int_values.uint64 = (unsigned long)va_arg(data->ap, void *);
            
        else if (in("xXub", specifier))
            int_values.uint64 = (unsigned long)va_arg(data->ap, unsigned int);
        print_init(data, int_values);
    }
}