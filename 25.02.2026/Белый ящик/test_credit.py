import pytest
from target_code import check_credit_eligibility

# =====================================================================
# 1. Покрытие операторов (Statement Coverage)
# Цель: выполнить каждую строчку кода хотя бы один раз.
# Достаточно 3 тестов, чтобы зайти в каждый return.
# =====================================================================

def test_statement_coverage_1():
    # Выполняет первый if (age < 18) и его return
    assert check_credit_eligibility(17, 60000, False) == "Отказ: возраст вне диапазона"

def test_statement_coverage_2():
    # Проходит первый if, заходит во второй if и его return
    assert check_credit_eligibility(25, 60000, False) == "Одобрено"

def test_statement_coverage_3():
    # Проходит первый if, падает во ветку else второго if и её return
    assert check_credit_eligibility(25, 30000, False) == "Отказ: низкий доход или плохая история"


# =====================================================================
# 2. Покрытие ветвей (Branch Coverage)
# Цель: проверить все направления развилок (True/False для каждого if).
# Наша функция имеет два блока if-else:
# - Первый if: True (выход), False (идем дальше).
# - Второй if: True (выход), False (идем в else).
# Тесты ниже закрывают все направления.
# =====================================================================

def test_branch_first_if_true():
    assert check_credit_eligibility(75, 80000, False) == "Отказ: возраст вне диапазона"

def test_branch_first_if_false_second_if_true():
    assert check_credit_eligibility(30, 55000, False) == "Одобрено"

def test_branch_second_if_false():
    assert check_credit_eligibility(30, 20000, False) == "Отказ: низкий доход или плохая история"


# =====================================================================
# 3. Покрытие условий (Condition Coverage)
# Цель: Каждое элементарное под-условие должно побывать True и False.
# Разберем второй if: (income >= 50000) AND (not has_criminal_record)
# Условие А: income >= 50000. Нужно проверить: True (>=50к) и False (<50к)
# Условие Б: not has_criminal_record. Нужно проверить: True (False) и False (True)
# =====================================================================

def test_condition_coverage():
    # Тест 1: Условие А = True (60000), Условие Б = True (not False -> True)
    assert check_credit_eligibility(30, 60000, False) == "Одобрено"
    
    # Тест 2: Условие А = False (40000), Условие Б = False (not True -> False)
    assert check_credit_eligibility(30, 40000, True) == "Отказ: низкий доход или плохая история"
