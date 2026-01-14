import tkinter as tk
from tkinter import ttk
import imutils
import cv2
from PIL import Image, ImageTk, ImageOps
import threading
from imutils.video import VideoStream
import time
from picamera2 import Picamera2
import numpy as np
import tkinter as tk
from tkinter import ttk
from tkinter.messagebox import showerror, showwarning, showinfo
import utils.read_write as rw

class SettingsFrame(ttk.Frame):    

    def __init__(self, parent):
        # s = ttk.Style()
        # s.configure("Settings.TFrame", background="pink")
        super().__init__(parent)

        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self.grid_rowconfigure(1, weight=1)

        self.currentfinger = None
        self.currentguide = None
        self.participantname = None

        self.create_sliders_block()
        self.create_settings_block()

    def create_settings_block(self):
        def setnamevar(one, two, three): #FIXME: this is given three params?
            name = participant_name_var.get()
            print(name)
            self.participantname = name
        
        # s = ttk.Style()
        # s.configure("Settings2.TFrame", background="cyan")
        settingsthing = ttk.Frame(self)
        settingsthing.grid(column=0,row=0,columnspan=2, sticky="ews")
        settingsthing.grid_columnconfigure(0,weight=1)
        settingsthing.grid_columnconfigure(1,weight=1)

        lf1 = self.create_labelframe(settingsthing, "Guide", ["V1", "V2", "V3", "V4", "VX"])
        lf1.grid(column=0, row=1, sticky="news")

        lf1 = self.create_labelframe(settingsthing, "Finger", ["L_Index", "L_Middle", "L_Ring", "R_Index", "R_Middle", "R_Ring", "X"])
        lf1.grid(column=1, row=1, sticky="news")

        name_label = ttk.Label(settingsthing, text="Name:")
        name_label.grid(column=0,row=0,sticky="news", pady=10)

        participant_name_var = tk.StringVar()
        participant_name_var.trace_add("write", callback=setnamevar)
        namebox = ttk.Entry(settingsthing, textvariable=participant_name_var)
        namebox.grid(column=1,row=0,sticky="news", pady=10)

    def create_labelframe(self, parent, name, values: list):
            def selected():
                var = name_var.get()
                if var.startswith("V"):
                    self.currentguide = var
                if var.startswith("L") or var.startswith("R"):
                    self.currentfinger = var

            lf = ttk.LabelFrame(parent, text=name)

            name_var = tk.StringVar()

            grid_row = 0

            for val in values:
                # create a radio button
                radio = ttk.Radiobutton(lf, text=val, value=val, variable=name_var, command=selected)
                radio.grid(row=grid_row, column=0, ipadx=10, ipady=10, sticky="nw")
                # grid column
                grid_row += 1
            return lf
            

    def create_sliders_block(self):
        # s = ttk.Style()
        # s.configure("Sliders.TFrame", background="blue")
        sliders = ttk.Frame(self)
        sliders.grid(column=0,row=1,sticky="ews")

        sliders.grid_columnconfigure(0,weight=1)
        sliders.grid_rowconfigure(0, weight=1)
        sliders.grid_rowconfigure(1, weight=1)
        sliders.grid_rowconfigure(2, weight=1)

        self.slider1 = self.create_slider(parent=sliders, name="PWM", callback=self.PWM_callback)
        self.slider1.grid(column=0,row=0,sticky="ew", pady=10)

        slider2 = self.create_slider(parent=sliders, name="brightness", callback=None)
        slider2.grid(column=0,row=1,sticky="ew", pady=10)

        slider3 = self.create_slider(parent=sliders, name="zoom", callback=None)
        slider3.grid(column=0,row=2,sticky="ew", pady=10)

    def PWM_callback(self, val):
        pwm_val= int(val.split(".")[0]) * 10
        print(f"PWM factor changed to: {pwm_val}")
        rw.send_to_arduino(pwm_val)

    def create_slider(self, parent, name, callback):
        slider_container = ttk.Frame(parent)
        slider_container.grid_columnconfigure(0,weight=1)
        slider_container.grid_columnconfigure(1,weight=10)
        slider_container.grid_columnconfigure(2,weight=1)
        slider_container.grid_rowconfigure(0,weight=1)
        slider_container.grid_rowconfigure(1,weight=1)

        def on_slider_change(self):
            value_label.configure(text=f"{name}: {'{:.0f}'.format(slider_val.get())}")

        slider_val = tk.IntVar()
        ttk.Scale(
        slider_container,
        from_=0,
        to=100,
        orient='horizontal',  
        variable= slider_val,
        command=callback,
        # length=HALF_SCREEN_WIDTH - 5,
        ).grid(column=0,row=0,columnspan=3, sticky="ew")

        # value label
        value_label = ttk.Label(
            slider_container,
            text=f"{name}: {slider_val.get()}",
        )
        value_label.grid(row=1,column=1)

        plus_button = ttk.Button(slider_container,text="+").grid(row=1, column=2, sticky="n")
        minus_button = ttk.Button(slider_container,text="-").grid(row=1, column=0, sticky="n")

        return slider_container

