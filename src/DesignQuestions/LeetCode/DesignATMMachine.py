from collections import defaultdict
from typing import List


class ATM:
    def __init__(self):
        # we can have map: bank note, frequency
        self.notes = defaultdict(int)
        self.bankNotes = [20, 50, 100, 200, 500]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(len(banknotesCount)):
            noteAmount = self.bankNotes[i]
            self.notes[noteAmount] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        result = [0] * 5
        for i in range(len(self.bankNotes) - 1, -1, -1):
            noteAmount = self.bankNotes[i]
            q = amount // noteAmount

            if q > 0:
                deduct = min(q, self.notes[noteAmount])
                amount -= noteAmount * deduct
                result[i] = deduct
                self.notes[noteAmount] -= deduct

        if amount == 0:
            # we were able to break apart
            return result
        else:
            # add the result deductions back into the system
            for i in range(len(result)):
                self.notes[self.bankNotes[i]] += result[i]

        return [-1]
