class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.active_tokens = {}
        self.time_to_live = timeToLive

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.active_tokens[tokenId] = currentTime + self.time_to_live

    def renew(self, tokenId: str, currentTime: int) -> None:
        if tokenId in self.active_tokens and self.active_tokens[tokenId] > currentTime:
            self.active_tokens[tokenId] = currentTime + self.time_to_live

    def countUnexpiredTokens(self, currentTime: int) -> int:
        num = 0
        for token in self.active_tokens:
            if self.active_tokens[token] > currentTime:
                num += 1
        return num


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
