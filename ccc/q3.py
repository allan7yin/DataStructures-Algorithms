# import sys
# from collections import defaultdict


# def pen():

#     input = sys.stdin.readline

#     N, M, Q = map(int, input().split())

#     colour = [0] * (N + 1)
#     prettiness = [0] * (N + 1)

#     pens_by_colour = defaultdict(list)

#     for i in range(1, N + 1):
#         c_i, p_i = map(int, input().split())
#         colour[i] = c_i
#         prettiness[i] = p_i
#         pens_by_colour[c_i].append(i)

#     def compute_best(pen_list):
#         if not pen_list:
#             return (0, -1)
#         best1_val = -1
#         best2_val = -1
#         for pen_id in pen_list:
#             p = prettiness[pen_id]
#             if p > best1_val:
#                 best2_val = best1_val
#                 best1_val = p
#             elif p > best2_val:
#                 best2_val = p
#         if best2_val < 0 and len(pen_list) == 1:
#             return (best1_val, -1)
        
#         return (best1_val, best2_val)

#     best1 = [0] * (M + 1)
#     best2 = [-1] * (M + 1)
#     for c in range(1, M + 1):
#         b1, b2 = compute_best(pens_by_colour[c])
#         best1[c], best2[c] = b1, b2

#     S = sum(best1[1:])

#     def compute_answer():

#         valid_b2 = [(best2[c], c) for c in range(1, M + 1) if best2[c] >= 0]
#         if not valid_b2:
#             return S

#         max1_val, max1_col = -1, -1
#         max2_val, max2_col = -1, -1
#         for val, col in valid_b2:
#             if val > max1_val:
#                 max2_val, max2_col = max1_val, max1_col
#                 max1_val, max1_col = val, col
#             elif val > max2_val:
#                 max2_val, max2_col = val, col

#         min1_val, min1_col = 10 ** 15, -1
#         min2_val, min2_col = 10 ** 15, -1
#         for c in range(1, M + 1):
#             val = best1[c]
#             if val < min1_val:
#                 min2_val, min2_col = min1_val, min1_col
#                 min1_val, min1_col = val, c
#             elif val < min2_val:
#                 min2_val, min2_col = val, c

#         if max1_col != min1_col:
#             improvement = max1_val - min1_val
#         else:
#             cand1 = (max2_val - min1_val) if max2_val >= 0 else -10 ** 15
#             cand2 = (max1_val - min2_val)
#             improvement = max(cand1, cand2)

#         if improvement < 0:
#             improvement = 0
#         return S + improvement

#     print(compute_answer())

#     updates = []
#     for _ in range(Q):
#         updates.append(input().split())

#     def refresh_colour(c):
#         nonlocal S
#         old_b1 = best1[c]
#         b1, b2 = compute_best(pens_by_colour[c]) if pens_by_colour[c] else (0, -1)
#         best1[c], best2[c] = b1, b2
#         S = S - old_b1 + b1

#     for update_line in updates:
#         t = int(update_line[0])
#         i_ = int(update_line[1])
#         val = int(update_line[2])

#         old_c = colour[i_]
#         if t == 1:
#             new_c = val
#             pens_by_colour[old_c].remove(i_)
#             pens_by_colour[new_c].append(i_)
#             colour[i_] = new_c
#             refresh_colour(old_c)
#             refresh_colour(new_c)
#         else:
#             new_p = val
#             prettiness[i_] = new_p
#             refresh_colour(old_c)

#         print(compute_answer())

# pen()

import sys
from collections import defaultdict
from sortedcontainers import SortedList

def max_pretty_painting():
    input = sys.stdin.readline

    N, M, Q = map(int, input().split())

    colour_array = [0]*(N+1)
    pretty_values = [0]*(N+1)

    pens_by_colour = [SortedList() for _ in range(M+1)]
    
    for i in range(1, N+1):
        c_i, p_i = map(int, input().split())
        colour_array[i] = c_i
        pretty_values[i] = p_i
        pens_by_colour[c_i].add(p_i)
    
    best1 = [0]*(M+1)
    best2 = [-1]*(M+1)
    
    def compute_top_prettiness(c):
        sorted_pretty_values = pens_by_colour[c]
        n = len(sorted_pretty_values)
        if n == 0:
            return (0, -1)
        elif n == 1:
            return (sorted_pretty_values[-1], -1)
        else:
            return (sorted_pretty_values[-1], sorted_pretty_values[-2])

    for c in range(1, M+1):
        b1, b2 = compute_top_prettiness(c)
        best1[c] = b1
        best2[c] = b2

    total_pretty_sum = sum(best1[1:])

    best1_list = SortedList()
    best2_list = SortedList()

    for c in range(1, M+1):
        best1_list.add((best1[c], c))
        if best2[c] != -1:
            best2_list.add((best2[c], c))

    def compute_maximum_prettiness():
        if len(best2_list) == 0:
            return total_pretty_sum

        if len(best1_list) == 1:
            return total_pretty_sum
        min1_val, min1_col = best1_list[0]
        min2_val, min2_col = best1_list[1]

        if len(best2_list) == 1:
            max1_val, max1_col = best2_list[-1]
            max2_val, max2_col = -1, -1
        else:
            max1_val, max1_col = best2_list[-1]
            max2_val, max2_col = best2_list[-2]

        if max1_col != min1_col:
            improvement = max1_val - min1_val
        else:
            cand1 = (max2_val - min1_val) if (max2_val >= 0) else float('-inf')
            cand2 = max1_val - min2_val
            improvement = max(cand1, cand2)

        if improvement < 0:
            improvement = 0
        return total_pretty_sum + improvement

    print(compute_maximum_prettiness())

    def update_colour(c):
        nonlocal total_pretty_sum
        best1_list.remove((best1[c], c))
        if best2[c] != -1:
            best2_list.remove((best2[c], c))

        old_b1 = best1[c]
        new_b1, new_b2 = compute_top_prettiness(c)
        best1[c], best2[c] = new_b1, new_b2

        total_pretty_sum += (new_b1 - old_b1)

        best1_list.add((new_b1, c))
        if new_b2 != -1:
            best2_list.add((new_b2, c))

    for _ in range(Q):
        t, i_, val = map(int, input().split())
        old_c = colour_array[i_]

        if t == 1:
            new_c = val

            pens_by_colour[old_c].remove(pretty_values[i_])
            update_colour(old_c)

            pens_by_colour[new_c].add(pretty_values[i_])
            colour_array[i_] = new_c
            update_colour(new_c)

            print(compute_maximum_prettiness())

            pens_by_colour[new_c].remove(pretty_values[i_])
            update_colour(new_c)
            pens_by_colour[old_c].add(pretty_values[i_])
            colour_array[i_] = old_c
            update_colour(old_c)

        else:
            old_p = pretty_values[i_]
            new_p = val
            pretty_values[i_] = new_p

            pens_by_colour[old_c].remove(old_p)
            pens_by_colour[old_c].add(new_p)
            update_colour(old_c)

            print(compute_maximum_prettiness())

max_pretty_painting()