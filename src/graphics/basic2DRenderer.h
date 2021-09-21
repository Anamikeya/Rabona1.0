#pragma once

#include<deque>
#include"Renderer.h"
#include"static_sprite.h"
namespace rabona {namespace graphics {


	class basic2DRenderer : public Renderer2D
	{
	private:
		std::deque<const StaticSprite*> m_RenderQueue;
	public:
		void submit(const Renderable2D* renderable) override;
		void flush() override;
	
	};

	}
}