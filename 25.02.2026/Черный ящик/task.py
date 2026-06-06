class TicketSystem:
    def __init__(self):

        self.state = "IDLE"

    def start_booking(self):
        if self.state == "IDLE":
            self.state = "CHOOSING"
            return "Система готова к выбору билетов"
        return "Ошибка: Бронирование уже запущено"

    def calculate_ticket(self, age: int, is_student: bool) -> float:
        """
        Рассчитывает стоимость билета.
        Базовая цена: 1000 рублей.
        Правила:
        - Детям до 7 лет (не включая 7) — вход запрещен (ошибка).
        - Пенсионерам (65 лет и старше) — скидка 50% (цена 500).
        - Студентам (от 17 до 25 лет включительно) при наличии студенческого — скидка 30% (цена 700).
        - В остальных случаях — полная цена (1000).
        """
        if self.state != "CHOOSING":
            raise RuntimeError("Ошибка: Перейдите в режим выбора билетов")

        if age < 0 or age > 120:
            raise ValueError("Некорректный возраст")

        if age < 7:
            raise ValueError("Слишком маленький возраст для сеанса")

        if age >= 65:
            return 500.0

        if 17 <= age <= 25 and is_student:
            return 700.0

        return 1000.0

    def confirm_booking(self):
        if self.state == "CHOOSING":
            self.state = "CONFIRMED"
            return "Билет успешно забронирован"
        return "Ошибка: Нечего подтверждать"
