def calculate_exp(x, n):
    ans = 1
    factorial = 1
    for i in range(1, n):
        factorial *= i
        ans += pow(x, i) / factorial
    return ans

if __name__ == '__main__':
    print(calculate_exp(2, 30))
