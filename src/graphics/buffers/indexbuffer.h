#pragma once

#include <GL/glew.h>
namespace rabona {namespace graphics {

	class IndexBuffer
	{
	private:

		unsigned int m_BufferID;
		unsigned int m_Count;
	public:
		IndexBuffer(unsigned short* data, int count);
		IndexBuffer(unsigned int* data, int count);
		~IndexBuffer();
		inline unsigned int getCount() const { return m_Count; }
		void bind() const;
		void unbind() const;

	};
}}

