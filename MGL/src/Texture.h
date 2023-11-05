#ifndef MGL_TEXTURE_H
#define MGL_TEXTURE_H

#include <cstdint>

#include "Constants.h"

namespace mgl {
    enum class TextureFormat
    {
        None             = -1,
        RGBA8            = GL_RGBA8,
        RGB32F           = GL_RGB32F,
        RGBA32F          = GL_RGBA32F,
        Depth            = GL_DEPTH_COMPONENT,
        Depth16          = GL_DEPTH_COMPONENT16,
        Depth24          = GL_DEPTH_COMPONENT24,
        Depth32          = GL_DEPTH_COMPONENT32,
        Depth32F         = GL_DEPTH_COMPONENT32F,
        Depth24Stencil8  = GL_DEPTH24_STENCIL8,
        Depth32FStencil8 = GL_DEPTH32F_STENCIL8,
        RedInt32         = GL_R32I,
        RedUInt32        = GL_R32UI,
        RedFloat32       = GL_R32F
    };

    enum class TextureFormatType
    {
        RGB          = GL_RGB,
        RGBA         = GL_RGBA,
        DepthStencil = GL_DEPTH_STENCIL,
        Depth        = GL_DEPTH_COMPONENT
    };

    enum class TextureWrapMode
    {
        Mirror  = GL_MIRRORED_REPEAT,
        Stretch = GL_CLAMP_TO_EDGE,
        Border  = GL_CLAMP_TO_BORDER
    };

    enum class TextureFilterMode
    {
        Linear  = GL_LINEAR,
        Nearest = GL_NEAREST
    };

    /* No mipmaps for now.
    enum class TextureMimapMode
    {
        None							= -1,
        LinearLinear					= GL_LINEAR_MIPMAP_LINEAR,
        LinearNearest					= GL_LINEAR_MIPMAP_NEAREST,
        NearestNearest					= GL_NEAREST_MIPMAP_NEAREST,
        NearestLinear					= GL_NEAREST_MIPMAP_LINEAR
    };
    */

    struct TextureProperties
    {
        TextureFormat     format     = TextureFormat::RGBA8;
        TextureWrapMode   wrapMode   = TextureWrapMode::Mirror;
        TextureFilterMode filterMode = TextureFilterMode::Linear;

        TextureProperties(const TextureFormat     format     = TextureFormat::None,
                          const TextureWrapMode   wrapMode   = TextureWrapMode::Mirror,
                          const TextureFilterMode filterMode = TextureFilterMode::Linear)
            : format(format), wrapMode(wrapMode), filterMode(filterMode)
        {
        }
    };

    class Texture
    {
    private:
        uint32_t          m_RendererId;
        const std::string m_FilePath;
        TextureProperties m_Props;
        uint8_t*          m_Buffer;
        int               m_Width;
        int               m_Height;
        int               m_GPP;
        uint32_t          m_Slot;

    public:
        inline uint32_t                 GetGlId() const { return m_RendererId; }
        inline int                      GetWidth() const { return m_Width; }
        inline int                      GetHeight() const { return m_Height; }
        inline uint32_t                 GetSlot() const { return m_Slot; }
        inline std::string_view         GetFilePath() const { return m_FilePath; }
        inline const TextureProperties& GetProperties() const { return m_Props; }

    public:
        Texture(const std::string_view filePath, TextureProperties properties = {});
        ~Texture();

    public:
        void Bind(const uint32_t slot = 0);
        void Unbind() const;

    public:
        static GLenum GetFormatType(const TextureProperties props);
    };
} // namespace mgl

#endif // MGL_TEXTURE_H
