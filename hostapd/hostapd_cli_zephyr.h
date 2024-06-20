/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef __HOSTAPD_CLI_ZEPHYR_H_
#define __HOSTAPD_CLI_ZEPHYR_H_

#include <zephyr/kernel.h>

void hostapd_cli_msg_cb(char *msg, size_t len);
int hostapd_request(struct wpa_ctrl *ctrl, int argc, char *argv[]);
int hostapd_ctrl_command(struct wpa_ctrl *ctrl, const char *cmd);
int zephyr_hostapd_cli_cmd_resp(const char *cmd, char *resp);
int zephyr_hostapd_cli_cmd_v(const char *fmt, ...);
int zephyr_hostapd_ctrl_init(void *ctx);
#endif /* __HOSTAPD_CLI_ZEPHYR_H_ */
