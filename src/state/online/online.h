/******************************************************************************
*     File Name           :     online.h                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-10-30 11:54]                            *
*     Last Modified       :     [2016-11-04 10:19]                            *
*     Description         :     Peer-to-peer online multiplayer.              *
******************************************************************************/
#ifndef ONLINE_H
#define ONLINE_H
/*****************************************************************************/
#include <sys/socket.h>                 // socket, connect
#include <netinet/in.h>                 // struct sockaddr_in, struct sockaddr
#include "src/state/serialize/serialize.h"
/*****************************************************************************/
typedef struct peer_s peer_t;
typedef struct online_s online_t;
/*****************************************************************************/
struct peer_s {
    char **address;
    change_t *holdback;
    peer_t *next;
};
/*---------------------------------------------------------------------------*/
struct online_s {
    int socket;
    struct sockaddr_in sock;
    char *buf;
    size_t bufsize;
    peer_t *peer;
};
/*****************************************************************************/
int synchronize(online_t *online, change_t *change);
/*****************************************************************************/
#endif // ONLINE_H
