import tkinter as tk
from tkinter import ttk
import imutils
import cv2
from PIL import Image
from PIL import ImageTk
import threading

class CaptureFrame(ttk.Frame): #inherits from frame

    def __init__(self, parent, style_arg):
        super().__init__(parent, style=style_arg) #init as frame

        self.grid_columnconfigure(0, weight=1)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        video = VideoFrame(self)
        video.grid(column=0,row=0,sticky="snew")
        
    
class VideoFrame(ttk.Frame):

    def __init__(self, parent, video_stream):
        super().__init__(parent, style="Video.TFrame")
        # self.grid_columnconfigure(0, weight=1)
        # self.grid_rowconfigure(0, weight=1)

        s = ttk.Style()
        s.configure("Video.TFrame", background="pink")

        self.video_stream = video_stream
        self.video_frame = None
        self.panel = None

        #start a thread that constantly pools the video sensor for
		# the most recently read frame
        self.stopEvent = threading.Event()
        self.thread = threading.Thread(target=self.videoLoop, args=())
        self.thread.start()


    def videoLoop(self):
		# DISCLAIMER:
		# I'm not a GUI developer, nor do I even pretend to be. This
		# try/except statement is a pretty ugly hack to get around
		# a RunTime error that Tkinter throws due to threading
        try:
			# keep looping over frames until we are instructed to stop
            while not self.stopEvent.is_set():
				# grab the frame from the video stream and resize it to have a maximum width of 300 pixels
                self.video_frame = self.vs.read()
                self.video_frame = imutils.resize(self.video_frame, width=300)
		
				# OpenCV represents images in BGR order; however PIL
				# represents images in RGB order, so we need to swap
				# the channels, then convert to PIL and ImageTk format
                image = cv2.cvtColor(self.video_frame, cv2.COLOR_BGR2RGB)
                image = Image.fromarray(image)
                image = ImageTk.PhotoImage(image)
		
				# if the panel is not None, we need to initialize it
                if self.panel is None:
                    self.panel = tk.Label(image=image)
                    self.panel.image = image
                    self.panel.pack(side="left", padx=10, pady=10)
		
				# otherwise, simply update the panel
                else:
                    self.panel.configure(image=image)
                    self.panel.image = image
        except RuntimeError as e:
            print(f"[INFO] caught a RuntimeError: {e}")