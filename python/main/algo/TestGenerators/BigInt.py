import random
import sys


logical_operators = ['>', '<', '==', '>=', '<=', '!=']


def randint(sign):
    pow = random.randint(1, 100)
    if sign > 0:
        return random.randint(0, 10**pow)
    return random.randint(-10**pow, 0)


def save_test(inputs, outputs):
    with open(sys.argv[1] + '.in', 'w') as file:
        file.write(str(len(inputs)) + '\n')
        file.write('\n'.join(inputs))
    with open(sys.argv[1] + '.out', 'w') as file:
        file.write('\n'.join(outputs))


def generate_logic_zero_test():
    inputs = []
    outputs = []
    for i in ['-0', '0']:
        for j in ['-0', '0']:
            for operator in logical_operators:
                expr = i + ' ' + operator + ' ' + j
                inputs.append(expr)
                outputs.append(str(int(eval(expr))))
    return inputs, outputs


def generate_logic_test():
    inputs = []
    outputs = []
    for i in [-1, 1]:
        for j in [-1, 1]:
            for _ in range(100):
                num1 = randint(i)
                num2 = randint(j)
                for operator in logical_operators:
                    expr = str(num1) + ' ' + operator + ' ' + str(num2)
                    inputs.append(expr)
                    outputs.append(str(int(eval(expr))))
    return inputs, outputs


inputs, outputs = generate_logic_test()
save_test(inputs, outputs)
