import cv2
import time
import utils.read_write as rw

def init_cam(picam2):
    config = picam2.create_still_configuration()  # Use still configuration
    picam2.configure(config)
    picam2.set_controls({"ExposureTime": 5000})
    picam2.start()

    # Give some time to the camera to start
    time.sleep(2)

    cv2.namedWindow('Camera')
    #cv2.setWindowProperty('Camera',cv2.WND_PROP_FULLSCREEN,cv2.WINDOW_FULLSCREEN)
        
    # Create trackbars for brightness and zoom
    cv2.createTrackbar('Brightness', 'Camera', 50, 100, on_brightness_change)
    cv2.createTrackbar('Zoom', 'Camera', 2, 20, on_zoom_change)
    cv2.createTrackbar('PWM', 'Camera', 100, 350, on_pwm_change)

# Function to adjust the brightness of the image
def adjust_brightness(image, brightness):
    return cv2.convertScaleAbs(image, alpha=1, beta=brightness)

# Function to apply zoom on the image
def apply_zoom(image, zoom_factor):
    height, width = image.shape[:2]
    center_x, center_y = width // 2, height // 2
    radius_x, radius_y = int(center_x / zoom_factor), int(center_y / zoom_factor)

    min_x, max_x = center_x - radius_x, center_x + radius_x
    min_y, max_y = center_y - radius_y, center_y + radius_y

    # Ensure the coordinates are within bounds
    min_x, max_x = max(min_x, 0), min(max_x, width)
    min_y, max_y = max(min_y, 0), min(max_y, height)

    cropped = image[min_y:max_y, min_x:max_x]
    return cv2.resize(cropped, (width, height))

# Callback functions for trackbars
def on_brightness_change(val):
    global brightness
    brightness = val - 50
    print(f"Brightness changed to: {brightness}")

def on_zoom_change(val):
    global zoom_factor
    zoom_factor = 1 + val / 10
    print(f"Zoom factor changed to: {zoom_factor}")
    
def on_pwm_change(val):
	global pwm_val
	pwm_val= val*10
	print(f"PWM factor changed to: {pwm_val}")
	rw.send_to_arduino(pwm_val)

def display_img(img_path: str, caption: str):
    if img_path is not None:
        img = cv2.imread(img_path)
        cv2.imshow(caption, img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()

        

