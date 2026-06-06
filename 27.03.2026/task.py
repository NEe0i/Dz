import tkinter as tk

def click_up():
    global counter
    counter += 1
    label.config(text=f"Счет: {counter}")

def click_down():
    global counter
    counter -= 1
    label.config(text=f"Счет: {counter}")

window = tk.Tk()
window.title("Кликер")

window_width = 300
window_height = 200

window.resizable(False, False)

screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()

center_x = int(screen_width / 2 - window_width / 2)
center_y = int(screen_height / 2 - window_height / 2)

window.geometry(f"{window_width}x{window_height}+{center_x}+{center_y}")

counter = 0

label = tk.Label(window, text=f"Счет: {counter}", font=("Arial", 16))
label.pack(pady=20)

btn_up = tk.Button(window, text="Увеличить (+)", command=click_up, width=15)
btn_up.pack(pady=5)

btn_down = tk.Button(window, text="Уменьшить (-)", command=click_down, width=15)
btn_down.pack(pady=5)

window.mainloop()
