from tkinter import ttk

class CompareFrame(ttk.Frame):#inherits from frame

    def __init__(self, parent, style_arg):
        super().__init__(parent, style=style_arg) #init as frame

        button = ttk.Button(self, text="yippe")
        button.grid(column=0,row=0)

        button2 = ttk.Button(self, text="3rd screen")
        button2.grid(column=1,row=0)