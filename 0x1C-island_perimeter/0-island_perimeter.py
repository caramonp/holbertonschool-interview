#!/usr/bin/python3
"""
Island Perimeter module
"""


def island_perimeter(grid):
    """ function that returns the perimeter of the island described in grid
    """
    count, maxPerimeter = (0, 0)
    len_grid, len_col = (len(grid), len(grid[0]))

    for col in range(len_grid):
        count += sum(grid[col])
        for row in range(len_col):
            if grid[col][row]:
                if row > 0 and grid[col][row - 1] == 1:
                    maxPerimeter += 1

                if col > 0 and grid[col - 1][row] == 1:
                    maxPerimeter += 1
    return count * 4 - maxPerimeter * 2
