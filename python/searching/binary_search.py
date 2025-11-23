"""
Title : Binary Search
Problem : N/A (Standard Algorithm)
Category: Searching / Divide and Conquer
Language: Python
Author : soyoung0108
Note : O(log N) iterative solution for finding an element in a sorted list.
"""
from typing import List

def binary_search(data: List[int], target: int) -> int:
    """
    정렬된 리스트(data)에서 target 값을 찾는 반복적 이진 탐색 함수.
    """
    low = 0
    high = len(data) - 1
    
    while low <= high:
        mid = (low + high) // 2
        
        if data[mid] == target:
            return mid
        elif data[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
            
    return -1

# 간단한 테스트 예제 
if __name__ == '__main__':
    sorted_list = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    
    # Assert를 통해 테스트 코드 포함 규칙 준수
    assert binary_search(sorted_list, 12) == 3 
    assert binary_search(sorted_list, 50) == -1 
    
    print("Test passed.")