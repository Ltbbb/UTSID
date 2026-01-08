import tkinter as tk
from tkinter import ttk

root = tk.Tk()
root.title("Camera")
# root.geometry("600x400")
frame = ttk.Frame(root)
import tkinter as tk
from tkinter import TclError, ttk

# layout on the root window
root.columnconfigure(0, weight=4)
root.columnconfigure(1, weight=1)

def create_input_frame(container):
    frame = ttk.Frame(container, borderwidth="1", relief="ridge")

    frame.columnconfigure(0, weight=1)
    frame.columnconfigure(1, weight=3)

    ttk.Label(frame, text="hey").grid(column=0,row=0)
    keyword = ttk.Entry(frame, width=30)
    keyword.focus()
    keyword.grid(column=1, row=0, sticky=tk.W)

    ttk.Label(frame, text="replace").grid(column=0,row=1)
    replacement = ttk.Entry(frame, width=30)
    replacement.grid(column=1, row=1, sticky=tk.W)

    return frame

input_frame = create_input_frame(root)
input_frame.grid(column=0, row=0)

def create_button_frame(container):
    frame = ttk.Frame(container, borderwidth="1", relief="ridge")

    frame.columnconfigure(0, weight=1)

    ttk.Button(frame, text='Find Next').grid(column=0, row=0)
    ttk.Button(frame, text='Replace').grid(column=0, row=1)
    ttk.Button(frame, text='Replace All').grid(column=0, row=2)
    ttk.Button(frame, text='Cancel').grid(column=0, row=3)

    for widget in frame.winfo_children():
        widget.grid(padx=5, pady=5)

    return frame

button_frame = create_button_frame(root)
button_frame.grid(column=1, row=0)

root.mainloop()