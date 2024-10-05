include "ft_printf.h"

static int  init_data(t_data *data, const char *ftm)
{
    data->chars_written = 0;
    data->s = fmt;
    data->buf = malloc(BUF_SIZE * sizeof(char));

    if (NULL == data->buf)
        return(MALLOC_ERROR);
    data->buffer_index = 0;
    my_memset(data->buf, 0, BUF_SIZE * sizeof(char));

    return (OK);

}

int ft_printf(const char *fmt, ...)
{
    t_data  data;

    va_start(data.ap, ftm)

    if  init_data(&data, fmt)
        return (MALLOC_ERROR);
    while (*data.s)
    {
        if (*data.s == '%' && *(++data.s))
        {
            if (parse_format(&data))
            {
                free(data.buf);
                return (PARSE_ERROR);
            }
        render_format(&data);
    }
    else
    {
        write_buf(&data, *data.s);
    }
    flush_buf(&data);
    va_ens(data.ap);
    free(data.buf);
    return (data.chars_written);
    

}
}