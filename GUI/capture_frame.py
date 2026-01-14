import tkinter as tk
from tkinter import ttk
import imutils
import cv2
from PIL import Image, ImageTk, ImageOps
import threading
from imutils.video import VideoStream
import time
# from picamera2 import Picamera2
import numpy as np
import tkinter as tk
from tkinter import ttk
from tkinter.messagebox import showerror, showwarning, showinfo


HALF_SCREEN_WIDTH = 512 #400
currentfinger = "finger"
currentguide = "VX"
participantname = ""
SESSION_NUMBER = 1

class CaptureFrame(ttk.Frame): #inherits from frame

    def __init__(self, parent, style_arg):
        super().__init__(parent, style=style_arg) #init as frame

        self.grid_columnconfigure(0, weight=6)
        self.grid_columnconfigure(1, weight=4)
        self.grid_rowconfigure(0, weight=1)

        settings = SettingsFrame(self)
        settings.grid(column=1,row=0, sticky="news")

        video = VideoFrame(self, settings) #TODO: REPLACE
        video.grid(column=0,row=0,sticky="news")


class SettingsFrame(ttk.Frame):    

    def __init__(self, parent):
        # s = ttk.Style()
        # s.configure("Settings.TFrame", background="pink")
        super().__init__(parent)

        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)
        self.grid_rowconfigure(1, weight=1)

        self.create_sliders_block()
        self.create_settings_block()

    def create_settings_block(self):
        def setnamevar(one, two, three): #FIXME: this is given three params?
            global participantname
            name = participant_name_var.get()
            print(name)
            participantname = name
        
        # s = ttk.Style()
        # s.configure("Settings2.TFrame", background="cyan")
        settingsthing = ttk.Frame(self)
        settingsthing.grid(column=0,row=0,columnspan=2, sticky="ews")
        settingsthing.grid_columnconfigure(0,weight=1)
        settingsthing.grid_columnconfigure(1,weight=1)

        lf1 = self.create_labelframe(settingsthing, "Guide", ["V1", "V2", "V3", "V4", "X"])
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
                global currentfinger, currentguide
                var = name_var.get()
                if var.startswith("V"):
                    currentguide = var
                if var.startswith("L") or var.startswith("R"):
                    currentfinger = var

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

        slider1 = self.create_slider(parent=sliders, name="PWM")
        slider1.grid(column=0,row=0,sticky="ew", pady=10)

        slider2 = self.create_slider(parent=sliders, name="brightness")
        slider2.grid(column=0,row=1,sticky="ew", pady=10)

        slider3 = self.create_slider(parent=sliders, name="zoom")
        slider3.grid(column=0,row=2,sticky="ew", pady=10)

    def create_slider(self, parent, name):
        slider_container = ttk.Frame(parent)
        slider_container.grid_columnconfigure(0,weight=1)
        slider_container.grid_columnconfigure(1,weight=10)
        slider_container.grid_columnconfigure(2,weight=1)
        slider_container.grid_rowconfigure(0,weight=1)
        slider_container.grid_rowconfigure(1,weight=1)

        def on_slider_change(self):
            value_label.configure(text=f"{name}: {'{:.0f}'.format(slider_val.get())}")

        slider_val = tk.DoubleVar()
        ttk.Scale(
        slider_container,
        from_=0,
        to=100,
        orient='horizontal',  
        variable= slider_val,
        command=on_slider_change,
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


    
class VideoFrame(ttk.Frame):

    def __init__(self, parent, settingsframe: SettingsFrame):
        s = ttk.Style()
        s.configure("Video.TFrame", background="orange")
        super().__init__(parent, style="Video.TFrame")

        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=10)
        self.grid_rowconfigure(1, weight=1)

        button = tk.Button(self, text="CAPTURE", command=self.capture_img)
        button.grid(column=0, row=1, sticky="news")

        default_img = Image.open("test_imgs/1.png")
        default_img = ImageTk.PhotoImage(default_img)
        panel_frame = tk.Frame(self)
        self.panel = tk.Label(panel_frame, image=default_img, anchor="center")
        self.panel.grid(sticky="news")
        panel_frame.grid(column=0, row=0, sticky="nsew")
        
        self.video_frame = None
        self.img_ctr = 0

        #create picam object to use for video streaming
        # self.picam2 = Picamera2()
        # config = self.picam2.create_still_configuration()  #TODO: change configuration?
        # self.picam2.configure(config)
        # self.picam2.set_controls({"ExposureTime": 5000})
        # self.picam2.start()

        #start a thread that constantly pools the video sensor for
		# the most recently read frame
        self.stopEvent = threading.Event()
        self.thread = threading.Thread(target=self.videoLoop, args=())
        self.thread.start()
    
    def capture_img(self):
        global currentguide, currentfinger, SESSION_NUMBER
        print("button press!!!!")
        if currentfinger == "finger" or currentguide == "VX" or participantname == "":
            showwarning("Warning!", "Fill in all fields")
        capture = self.video_frame
        image_name = f'data/{currentguide}/{participantname}/{currentfinger}_{SESSION_NUMBER}_{self.img_ctr}.png' #TODO: Image storage #TODO: impl counter
        print(image_name)
        self.img_ctr += 1
        cv2.imwrite(image_name, capture)

    def videoLoop(self):
		
		# try/except statement is a pretty ugly hack to get around
		# a RunTime error that Tkinter throws due to threading

        try:
			# keep looping over frames until we are instructed to stop
            while not self.stopEvent.is_set(): #TODO: stop event
				#use picam to capture the frames and resize
                # self.video_frame = self.picam2.capture_array()
		
				#Change to image and resize
                # image = Image.fromarray(self.video_frame).resize((HALF_SCREEN_WIDTH, 300))
                # image = ImageOps.mirror(image)
                image = Image.open("test_imgs/1.png").resize((50, 50))
                image = ImageTk.PhotoImage(image)
		
				# if the panel is None, we need to initialize it
                self.panel.configure(image=image)
                self.panel.image = image

        except RuntimeError as e:
            print(f"[INFO] caught a RuntimeError: {e}")
