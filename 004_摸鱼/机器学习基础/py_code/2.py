def factorial(n):
    ans = 1
    for factor in range(1, n + 1):
        ans *= factor
    return ans

if __name__ == '__main__':
    ans = 0
    for i in range(1, 6):
        ans += factorial(i)
    print(ans)