#include "Error.hpp"

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int main() {
	THROW_ERROR("This is a test error message");

	return 0;
} 
