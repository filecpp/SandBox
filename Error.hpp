#pragma once

#include <stdexcept>
#include <string>

#define THROW_ERROR(msg)							\
	throw											\
		std::runtime_error(std::string("Error: ") + \
		msg +										\
		" (in file " + __FILE__ +					\
		", line " + \ std::to_string(__LINE__) +	\
		")")
