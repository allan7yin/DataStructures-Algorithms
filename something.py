from ast import List


# crypt the is the array OF 3 strings: word1 + word2 = word3
# soluiont is the array from char to int : [['O' : '0']], ...
class Solution:
  def main(crypt, solution):
    # create a hashmap
    dict = {}
    for key,value in solution:
      dict[key] = value

    nums = []
    for word in crypt:
      temp = ''
      for ch in word:
        temp += dict[ch]
      # string to num
      temp.lstrip('0') if temp[1] == '0' else temp
      nums.append(int(temp.lstrip('0')))
    
    # check if valid 
    return nums[0] + nums[1] == nums[2]
    
solution = [['A', '0'], ['B', '2'], ['C', '3'], ['D', '4'], ['E', '5'],
                    ['F', '6'], ['G', '7'], ['H', '8'], ['I', '9'], ['J', '10'],
                    ['K', '11'], ['L', '12'], ['M', '13'], ['N', '14'], ['O', '15'],
                    ['P', '16'], ['Q', '17'], ['R', '18'], ['S', '19'], ['T', '20'],
                    ['U', '21'], ['V', '22'], ['W', '23'], ['X', '24'], ['Y', '25'],
                    ['Z', '26']]
allan = Solution
crypt = ["A", "A", "A"]
print(allan.main(crypt, solution))