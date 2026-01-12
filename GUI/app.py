import tkinter as tk
from tkinter import ttk
from tkinter import Menu

class App(tk.Tk):

    def __init__(self):
        super().__init__()

        self.title("App")
        self.geometry("800x480")
        self.resizable(False, False) #TODO: change?

        self.create_menu()

    def create_menu(self):
        menubar = Menu(self)
        menubar.add_command(label ='Capture', command=self.change_to_capture())
        menubar.add_command(label ='Files', command=self.change_to_files())
        menubar.add_command(label ='Compare', command=self.change_to_compare())

        self.config(menu = menubar)

    def change_to_capture(self):
        print("hey!")
        frame = CaptureFrame(self)
        frame.grid(column=0,row=0)
        frame.tkraise()

    def change_to_files(self):
        None

    def change_to_compare(self):
        None
    
class CaptureFrame(ttk.Frame): #inherits from frame

    def __init__(self, parent):
        super().__init__(parent, borderwidth="1", relief="raised") #init as frame

        self.columnconfigure(0, weight=2)
        self.columnconfigure(1, weight=2)

        button = ttk.Button(self, text="hey")
        button.grid(column=0,row=0)

        button2 = ttk.Button(self, text="hello")
        button2.grid(column=1,row=0)


if __name__ == "__main__":
    app = App()
    # ContainerFrame(app)
    # ControlLabelFrame(app)
    app.mainloop()