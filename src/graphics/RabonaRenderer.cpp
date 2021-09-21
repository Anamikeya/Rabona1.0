#include"RabonaRenderer.h"
namespace rabona {namespace graphics {
	
	RabonaRenderer::RabonaRenderer()
	{
		init();
	}

	RabonaRenderer::~RabonaRenderer()
	{
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
	}

	void RabonaRenderer::init()
	{
		glGenVertexArrays(1, &m_VAO);

		glGenBuffers(1, &m_VBO);
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*)(3 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		unsigned int* indicies = new unsigned int[RENDERER_INDICIES_SIZE];
		int offset = 0;
		for (int i = 0; i < RENDERER_INDICIES_SIZE; i += 6)
		{
			indicies[  i  ] = offset + 0;
			indicies[i + 1] = offset + 1;
			indicies[i + 2] = offset + 2;

			indicies[i + 3] = offset + 2;
			indicies[i + 4] = offset + 3;
			indicies[i + 5] = offset + 0;
			offset += 4;
		}
		m_IBO = new IndexBuffer(indicies, RENDERER_INDICIES_SIZE);
		glBindVertexArray(0);
	}
	void RabonaRenderer::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VAO);
		m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}
	void RabonaRenderer::submit(const Renderable2D* renderable)
	{
		const maths::vec3& position = renderable->getPosition();
		const maths::vec2& size = renderable->getSize();
		const maths::vec4& color = renderable->getColor();

		m_Buffer->vertex = position;
		m_Buffer->color = color;
		m_Buffer++;

		m_Buffer->vertex = maths::vec3(position.x, position.y + size.y, position.z);
		m_Buffer->color = color;
		m_Buffer++;

		m_Buffer->vertex = maths::vec3(position.x + size.x, position.y + size.y, position.z);
		m_Buffer->color = color;
		m_Buffer++;

		m_Buffer->vertex = maths::vec3(position.x +  size.x, position.y, position.z);
		m_Buffer->color = color;
		m_Buffer++;

		m_IndexCount += 6;
	}
	void RabonaRenderer::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void RabonaRenderer::flush()
	{
		glBindVertexArray(m_VAO);
		m_IBO->bind();

		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);


		m_IBO->unbind();
		glBindVertexArray(0);
		m_IndexCount = 0;
	}

} }
