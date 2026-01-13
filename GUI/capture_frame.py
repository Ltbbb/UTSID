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

HALF_SCREEN_WIDTH = 400

class CaptureFrame(ttk.Frame): #inherits from frame

    def __init__(self, parent, style_arg):
        super().__init__(parent, style=style_arg) #init as frame

        self.grid_columnconfigure(0, uniform=1, minsize=HALF_SCREEN_WIDTH)
        self.grid_columnconfigure(1, uniform=1)
        self.grid_rowconfigure(0, weight=1)

        video = VideoFrame(self) #TODO: REPLACE
        video.grid(column=0,row=0,sticky="news")

        settings = SettingsFrame(self)
        settings.grid(column=1,row=0, sticky="news")

class SettingsFrame(ttk.Frame):

    def __init__(self, parent):
        s = ttk.Style()
        s.configure("Settings.TFrame", background="grey")
        super().__init__(parent, style="Settings.TFrame")

        self.grid_rowconfigure(0, weight=1)
        self.grid_rowconfigure(1, weight=1)

    
class VideoFrame(ttk.Frame):

    def __init__(self, parent):
        s = ttk.Style()
        s.configure("Video.TFrame", background="pink")
        super().__init__(parent, style="Video.TFrame")

        self.grid_rowconfigure(0, weight=1)
        self.grid_rowconfigure(1, weight=10)

        button = tk.Button(self, text="CAPTURE", command=self.capture_img)
        button.grid(column=0, row=1, sticky="news")

        self.panel = None
        self.video_frame = None
        self.img_ctr = 0

        #create picam object to use for video streaming
        self.picam2 = Picamera2()
        config = self.picam2.create_still_configuration()  #TODO: change configuration?
        self.picam2.configure(config)
        self.picam2.set_controls({"ExposureTime": 5000})
        self.picam2.start()

        #start a thread that constantly pools the video sensor for
		# the most recently read frame
        self.stopEvent = threading.Event()
        self.thread = threading.Thread(target=self.videoLoop, args=())
        self.thread.start()
    
    def capture_img(self):
        print("button press!!!!")
        capture = self.video_frame
        print(type(capture))
        image_name = f'img/finger_{self.img_ctr}.png' #TODO: Image storage
        self.img_ctr += 1
        cv2.imwrite(image_name, capture)

    def videoLoop(self):
		
		# try/except statement is a pretty ugly hack to get around
		# a RunTime error that Tkinter throws due to threading

        try:
			# keep looping over frames until we are instructed to stop
            while not self.stopEvent.is_set(): #TODO: stop event
				#use picam to capture the frames and resize
                self.video_frame = self.picam2.capture_array()
		
				#Change to image and resize
                image = Image.fromarray(self.video_frame).resize((HALF_SCREEN_WIDTH, 300))
                image = ImageOps.mirror(image)
                image = ImageTk.PhotoImage(image)
		
				# if the panel is None, we need to initialize it
                if self.panel is None:
                    self.panel = tk.Label(self, image=image, anchor="center")
                    self.panel.grid(column=0, row=0, sticky="nsew")
                else:
                    self.panel.configure(image=image)
                    self.panel.image = image

        except RuntimeError as e:
            print(f"[INFO] caught a RuntimeError: {e}")
