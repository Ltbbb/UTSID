import tkinter as tk
from tkinter import ttk
from tkinter import Menu
from capture_frame import CaptureFrame
from files_frame import FilesFrame
from compare_frame import CompareFrame
from utils.capture_framework import Framework
from picamera2 import Picamera2


class App(tk.Tk):

    def __init__(self):
        super().__init__()

        self.title("UTSID")
        self.geometry('1024x800')
        self.grid_columnconfigure(0,weight=1)
        self.grid_rowconfigure(0,weight=1)

        #creation of frame
        notebook = ttk.Notebook(self)
        notebook.grid(row=0, column=0, sticky="nsew")

        # Initialize styles
        s = ttk.Style()
        s.configure('Frame1.TFrame', background='red')
        s.configure('Frame2.TFrame', background='blue')
        s.configure('Frame3.TFrame', background='green')

        #Init video stream
        picam2 = Picamera2()
        capturing_framework = Framework(picam2=picam2, callback=)
        
        # Create first tab
        tab1 = CaptureFrame(notebook, "Frame1.TFrame")
        notebook.add(tab1, text="Capture")

        # Second tab
        tab2 = FilesFrame(notebook, 'Frame2.TFrame')
        notebook.add(tab2, text="Files")

        # Third tab
        tab3 = CompareFrame(notebook, 'Frame3.TFrame')
        notebook.add(tab3, text="Compare")

if __name__ == "__main__":
    app = App()
    app.mainloop()