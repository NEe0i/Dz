def func(num1, num2, operation):
    if operation == "+":
        return num1 + num2
    elif operation == "-":
        return num1 - num2
    elif operation == "*":
        return num1 * num2
    elif operation == "/":
        if num2 == 0:
            return "Ошибка: деление на ноль!"
        return num1 / num2
    elif operation == "//":
        if num2 == 0:
            return "Ошибка: деление на ноль!"
        return num1 // num2
    elif operation == "%":
        if num2 == 0:
            return "Ошибка: деление на ноль!"
        return num1 % num2
    else:
        return "Ошибка: неверная операция!"


def format_result(value):
    if not isinstance(value, (int, float)):
        return value  # Если вернулась строка с ошибкой, отдаем как есть
    if value.is_integer():
        return int(value)
    return round(value, 2)


memory = 0.0

while True:
    print("\n--- Калькулятор ---")
    print(f"Текущее значение в памяти (m): {format_result(memory)}")
    
    user_input = input("Нажмите Enter для расчета или введите 'выход': ")
    if user_input.lower() == "выход":
        print("Программа завершена.")
        break

    try:
        inp1 = input("Введите первое число (или 'm'): ").strip().lower()
        first_num = memory if inp1 in ("m", "м") else float(inp1)

        op = input("Введите операцию (+, -, *, /, //, %): ").strip()

        inp2 = input("Введите второе число (или 'm'): ").strip().lower()
        second_num = memory if inp2 in ("m", "м") else float(inp2)

        raw_result = func(first_num, second_num, op)
        formatted_result = format_result(raw_result)
        
        print(f"Результат: {formatted_result}")

        if isinstance(raw_result, (int, float)):
            memory = raw_result

    except ValueError:
        print("Ошибка: вводите только числа или 'm'!")
