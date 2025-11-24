import cv2
from picamera2 import Picamera2, Preview
from libcamera import controls
import time

# Initialize Picamera2
picam2 = Picamera2()
config = picam2.create_still_configuration()
picam2.configure(config)
picam2.start()
time.sleep(2)
# Function to adjust the brightness of the image
def adjust_brightness(image, brightness):
    return cv2.convertScaleAbs(image, alpha=1, beta=brightness)

# Function to apply zoom on the image
def apply_zoom(image, zoom_factor):
    center_x, center_y = image.shape[1] // 2, image.shape[0] // 2
    radius_x, radius_y = int(center_x / zoom_factor), int(center_y / zoom_factor)

    min_x, max_x = center_x - radius_x, center_x + radius_x
    min_y, max_y = center_y - radius_y, center_y + radius_y

    cropped = image[min_y:max_y, min_x:max_x]
    return cv2.resize(cropped, (image.shape[1], image.shape[0]))

# Initial values for brightness and zoom
brightness = 0
zoom_factor = 1.0
image_counter=0

cv2.namedWindow('Camera')

# Callback functions for trackbars
def on_brightness_change(val):
    global brightness
    brightness = val - 50

def on_zoom_change(val):
    global zoom_factor
    zoom_factor = 1 + val / 10

# Create trackbars for brightness and zoom
cv2.createTrackbar('Brightness', 'Camera', 50, 100, on_brightness_change)
cv2.createTrackbar('Zoom', 'Camera', 10, 20, on_zoom_change)

while True:
    # Capture frame-by-frame
    frame = picam2.capture_array()

    # Adjust brightness and zoom
    frame = adjust_brightness(frame, brightness)
    frame = apply_zoom(frame, zoom_factor)

    # Display the frame
    cv2.imshow('Camera', frame)

    # Check for key press
    key = cv2.waitKey(1)
    if key==ord('i'):
        image_counter+=1
        image_name=f'image_{image_counter}.jpg'
        cv2.imwrite(image_name, frame)
        print(f"Image captured and saved as {image_name}")
    elif key == ord('q'):
        
        print("Quitting the program")
        break

# Release resources
cv2.destroyAllWindows()
picam2.stop()
