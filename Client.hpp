#pragma once

#include <cstdint>

enum class MessageType : uint8_t {
    String = 1,
    Int = 2,
    Int8Array = 3
};

#define WIN32
#ifdef WIN32

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#endif
