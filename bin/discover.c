//---------------------------------------------------------------------------
//  __________________    _________  _____            _____  .__         ._.
//  \______   \______ \  /   _____/ /     \          /  _  \ |__| ____   | |
//   |    |  _/|    |  \ \_____  \ /  \ /  \        /  /_\  \|  _/ __ \  | |
//   |    |   \|    `   \/        /    Y    \      /    |    |  \  ___/   \|
//   |______  /_______  /_______  \____|__  / /\   \____|__  |__|\___ |   __
//          \/        \/        \/        \/  )/           \/        \/   \/
//
// This file is part of libdsm. Copyright © 2014 VideoLabs SAS
//
// Author: Julien 'Lta' BALLET <contact@lta.io>
//
// This program is free software. It comes without any warranty, to the extent
// permitted by applicable law. You can redistribute it and/or modify it under
// the terms of the Do What The Fuck You Want To Public License, Version 2, as
// published by Sam Hocevar. See the COPYING file for more details.
//----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "bdsm.h"

int main(int ac, char **av)
{
  netbios_ns_t      *ns;
  netbios_ns_iter_t iter;

  ns = netbios_ns_new();

  if (!netbios_ns_discover(ns))
  {
    fprintf(stderr, "Error while discovering local network\n");
    exit(42);
  }

  iter = netbios_ns_get_entries(ns);
  while (iter != NULL)
  {
    struct in_addr addr;

    addr.s_addr = netbios_ns_iter_ip(iter);
    printf("Ip: %s, name: %s<%x> \n",
      inet_ntoa(addr),
      netbios_ns_iter_name(iter),
      netbios_ns_iter_type(iter));

    iter = netbios_ns_iter_next(iter);
  }

  return (0);
}