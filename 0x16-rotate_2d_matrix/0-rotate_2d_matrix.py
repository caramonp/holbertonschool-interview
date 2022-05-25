#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """rotate two dimension matrix 90 degrees clockwise
    """
    lenght = len(matrix)
    for i in range(int(lenght / 2)):
        y = (lenght - i - 1)
        for j in range(i, y):
            x = (lenght - 1 - j)
            tempo = matrix[i][j]
            matrix[i][j] = matrix[x][i]
            matrix[x][i] = matrix[y][x]
            matrix[y][x] = matrix[j][y]
            matrix[j][y] = tempo
