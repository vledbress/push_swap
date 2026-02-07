import subprocess
import random
import sys

# --- НАСТРОЙКИ ---
NUM_COUNT = 500    # Сколько чисел сортируем
ITERATIONS = 200  # Сколько раз запускаем
PATH_TO_PS = "./push_swap" # Путь к твоему исполняемому файлу

def run_test():
    # Генерируем уникальные случайные числа
    nums = random.sample(range(-1000, 1000), NUM_COUNT)
    arg = " ".join(map(str, nums))

    # Запускаем push_swap и получаем вывод
    try:
        result = subprocess.run([PATH_TO_PS, *map(str, nums)], 
                                capture_output=True, text=True, check=True)
    except subprocess.CalledProcessError as e:
        return None, f"Error: {e}"

    operations = result.stdout.splitlines()
    
    # Имитируем работу стека для проверки сортировки
    a = list(nums)
    b = []
    
    for op in operations:
        try:
            apply_op(op, a, b)
        except Exception as e:
            return None, f"Invalid operation: {op}"

    # Проверка: стек B пуст, а стек A отсортирован
    is_ok = (not b) and (a == sorted(nums))
    return len(operations), is_ok

def apply_op(op, a, b):
    if op == "sa" and len(a) > 1: a[0], a[1] = a[1], a[0]
    elif op == "sb" and len(b) > 1: b[0], b[1] = b[1], b[0]
    elif op == "pa" and b: a.insert(0, b.pop(0))
    elif op == "pb" and a: b.insert(0, a.pop(0))
    elif op == "ra" and a: a.append(a.pop(0))
    elif op == "rb" and b: b.append(b.pop(0))
    elif op == "rra" and a: a.insert(0, a.pop())
    elif op == "rrb" and b: b.insert(0, b.pop())
    # Добавь rr, rrr, ss если твой алгоритм их использует

def main():
    total_ops = 0
    max_ops = 0
    results = []

    print(f"--- Тестирование {PATH_TO_PS} | {NUM_COUNT} чисел ---")
    
    for i in range(ITERATIONS):
        ops_count, is_ok = run_test()
        if ops_count is None:
            print(f"Тест {i+1}: {is_ok}")
            continue
            
        status = "OK" if is_ok else "KO"
        print(f"Тест {i+1}: {ops_count} операций [{status}]")
        
        results.append(ops_count)
        total_ops += ops_count
        max_ops = max(max_ops, ops_count)

    print("\n--- Итог ---")
    print(f"Среднее: {total_ops // ITERATIONS}")
    print(f"Максимум: {max_ops}")

if __name__ == "__main__":
    main()