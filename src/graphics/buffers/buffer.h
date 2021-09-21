#pragma once
#include <GL/glew.h>
namespace rabona {namespace graphics{

	class Buffer
	{
	private:

		unsigned int m_BufferID;
		unsigned int m_ComponentCount;
	public:
		Buffer(float* data, int count, unsigned int componentCount);
		~Buffer();
		inline unsigned int getComponentCount() const { return m_ComponentCount; }
		void bind() const; 
		void unbind() const;

	};
} }

