#include "URL.h"
#include <iostream>

URL::URL() : URL(_DEF_PROTOCOL_, _DEF_RESOURCE_VAL_) {} // Delegating towards the ctor with params using our class defined default values
URL::URL(std::string protocol, std::string resource)
	:protocol(protocol), resource(resource) 
{
	// Debugg lines
	//std::cout << protocol.find("http://") << std::endl;
	//std::cout << protocol.find("https://") << std::endl;
	// Doesn't matter if we use protocol or this->protocol, as they are both containing the same value after initialisation
	if (protocol.find("http://") == std::string::npos
		&& protocol.find("https://") == std::string::npos)
	{
		throw std::runtime_error("Invalid protocol type - only http or https are allowed");
	}

	if (resource.find("www.") == std::string::npos)
	{
		throw std::runtime_error("Invalid resource value - www. is missing");
	}
	// TODO - also check if the format after .com is correct 
}

void URL::displayURL() const
{
	std::cout << "URL: " << this->protocol << this->resource << std::endl;
}
