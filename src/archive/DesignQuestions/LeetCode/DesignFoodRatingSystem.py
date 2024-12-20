from collections import defaultdict
import heapq

"""
Food Rating System:

- hashamp: key = cuisine, value = maxHeap of tuples: (score, food)
- brute-force, we we iterate through all values in the maxHeap,
  and change the desired one O(n)

"""


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisine_foods = defaultdict(list)
        self.food_to_cuisine = {}

        # initliaze the above data structures
        for i in range(len(foods)):
            self.food_to_cuisine[foods[i]] = cuisines[i]
            heapq.heappush(self.cuisine_foods[cuisines[i]], (-1 * ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine_type = self.food_to_cuisine[food]
        for i in range(len(self.cuisine_foods[cuisine_type])):
            rating, food_name = self.cuisine_foods[cuisine_type][i]
            if food_name == food:
                self.cuisine_foods[cuisine_type][i] = (-1 * newRating, food)
                heapq.heapify(self.cuisine_foods[cuisine_type])
                break

    def highestRated(self, cuisine: str) -> str:
        result = self.cuisine_foods[cuisine][0][1]
        return result


"""
But, the above is TLE. So, need more effecient data structures.
What we can instead do, is on food rating changes, just push something new
to the maxHeap. Then, in the food_to_cuisine, we'll also store the updated
rating, so we can get the correct one and pop outdated ones
"""


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisine_foods = defaultdict(list)
        self.food_to_cuisine = {}

        # initliaze the above data structures
        for i in range(len(foods)):
            self.food_to_cuisine[foods[i]] = (ratings[i], cuisines[i])
            heapq.heappush(self.cuisine_foods[cuisines[i]], (-1 * ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        rating, cuisine_type = self.food_to_cuisine[food]
        self.food_to_cuisine[food] = (newRating, cuisine_type)
        heapq.heappush(self.cuisine_foods[cuisine_type], (-1 * newRating, food))

    def highestRated(self, cuisine: str) -> str:
        topRating, topName = self.cuisine_foods[cuisine][0]
        topRating *= -1
        while topRating != self.food_to_cuisine[topName][0]:
            heapq.heappop(self.cuisine_foods[cuisine])
            topRating, topName = self.cuisine_foods[cuisine][0]
            topRating *= -1

        return topName


"""
This does not TLE: Beats 80% of submissions
"""
