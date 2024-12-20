import math
def getMaxUpgradedServers(num_servers,money,sell,upgrade):
    res = []
    for c, u, s, m in zip(num_servers, upgrade, sell, money):
        to_sell = math.ceil((c*u - m)/(s + u))
        res.append(c - to_sell if to_sell > 0 else c)
    return res