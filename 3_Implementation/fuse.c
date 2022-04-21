/*
 * fuse.c
 *
 * Created: 21-04-2022 11:30:43
 *  Author: DeviTanuja
 */ 
#include <avr/io.h>

FUSES = {
	.low = LFUSE_DEFAULT,
	.high = HFUSE_DEFAULT,
	.extended = EFUSE_DEFAULT
};
