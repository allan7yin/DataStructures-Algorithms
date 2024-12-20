from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        
        line, length = [], 0
        i = 0
        while i < len(words):
            if length + len(line) + len(words[i]) > maxWidth:
                # need to insert spaces and add to the result vector
                extraSpace = maxWidth - length
                spaces = extraSpace // max(1, len(line) - 1)
                remainder = extraSpace % max(1, len(line) - 1)

                for j in range(max(1, len(line) - 1)):
                    line[j] += " " * spaces
                    if remainder:
                        line[j] += " "
                        remainder -= 1
                    
                result.append("".join(line))
                line, length = [], 0

            line.append(words[i])
            length+=len(words[i])
            i += 1
        
        # last line
        lastLine = " ".join(line)
        trailSpace = maxWidth - len(lastLine)
        lastLine += " " * trailSpace
        result.append(lastLine)
        return result
        