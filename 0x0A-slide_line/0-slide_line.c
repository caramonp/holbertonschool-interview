#include "slide_line.h"

/**
 * slide_line - slides a line or left or right
 * @line: line of array
 * @size: size of array
 * @direction: direction to slide
 * Return: 0 or 1
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	} else
	{
		slide_right(line, size);
	}

	return (1);
}

/**
 * slide_left - slides to the left
 * @line: line of arrays
 * @size: size of array
 */

void slide_left(int *line, size_t size)
{
	int i = 0, j, current, previus = 0;

	for (j = 0; j < (int)size; j++)
	{
		current = line[j];
		if (!current)
			continue;
		if (!previus)
			previus = current;
		else if (previus == current)
		{
			line[i++] = current << 1;
			previus = 0;
		} else
		{
			line[i++] = previus;
			previus = current;
		}
	}
	if (previus)
		line[i++] = previus;
	while (i < (int)size)
		line[i++] = 0;
}

/**
 * slide_right - slides to the right
 * @line: line of arrays
 * @size: size of array
 */

void slide_right(int *line, size_t size)
{
	int  i = size - 1, j, current, previus = 0;

	for (j = size - 1; j >= 0; j--)
	{
		current = line[j];
		if (!current)
			continue;
		if (!previus)
			previus = current;
		else if (previus == current)
		{
			line[i--] = current << 1;
			previus = 0;
		} else
		{
			line[i--] = previus;
			previus = current;
		}
	}
	if (previus)
		line[i--] = previus;
	while (i >= 0)
		line[i--] = 0;
}
