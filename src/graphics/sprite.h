#pragma once
#include"Renderable2d.h"
namespace rabona {namespace graphics {

	class Sprite : public Renderable2D
	{
	public:
		Sprite(float x, float y, float width, float height, const maths::vec4& color);
	};
}}