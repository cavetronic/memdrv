/*
* Copyright © 2017 Adam Pyka <cavetronic@cavetronic.eu>
* This program is free software. It comes without any warranty, to the extent
* permitted by applicable law. You can redistribute it and/or modify it under
* the terms of the GNU GENERAL PUBLIC LICENSE, Version 3, as
* published by Free Software Foundation. See the LICENSE file for more details.
*/

#ifndef SERIALFLASH_H
#define SERIALFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>

#define MAX_ADDRESS	0xFFFFFF

/* ===================================================
 * SPI low-level functions
 * ===================================================
 */
 
/*
 * Transmits and receives a single byte via the SPI
 */
uint8_t spi_trx(uint8_t tx_byte);

/*
 * Select SPI device
 */
void spi_select(void);

/*
 * Deselect SPI device
 */
void spi_deselect(void);

/* ===================================================
 * Memory access helpers
 * ===================================================
 */
 
/*
 * Send memory address via SPI
 */
void send_address(uint32_t address);

/*
 * Sets the write enable latch (WEL) bit.
 */
void enable_write();

/*
 * Resets the write enable latch (WEL) bit.
 */
void diable_write();

/*
 * Reads a memory page from address by n-bytes. If end address is reached,
 * the functions stop reading and returns.
 * 
 * The pointer to n-byte data array is needed.
 */
void read_page(uint8_t *received_data, uint32_t address, uint16_t n);

/*
 * Writes a memory page at address by n-bytes.
 */
void write_page(uint8_t *data, uint32_t address, uint16_t n);

/* ===================================================
 * High-level functions
 * ===================================================
 */
 
/*
 * Reads a single memory byte at particular address.
 * 
 * Return the data byte.
 */
uint8_t read_data_byte(uint32_t address);

/*
 * Writes a single memory byte at particular address.
 * 
 */
void write_data_byte(uint8_t data, uint32_t address);

/*
 * Reads a memory from start_addr by n-bytes. If end address is reached,
 * the functions stop reading and returns.
 * 
 * The pointer to n-byte data array is needed.
 */
void read_data_bytes(uint8_t *received_data, uint32_t start_addr, uint32_t n);

/*
 * Writes a memory from start_addr by n-bytes.
 */
void write_data_bytes(uint8_t *data, uint32_t start_addr, uint32_t n);

/*
 * Erase a memory page.
 */
void erase_page(uint32_t address);

/*
 * Reads a chip ID.
 * 
 * Return the two-byte chip ID.
 */
uint16_t read_chip_id();

#ifdef __cplusplus
}
#endif

#endif /* SERIALFLASH_H */
