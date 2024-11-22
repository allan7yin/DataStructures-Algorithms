from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        if n * m != r * c:
            return mat
        matrix = [[0 for _ in range(c)] for _ in range(r)]
        x, y = 0, 0
        

        for i in range(n):
            for j in range(m):
                if y >= c:
                    y = 0
                    x+= 1
                matrix[x][y] = mat[i][j]
                y += 1

        return matrix