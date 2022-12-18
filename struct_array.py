import sys
from collections import deque

input = sys.stdin.readline

# 2차원 구조체 배열 선언
if __name__ == "__main__":
    T = int(input())
    mp = [[(0,0,0) for _ in range(10)] for _ in range(100)]
    ans = 0
