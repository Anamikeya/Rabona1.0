#pragma once
#include<chrono>
#include<iostream>

namespace rabona {
	class Timer
	{
	private:
		std::chrono::duration<float> m_Duration ;
		std::chrono::time_point<std::chrono::steady_clock> m_Start;
		std::chrono::time_point<std::chrono::steady_clock> m_End;
	public:
		
		Timer()
		{
			m_Start = std::chrono::high_resolution_clock::now();
			
		}
		~Timer()
		{
			m_End = std::chrono::high_resolution_clock::now();
			m_Duration = m_End - m_Start;
			float ms = m_Duration.count() * 1000.0f;
			printf("\nTImer took : %f ms\n ", ms);

		}
	};
}