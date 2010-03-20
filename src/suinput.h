/*
  suinput - A set of uinput helper functions
  Copyright (C) 2009 Tuomas Räsänen <tuos@codegrove.org>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SUINPUT_H
#define SUINPUT_H
#include <stdint.h>

#include <linux/uinput.h>

int suinput_uinput_write_event(int uinput_fd, const struct input_event *event);

int suinput_uinput_write(int uinput_fd, uint16_t ev_type, uint16_t ev_code,
                         int32_t ev_value);

int suinput_uinput_syn(int uinput_fd);

const char *suinput_uinput_get_devnode(void);

int suinput_uinput_open(void);

int suinput_uinput_create(int uinput_fd,
                          const struct uinput_user_dev *user_dev);

int suinput_uinput_destroy(int uinput_fd);

int suinput_uinput_set_capabilities(int uinput_fd, uint16_t ev_type,
                                    int *ev_codes, size_t ev_codes_len);

#endif /* SUINPUT_H */
