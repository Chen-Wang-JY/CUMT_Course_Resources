def factorial_sum(n):
    ans = 0
    cur = 1
    for factor in range(1, n + 1):
        cur *= factor
        ans += cur
    return ans

if __name__ == '__main__':
    print(factorial_sum(5))
