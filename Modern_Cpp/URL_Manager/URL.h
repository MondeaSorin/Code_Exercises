#pragma once
#include <string>

class URL
{
	static constexpr const char* _DEF_PROTOCOL_ = "Unknown protocol";
	static constexpr const char* _DEF_RESOURCE_VAL_ = "Unknown resource";
private:
	std::string protocol;
	std::string resource;
public:
	URL();
	URL(std::string protocol, std::string resource);

	void displayURL() const;
};	

