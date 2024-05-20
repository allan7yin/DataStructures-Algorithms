"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None
        myMap = {}
        copyGraph = Node(node.val)

        def dfs(original, copy):
            nonlocal myMap
            myMap[original.val] = copy
            # copy go to each of the neighbours of the orginal node and make copies if unvisited
            for neighbour in original.neighbors:
                if neighbour.val not in myMap:
                    temp = Node(neighbour.val)
                    copy.neighbors.append(temp)
                    dfs(neighbour, temp)
                else:
                    copy.neighbors.append(myMap[neighbour.val])

        dfs(node, copyGraph)
        return copyGraph
