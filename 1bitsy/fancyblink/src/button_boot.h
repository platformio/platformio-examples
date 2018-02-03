/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COMMON_BUTTON_BOOT_H
#define COMMON_BUTTON_BOOT_H

/* This function sets up and checks the state of the user button.
 * If the user button is depressed the built in factory bootloader is launched.
 */
void button_boot(void);

#endif /* COMMON_BUTTON_BOOT_H */
