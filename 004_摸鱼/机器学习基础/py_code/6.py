def judge(x):
    if x == 1 or x == 0:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

if __name__ == '__main__':
    for i in range(0, 21):
        print(i, judge(i))
