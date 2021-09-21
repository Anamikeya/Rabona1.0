#pragma once

#include"Renderer.h"
#include"buffers/indexbuffer.h"
namespace rabona { namespace graphics {
#define RENDERER_MAX_SPRITES 1000000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE *  RENDERER_MAX_SPRITES
#define RENDERER_INDICIES_SIZE RENDERER_MAX_SPRITES * 6
#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1
	class RabonaRenderer : public Renderer2D
	{
	private:
		unsigned int m_VAO;
		unsigned int m_VBO;
		IndexBuffer* m_IBO;
		size_t m_IndexCount;
		VertexData* m_Buffer;
		 
	public:
		RabonaRenderer();
		~RabonaRenderer();
		void begin();
		void end();
		void submit(const Renderable2D* renderable) override;
		void flush() override;
	private:
		void init();

	};
}}