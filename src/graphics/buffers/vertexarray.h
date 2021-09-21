#pragma once
#include<vector>
#include<GL/glew.h>
#include "buffer.h"
namespace rabona {namespace graphics {
	
	class VertexArray
	{
	private:
		unsigned int m_ArrayID;
		std::vector<Buffer*> m_Buffers;

	public:
		VertexArray();
		~VertexArray();
		void addBuffer(Buffer* buffer, unsigned int index);
		void bind() const;
		void unbind() const;

	};
}}