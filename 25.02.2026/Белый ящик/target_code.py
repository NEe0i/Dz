def check_credit_eligibility(age: int, income: int, has_criminal_record: bool) -> str:
    # Базовая проверка возраста
    if age < 18 or age > 70:
        return "Отказ: возраст вне диапазона"
    
    # Сложное условие с составными элементами для проверки условий (Condition Coverage)
    if income >= 50000 and not has_criminal_record:
        return "Одобрено"
    else:
        return "Отказ: низкий доход или плохая история"
