from enum import Enum 
from collections import defaultdict

class State(Enum):
    UP = 1
    DOWN = 2
    IDLE = 3
    STOPPED = 4

class Person:
    def __init__(self, weight: float):
        self.weight = weight

class Elevator:
    def __init__(self, maxLevel: int, weightLimit: float):
        self.currentWeight = 0
        self.maxLevel = maxLevel
        self.weightLimit = weightLimit
        self.currentLevel = 0
        self.remainingLevels = 0
        self.upMap = defaultdict(list)
        self.downMap = defaultdict(list)
        self.status = State.IDLE

class ElevatorSystem:
    def __init__(self, elevator: Elevator):
        self.elevator = elevator
    
    # this is what happens when a consumer pushes the button to go up or down
    def addPerson(self, person: Person, source: int, target: int):
        if self.elevator.currentWeight + person.weight > self.elevator.weightLimit:
            # do something here
            print("cannot step into elevator, max capacity reached")

        up = False
        if source < target:
            up = True
        
        if up:
            # first decide if we need to increment the remainingLevels
            if source > self.elevator.currentLevel:
                self.elevator.remainingLevels += 1
            self.elevator.upMap[target].append(person)
        else:
            if source < self.elevator.currentLevel:
                self.elevator.remainingLevels += 1
            self.elevator.downMap[target].append(person)

    # really need this logic to be strong
    def moveElevator(self):
        # Get the appropriate map based on elevator status
        current_map = self.elevator.upMap if self.elevator.status == State.UP else self.elevator.downMap
        
        if self.elevator.currentLevel in current_map:
            self.elevator.remainingLevels -= 1

        # Remove people from the current level and update weight
        for person in current_map.pop(self.elevator.currentLevel, []):
            self.elevator.currentWeight -= person.weight
        
        # Update elevator status and remaining levels if needed
        if self.elevator.currentLevel == self.elevator.maxLevel:
            self.elevator.remainingLevels = len(self.elevator.downMap)
            self.elevator.status = State.DOWN
        elif self.elevator.currentLevel == 1:
            self.elevator.remainingLevels = len(self.elevator.upMap)
            self.elevator.status = State.UP
        else:
            self.elevator.currentLevel += 1 if self.elevator.status == State.UP else -1

        if 

