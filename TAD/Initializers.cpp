#include "Initializers.h"

VkApplicationInfo Initializers::ApplicationInfo(VulkanConfiguration& config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.applicationName;
	info.applicationVersion = config.applicationVersion;
	info.pEngineName = config.engineName;
	info.engineVersion = config.engineVersion;
	info.apiVersion = config.apiVersion;
	return info;
}

VkInstanceCreateInfo Initializers::InstanceCreateInfo(VkApplicationInfo& appInfo, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &appInfo;
	info.enabledExtensionCount = extensions.size();
	info.enabledLayerCount = layers.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.ppEnabledLayerNames = layers.data();
	return info;
}
