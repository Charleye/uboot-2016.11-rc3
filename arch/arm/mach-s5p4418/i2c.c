/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <i2c.h>

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_SYS_I2C
static void s5p4418_i2c_init(struct i2c_adapter *adap, int speed, int slaveadd)
{
}

static int s5p4418_i2c_probe(struct i2c_adapter *adap, uint8_t chip)
{
    return 0;
}

static int s5p4418_i2c_read(struct i2c_adapter *adap, uint8_t chip, uint addr,
        int alen, uint8_t *buffer, int len)
{
    return 0;
}

static int s5p4418_i2c_write(struct i2c_adapter *adap, uint8_t chip, uint addr,
        int alen, uint8_t *buffer, int len)
{
    return 0;
}

static uint s5p4418_i2c_set_bus_speed(struct i2c_adapter *adap, unsigned int speed)
{
    return 0;
}

#endif
/*
 * Register s5p4418 i2c adapters
 */
U_BOOT_I2C_ADAP_COMPLETE(i2c00, s5p4418_i2c_init, s5p4418_i2c_probe,
        s5p4418_i2c_read, s5p4418_i2c_write,
        s5p4418_i2c_set_bus_speed,
        CONFIG_SYS_I2C_S5P4418_SPEED,
        CONFIG_SYS_I2C_S5P4418_SLAVE, 0)
U_BOOT_I2C_ADAP_COMPLETE(i2c01, s5p4418_i2c_init, s5p4418_i2c_probe,
        s5p4418_i2c_read, s5p4418_i2c_write,
        s5p4418_i2c_set_bus_speed,
        CONFIG_SYS_I2C_S5P4418_SPEED,
        CONFIG_SYS_I2C_S5P4418_SLAVE, 1)
U_BOOT_I2C_ADAP_COMPLETE(i2c02, s5p4418_i2c_init, s5p4418_i2c_probe,
        s5p4418_i2c_read, s5p4418_i2c_write,
        s5p4418_i2c_set_bus_speed,
        CONFIG_SYS_I2C_S5P4418_SPEED,
        CONFIG_SYS_I2C_S5P4418_SLAVE, 2)
U_BOOT_I2C_ADAP_COMPLETE(i2c03, s5p4418_i2c_init, s5p4418_i2c_probe,
        s5p4418_i2c_read, s5p4418_i2c_write,
        s5p4418_i2c_set_bus_speed,
        CONFIG_SYS_I2C_S5P4418_SPEED,
        CONFIG_SYS_I2C_S5P4418_SLAVE, 3)
