#pragma once
#include "MyClass.h"
#include "Stack.h"

bool findPath(int* maze,int ROW,int COL, Direction direct[], Stack<Box>& s)
{
	Box temp;
	int x, y, di;
	int line, col;
	//maze[1][1] = -1;
	maze[1 * COL + 1] = -1;
	temp = { 1,1,-1 };
	s.Push(temp);
	while (!s.Empty()) {
		temp = s.Pop();
		x = temp.x; y = temp.y; di = temp.di + 1;
		while (di < 4) {
			line = x + direct[di].incX;
			col = y + direct[di].incY;
			if (maze[line * COL + col] == 0) {
				temp = Box( x,y,di );
				s.Push(temp);
				x = line; y = col; maze[line*COL+col] = -1;
				if (x == ROW - 2 && y == ROW - 2) { 
					temp = { x,y,-1 };
					s.Push(temp);
					return true;
				}
				else  di = 0;
			}
			else di++;
		}
	}
	return false;
}
