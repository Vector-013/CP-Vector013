def calculate_lucky_value(n, k):
    lucky_value = 0
    stack = [(1, n)]  # Stack to store segments as (l, r)

    while stack:
        l, r = stack.pop()
        length = r - l + 1

        if length < k:
            continue  # Skip segments smaller than k

        m = (l + r) // 2
        if length % 2 == 0:
            # Even-length segment: split into two halves
            stack.append((l, m))
            stack.append((m + 1, r))
        else:
            # Odd-length segment: add m to lucky value
            lucky_value += m
            stack.append((l, m - 1))
            stack.append((m + 1, r))

    return lucky_value

# Input values
n = 10**9  # Large value for the number of stars
k = 10**6  # Laziness threshold

# Calculate and print final lucky value
print("Final Lucky Value:", calculate_lucky_value(n, k))
