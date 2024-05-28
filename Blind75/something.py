def validate(rule,transaction):
    for merchant in rule.keys():
        if merchant == "points":
            continue
        if merchant not in transaction.keys():
            return False
        if transaction[merchant] < rule[merchant]:
            return False
    return True
def f(transactions):
    rules = [
        {"points": 500, "Sport Check": 75, "Tim Hortons": 25, "Subway": 25},
        {"points": 300, "Sport Check": 75, "Tim Hortons": 25},
        {"points": 200, "Sport Check": 75},
        {"points": 150, "Sport Check": 25, "Tim Hortons": 10, "Subway": 10},
        {"points": 75, "Sport Check": 25, "Tim Hortons": 10},
        {"points": 75, "Sport Check": 20},
    ]
    def dp(transactions):
        points = sum(transactions.values())
        for rule in rules:
            if validate(rule,transactions):
                cpy = transactions.copy()
                for merchant in cpy.keys():
                    if merchant not in rule:
                        continue
                    cpy[merchant] -= rule[merchant]
                pts = rule["points"] + dp(cpy)
                points = max(pts,points)
        return points
    ans = dp(transactions)
    return ans
transactions = {
    "Sport Check": 25,
    "Tim Hortons": 10,
    "Subway": 5
}

ans = f(transactions)
print(ans)