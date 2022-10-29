# python3
from array import array
from collections import namedtuple
import os


def match(left, right):
    return (left + right) in ["()", "[]", "{}"]

def empty(stack):
    return not bool(stack)

def prior_to_current_result(current_result, val):
    opening = '([{'
    closing = ')]}'

    if current_result in opening and val in closing:
        return True
    return False


def find_mismatch(text):
    stack = []
    result = None

    for i, val in enumerate(text):
        if val not in '()[]{}':
            continue

        if empty(stack):
            result = i
            stack.append(val)
            continue

        top = stack[-1]
        if match(top, val):
            stack.pop()
            if empty(stack):
                result = None
            continue

        if prior_to_current_result(text[result], val):            
            result = i
        stack.append(val)


    if result is not None:
        return result + 1
    else:
        return 'Success'

def main():
    cur_dir = os.path.dirname(os.path.abspath(__file__))
    test_dir = cur_dir + '/tests/'
    for num in range(1, 55):
        if num < 10:
            num = f'0{num}'
        input_ = open(f'{test_dir}{num}').read().strip('\n')
        output_ = open(f'{test_dir}{num}.a').read().strip('\n')

        print(f'----- test number {num} -----')
        result = find_mismatch(input_)
        print(f'expected: {output_}')
        print(f'result: {result}')
        assert str(result) == output_


if __name__ == "__main__":
    main()