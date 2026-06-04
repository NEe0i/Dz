import pytest

# Симулируемая функция авторизации (Объект тестирования)
def login_system(username, password):
    if len(str(username)) > 50:
        return "Поле не принимает более 50 символов"
    if not username and not password:
        return "Введите логин и пароль"
    if username and not password:
        return "Введите пароль"
    if username == "admin" and password == "12345":
        return "Открывается главная страница"
    return "Неверный логин или пароль"


# --- ТЕСТОВЫЕ СЛУЧАИ ---

def test_tc01_successful_login():
    """TC-01: Успешный вход"""
    result = login_system("admin", "12345")
    assert result == "Открывается главная страница"

def test_tc02_invalid_username():
    """TC-02: Неверный логин"""
    result = login_system("user", "12345")
    assert result == "Неверный логин или пароль"

def test_tc03_invalid_password():
    """TC-03: Неверный пароль"""
    result = login_system("admin", "11111")
    assert result == "Неверный логин или пароль"

def test_tc04_empty_fields():
    """TC-04: Пустые поля"""
    result = login_system("", "")
    assert result == "Введите логин и пароль"

def test_tc05_only_username():
    """TC-05: Только логин"""
    result = login_system("admin", "")
    assert result == "Введите пароль"

def test_tc06_case_sensitivity():
    """TC-06: Регистр символов"""
    result = login_system("ADMIN", "12345")
    assert result == "Неверный логин или пароль"

def test_tc07_long_values():
    """TC-07: Длинные значения (валидация длины > 50 символов)"""
    long_username = "a" * 100
    result = login_system(long_username, "12345")
    assert result == "Поле не принимает более 50 символов"
