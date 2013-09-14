#include "gpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int open_value_file(unsigned int gpio)
{
    int fd;
    char filename[40];

    // create file descriptor of value file
    snprintf(filename, sizeof(filename), "/sys/class/gpio/gpio%d/value", gpio);
    if ((fd = open(filename, O_RDONLY | O_NONBLOCK)) < 0)
        return -1;
    return fd;
}

int gpio_export(unsigned int gpio)
{
    int fd, len;
    char str_gpio[10];
    struct gpio_exp *new_gpio, *g;

    if ((fd = open("/sys/class/gpio/export", O_WRONLY)) < 0)
    {
        return -1;
    }
    len = snprintf(str_gpio, sizeof(str_gpio), "%d", gpio);
    write(fd, str_gpio, len);
    close(fd);
}

int gpio_set_direction(unsigned int gpio, unsigned int in_flag)
{
    int fd;
    char filename[40];
    char direction[10] = { 0 };

    snprintf(filename, sizeof(filename), "/sys/class/gpio/gpio%d/direction", gpio);
    if ((fd = open(filename, O_WRONLY)) < 0)
        return -1;

    if (in_flag) {
        strncpy(direction, "out", 3);
    } else {
        strncpy(direction, "in", 2); // TODO fix remove 9 to strlen of similar
    }

    write(fd, direction, strlen(direction));
    close(fd);
    return 0;
}

int gpio_set_value(unsigned int gpio, unsigned int value)
{
    int fd;
    char filename[40];
    char vstr[10];

    snprintf(filename, sizeof(filename), "/sys/class/gpio/gpio%d/value", gpio);

    if ((fd = open(filename, O_WRONLY)) < 0)
        return -1;

    if (value) {
        strncpy(vstr, "1", ARRAY_SIZE(vstr) - 1);
    } else {
        strncpy(vstr, "0", ARRAY_SIZE(vstr) - 1);
    }

    write(fd, vstr, strlen(vstr));
    close(fd);
    return 0;
}

int gpio_get_value(unsigned int gpio, unsigned int *value)
{
    int fd = 0;
    char ch;

    if (!fd)
    {
        if ((fd = open_value_file(gpio)) == -1)
            return -1;
    }    

    lseek(fd, 0, SEEK_SET);
    read(fd, &ch, sizeof(ch));

    if (ch != '0') {
        *value = 1;
    } else {
        *value = 0;
    }

    return 0;
}