from collections import Counter

# modify the cpp version to reflect this logic
def consistent_logs(user_event):
    freq = Counter(user_event)
    min_value = min(freq.values())

    event_count = Counter()
    l = max_length = 0
    mxid = -1
    mxval = 0
    for r in range(len(user_event)):
        event_count[user_event[r]] += 1
        if event_count[user_event[r]] > mxval:
            mxval = event_count[user_event[r]]
            mxid = user_event[r]
        while mxval > min_value:
            event_count[user_event[l]] -= 1
            if user_event[l] == mxid:
                mxval -= 1
            if event_count[user_event[l]] == 0:
                del event_count[user_event[l]]
            l += 1

        max_length = max(max_length, r - l + 1)

    return max_length

es = [1, 2, 1, 3, 4, 2, 4, 3, 3, 4]
print(consistent_logs(es))