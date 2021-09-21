#include "shader.h"
#include <vector>
#include <iostream>
namespace rabona {namespace graphics {
	
	Shader::Shader(const char* vertPath, const char* fragPath)
		:m_VertPath(vertPath),m_FragPath(fragPath)
	{
		m_ShaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderID);
	}
	unsigned int Shader::load()
	{
		unsigned int program = glCreateProgram();
		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertSourceString = FileUtils::read_file(m_VertPath);
		std::string fragSourceString = FileUtils::read_file(m_FragPath);
		const char* vertSource = vertSourceString.c_str();
		const char* fragSource = fragSourceString.c_str();



		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);
		
		int result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

	
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;

	}
	int Shader::getUniformLocation(const char* name)
	{
		return glGetUniformLocation(m_ShaderID, name);
	}
	void Shader::setUniform1i(const char* name, int value)
	{
		return glUniform1i(getUniformLocation(name),value);
	}

	void Shader::setUniform1f(const char* name, float value)
	{
		return glUniform1f(getUniformLocation(name), value);
	}
	void Shader::setUniform2f(const char* name, const maths::vec2& vector)
	{
		return glUniform2f(getUniformLocation(name), vector.x, vector.y);
	}
	void Shader::setUniform3f(const char* name, const maths::vec3& vector)
	{
		return glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);

	}
	void Shader::setUniform4f(const char* name, const maths::vec4& vector)
	{
		return glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	void Shader::setUniformMat4(const char* name, const maths::mat4& matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);

	}


	void Shader::enable()
	{
		glUseProgram(m_ShaderID);
	}
	void Shader::disable()
	{
		glUseProgram(0);

	}


} }