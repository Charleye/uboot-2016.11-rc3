/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE     512U
typedef unsigned char uchar_t;

int main (int argc, char *argv[])
{
    if (argc != 5)
    {
        printf ("Usage: mk4418 <destination file> <2ndboot.bin> <nsih.txt> <u-boot.bin>");
        return -1;
    }

    FILE *2ndboot   = NULL;
    FILE *nsih      = NULL;
    FILE *uboot     = NULL;
    FILE *dest      = NULL;

    uchar_t *buf = (uchar_t *)malloc(BUFSIZE);
    memset (buf, 0x00, BUFSIZE);

    2ndboot = fopen (argv[2], "r");
    if (2ndboot == NULL)
    {
        printf ("Open 2ndboot file failed\n");
        return -1;
    }
    nsih = fopen (argv[3], "r");
    if (nsih == NULL)
    {
        printf ("Open nsih file failed\n");
        return -1;
    }
    uboot = fopen (argv[4], "r");
    if (uboot == NULL)
    {
        printf ("Open u-boot.bin file failed\n");
        return -1;
    }

    if (2ndboot)
        fclose(2ndboot);
    if(nsih)
        fclose(nsih);
    if(uboot)
        fclose(uboot);
    if(buf)
        free(buf);

    return 0;
}
