from tkinter import ttk

class FilesFrame(ttk.Frame): #inherits from frame

    def __init__(self, parent, style_arg):
        super().__init__(parent, style=style_arg) #init as frame

        self.columnconfigure(0, weight=2)
        self.columnconfigure(1, weight=2)

        button = ttk.Button(self, text="omg")
        button.grid(column=0,row=0)

        button2 = ttk.Button(self, text="2nd screen")
        button2.grid(column=1,row=0)