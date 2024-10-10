/*
 * Hostapd / Zephyr socket pair -based control interface
 * Copyright (c) 2022, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include "ctrl_iface_zephyr.h"

void hostapd_ctrl_iface_receive(int sock, void *eloop_ctx,
					      void *sock_ctx)
{
	struct hostapd_data *hapd = eloop_ctx;
	char buf[MAX_CTRL_MSG_LEN + 1];
	char *pos;
	int res;
	char *reply = NULL;
	int reply_len = 0;
	const int reply_size = 4096;

	res = recv(sock, buf, MAX_CTRL_MSG_LEN, 0);
	if (res < 0) {
		wpa_printf(MSG_ERROR, "recvfrom(ctrl_iface): %s",
			   strerror(errno));
		return;
	}

	if (!res) {
		eloop_unregister_sock(sock, EVENT_TYPE_READ);
		wpa_printf(MSG_DEBUG, "ctrl_iface: Peer unexpectedly shut down "
			   "socket");
		return;
	}

	if ((size_t) res > MAX_CTRL_MSG_LEN) {
		wpa_printf(MSG_ERROR, "recvform(ctrl_iface): input truncated");
		return;
	}
	buf[res] = '\0';

	pos = buf;
	while (*pos == ' ')
		pos++;

	reply_len = hostapd_ctrl_iface_receive_process(hapd, pos, reply, reply_size, NULL, 0);
	if (reply) {
		send(sock, reply, reply_len, 0);
	} else if (reply_len == 1) {
		send(sock, "FAIL\n", 5, 0);
	} else if (reply_len == 3) {
		send(sock, "OK\n", 3, 0);
	}
}


