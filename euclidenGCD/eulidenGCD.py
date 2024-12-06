import tkinter as tk
from tkinter import messagebox

# Function to calculate GCD
def gcd(a , b) :
    if a < b:
        a, b = b, a 
    while (b != 0):
        # A = X . B + Y
        # x = a // b 
        # y = a % b 
        # a = b 
        # b = y 
        a, b = b, a % b
    return a

# Function to handle the button click
def calculate_gcd():
    try:
        # Get the inputs and calculate GCD
        num1 = int(entry1.get())
        num2 = int(entry2.get())
        result = gcd(num1, num2)
        # Display the result
        result_label.config(text=f"GCD: {result}")
    except ValueError:
        # Show error message if inputs are invalid
        messagebox.showerror("Invalid Input", "Please enter valid integers!")

# Create the main Tkinter window
root = tk.Tk()
root.title("GCD Calculator")

# Create and place labels, entry fields, and buttons
tk.Label(root, text="Enter First Number:").grid(row=0, column=0, padx=10, pady=10)
entry1 = tk.Entry(root)
entry1.grid(row=0, column=1, padx=10, pady=10)

tk.Label(root, text="Enter Second Number:").grid(row=1, column=0, padx=10, pady=10)
entry2 = tk.Entry(root)
entry2.grid(row=1, column=1, padx=10, pady=10)

calculate_button = tk.Button(root, text="Calculate GCD", command=calculate_gcd)
calculate_button.grid(row=2, column=0, columnspan=2, pady=10)

result_label = tk.Label(root, text="GCD: ")
result_label.grid(row=3, column=0, columnspan=2, pady=10)

# Start the Tkinter event loop
root.mainloop()
