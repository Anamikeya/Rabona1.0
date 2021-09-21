#pragma once
#include<memory>
namespace rabona {
	
	class MemoryCheck
	{
		struct AllocationMemory
		{
			int MemoryAllocated;
			int MemoryFree;

			int CurrentUsage() {
				return MemoryAllocated - MemoryFree;
			}
		};
		static AllocationMemory s_AllocationMemory;
		void* operator new(size_t size)
		{
			s_AllocationMemory.MemoryAllocated += size;
			return malloc(size);
		}
		void operator delete(void* memory, size_t size)
		{
			s_AllocationMemory.MemoryFree += size;
			free(memory);
		}

		static void MemoryTotalUsed()
		{
			printf("Memory Usage : %d", s_AllocationMemory.CurrentUsage());
		}
	};
}