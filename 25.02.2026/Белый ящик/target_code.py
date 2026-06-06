def check_credit_eligibility(age: int, income: int, has_criminal_record: bool) -> str:

    if age < 18 or age > 70:
        return "Отказ: возраст вне диапазона"
    
    
    if income >= 50000 and not has_criminal_record:
        return "Одобрено"
    else:
        return "Отказ: низкий доход или плохая история"
