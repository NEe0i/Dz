import pytest
from target_code import check_credit_eligibility

# 1. Покрытие операторов (Statement Coverage)


def test_statement_coverage_1():

    assert check_credit_eligibility(17, 60000, False) == "Отказ: возраст вне диапазона"

def test_statement_coverage_2():
    assert check_credit_eligibility(25, 60000, False) == "Одобрено"

def test_statement_coverage_3():
    assert check_credit_eligibility(25, 30000, False) == "Отказ: низкий доход или плохая история"

# 2. Покрытие ветвей (Branch Coverage)

def test_branch_first_if_true():
    assert check_credit_eligibility(75, 80000, False) == "Отказ: возраст вне диапазона"

def test_branch_first_if_false_second_if_true():
    assert check_credit_eligibility(30, 55000, False) == "Одобрено"

def test_branch_second_if_false():
    assert check_credit_eligibility(30, 20000, False) == "Отказ: низкий доход или плохая история"

# 3. Покрытие условий (Condition Coverage)

def test_condition_coverage():
    assert check_credit_eligibility(30, 60000, False) == "Одобрено"
    assert check_credit_eligibility(30, 40000, True) == "Отказ: низкий доход или плохая история"
