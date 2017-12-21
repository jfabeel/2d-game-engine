/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_STACK
#define C_STACK

#include <iostream>

template <class m_m> 

class CStack {
private:
	m_m *m_stack;
	int topIndex;	
public:
	CStack()
	{
		std::cout << "New Stack is created" << std::endl;
		m_stack = new m_m;
		topIndex = -1;
	}
	void Push(m_m m_stackItem)
	{
		topIndex++;
		m_stack[topIndex] = m_stackItem;
	}
	void Pop()
	{
		if (topIndex == -1)
		{
			return;
		}
		m_stack[topIndex] = NULL;
		topIndex--;
	}
	m_m AtIndex(int index)
	{
		return m_stack[topIndex];
	}
	int size()
	{
		return topIndex;
	}
};

#endif