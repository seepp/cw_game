#ifndef PIPELINE_H
#define PIPELINE_H

#include <vulkan/vulkan.hpp>
#include <vector>
#include <string>

namespace cwg {
namespace graphics {

class pipeline {
    vk::Pipeline m_handle;
    vk::Device m_device;
    std::vector<vk::ShaderModule> m_shaders;

    void create(vk::RenderPass rp, vk::PipelineLayout lay, vk::Extent2D extent);
    vk::ShaderModule create_shader(std::string path);
    void destroy();
public:
    pipeline() {}
    pipeline(vk::Device dev, vk::RenderPass rp, vk::PipelineLayout lay, vk::Extent2D extent);
    ~pipeline();

    inline vk::Pipeline get() { return m_handle; }
    inline void reset() { destroy();}
    //inline void reset(vk::Format format) { destroy(); create(format);  }      //dangerous
    inline void reset(vk::Device dev, vk::RenderPass rp, vk::PipelineLayout lay, vk::Extent2D extent) { destroy(); m_device = dev; create(rp, lay, extent); }
};


}
}

#endif