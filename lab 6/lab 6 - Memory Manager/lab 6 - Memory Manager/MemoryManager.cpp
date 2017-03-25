// Amanda Pan
// CECS 285
// lab 6 Memory Manager
// 5/5/2016

#include "MemoryManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace MemoryManager
{
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
	//
	// This is the only static memory that you may use, no other global variables
	// may be created, if you need to save data make it fit in MM_pool
	//
	// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];
	// I have provided this tool for your use
	void memView(int start, int end)
	{
		const unsigned int SHIFT = 8;
		const unsigned int MASK = 1 << SHIFT - 1;
		unsigned int value;	// used to facilitate bit shifting and masking
		cout << " Pool Unsignd Unsigned " << endl;
		cout << "Mem Add indx bits chr ASCII# short int " << endl;
		cout << "-------- ---- -------- --- ------ ------- ------------" << endl;
		for (int i = start; i <= end; i++)
		{
			cout << (long*)(MM_pool + i) << ':';	// the actual address in hexadecimal
			cout << '[' << setw(2) << i << ']';	// the index into MM_pool
			value = MM_pool[i];
			cout << " ";
			for (int j = 1; j <= SHIFT; j++)	// the bit sequence for this byte (8 bits)
			{
				cout << ((value & MASK) ? '1' : '0');
				value <<= 1;
			}
			cout << " ";
			cout << '|' << *(char*)(MM_pool + i) << "| (";	// the ASCII character of the 8 bits (1 byte)
			cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";	// the ASCII number of the character
			cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";	// the unsigned short value of 16 bits (2 bytes)
			cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// the unsigned int value of 32 bits (4 bytes)
			cout << endl;
		}
	}
	// Initialize set up any data needed to manage the memory pool
	void initializeMemoryManager(void)
	{
		*(unsigned short *)(MM_pool + 0) = 6;
		*(unsigned short *)(MM_pool + 2) = 0;
		*(unsigned short *)(MM_pool + 4) = 0;		
	}
	// return a pointer inside the memory pool
	// If no chunk can accommodate aSize call onOutOfMemory() - still
	void* allocate(int aSize)
	{
		if((*MM_pool + aSize + 6) > (MM_POOL_SIZE-1))
		{
			onOutOfMemory();
			return 0;
		}
		unsigned short index = *(unsigned short*)MM_pool;
		unsigned short inUse = *(unsigned short*)(MM_pool + 2);
		*(unsigned short *)(MM_pool + index) = aSize; //set node 1st index to aSize
		//store index of prev in inUse
		if(inUse != 0)
		{
			*(unsigned short *)(MM_pool + index + 2) = inUse;
			*(unsigned short *)(MM_pool + inUse + 4) = index;
		}
		*(unsigned short *)(MM_pool + 2) = index; //next 
		*(unsigned short*)MM_pool = index + (6 + aSize);
		return (void *)(MM_pool + index + 6);
	}
	// Free up a chunk previously allocated
	void deallocate(void* aPointer)
	{
		unsigned short current = (char*)(aPointer) - 6 - MM_pool;
		unsigned short prev = *(unsigned short*)(MM_pool + current + 4);
		unsigned short next = *(unsigned short*)(MM_pool + current + 2);
		unsigned short used = *(unsigned short*)(MM_pool + 4);
		if (next != 0)
			*(unsigned short*)(MM_pool + next + 4) = prev;
		if (prev != 0)
			*(unsigned short*)(MM_pool + prev + 2) = next;
		if(current == *(unsigned short*)(MM_pool + 2))
			*(unsigned short*)(MM_pool + 2) = next;
		if (used != 0)
			*(unsigned short*)(MM_pool + used + 4) = current;
		*(unsigned short*)((char*)(aPointer) - 4) = used;
		*(unsigned short*)(MM_pool + 4) = current;
	}
	//---
	//--- support routines
	//---
	// Will scan the memory pool and return the total free space remaining
	int freeMemory(void)
	{
		return MM_POOL_SIZE - inUseMemory() - usedMemory() - 6;
	}
	// Will scan the memory pool and return the total deallocated memory
	int usedMemory(void)
	{
		unsigned short next = *(unsigned short*)(MM_pool + 4);
		unsigned short usedMem = 0;
		while (next != 0)
		{
			usedMem += 6 + *(unsigned short*)(MM_pool + next);
			next = *(unsigned short*)(MM_pool + next + 2);
		}
		return usedMem;
	}
	// Will scan the memory pool and return the total in use memory
	int inUseMemory(void)
	{
		unsigned short next = *(unsigned short*)(MM_pool + 2);
		unsigned short inUseMem = 0;
		while (next != 0)
		{
			inUseMem += 6 + *(unsigned short*)(MM_pool + next);
			next = *(unsigned short*)(MM_pool + next + 2);
		}
		return inUseMem;
	}
	void onOutOfMemory()
	{
		cout << "Out of memory\n";
	}
}