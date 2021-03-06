import random
import sys


logical_operators = ['>', '<', '==', '>=', '<=', '!=']
arithmetic_operators = ['+', '-', '*', '/', '%']


def randint(sign, max_pow=100):
    pow = random.randint(1, max_pow)
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


def generate_arithm_test():
    inputs = []
    outputs = []
    for i in [-1, 1]:
        for j in [-1, 1]:
            for _ in range(100):
                num1 = randint(i)
                num2 = randint(j)
                for operator in arithmetic_operators:
                    if num2 == 0 and operator in ['/', '%']:
                        continue
                    expr = str(num1) + ' ' + operator + ' ' + str(num2)
                    inputs.append(expr)
                    if operator == '/':
                        expr = i * j * ((i * num1) // (j * num2))
                        outputs.append(str(expr))
                    elif operator == '%':
                        expr = i * ((i * num1) % (j * num2))
                        outputs.append(str(expr))
                    else:
                        outputs.append(str(eval(expr)))
    return inputs, outputs


def generate_unary_test():
    inputs = []
    outputs = []
    for i in [-1, 1]:
        for _ in range(100):
            num = randint(i)
            inputs.append(str(num) + ' ++')
            outputs.append(str(num+1))
            inputs.append(str(num) + ' --')
            outputs.append(str(num-1))
            inputs.append(str(num) + ' -')
            outputs.append(str(-num))
    return inputs, outputs


inputs, outputs = generate_arithm_test()
save_test(inputs, outputs)
