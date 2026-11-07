#include <stdio.h>

enum
{
    LIGHT = 0,
    FAN = 1,
    AC = 2,
    HEATER = 3,
    PUMP = 4
};

unsigned char switch_on(unsigned char reg, int dev)
{
    return reg | (1u << dev);
}

unsigned char switch_off(unsigned char reg, int dev)
{
    return reg & ~(1u << dev);
}

unsigned char toggle(unsigned char reg, int dev)
{
    return reg ^ (1u << dev);
}

int is_on(unsigned char reg, int dev)
{
    return (reg & (1u << dev)) != 0;
}

void show(unsigned char reg)
{
    int bit;

    for (bit = 7; bit >= 0; bit--)
        printf("%d", (reg >> bit) & 1);

    printf("\n");
}

int main()
{
    unsigned char reg = 0;

    reg = switch_on(reg, LIGHT);
    reg = switch_on(reg, AC);

    show(reg);

    reg = toggle(reg, FAN);
    reg = switch_off(reg, LIGHT);

    show(reg);

    printf("AC is %s\n", is_on(reg, AC) ? "ON" : "OFF");

    printf("PUMP is %s\n", is_on(reg, PUMP) ? "ON" : "OFF");

    return 0;
}
