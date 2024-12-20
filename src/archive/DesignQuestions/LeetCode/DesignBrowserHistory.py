class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.index = 0

    def visit(self, url: str) -> None:
        for i in range(self.index + 1, len(self.history)):
            self.history.pop()
        self.history.append(url)
        self.index += 1

    def back(self, steps: int) -> str:
        count = min(self.index, steps)
        self.index -= count
        return self.history[self.index]

    def forward(self, steps: int) -> str:
        count = min(len(self.history) - self.index - 1, steps)
        self.index += count
        return self.history[self.index]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
