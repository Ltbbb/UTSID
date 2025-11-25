import cv2
from picamera2 import Picamera2
import refactor.utils.imaging as im
import refactor.utils.preprocess as prep
import refactor.utils.read_write as rw

KEY_TAKE_PICTURE = "i"
KEY_QUIT = "q"
IMAGE_FOLDER = "/img/" #TODO: impl image folder

# Initial values for brightness and zoom
brightness = 0
zoom_factor = 0
pwm_val = 0

img_ctr = 0  # Counter for images
image_paths = []  # List to store paths of captured images

def main():
    capture_images()
    best_img_f, best_img_l = determine_best_img()

    #Display the best image
    im.display_img(best_img_l, "Best Image Laplace")
    im.display_img(best_img_f, "Best Image Fourier")

def capture_images():
    # Initialize Picamera2
    picam2 = Picamera2()
    im.init_cam(picam2)

    while True:
        # Capture frame-by-frame
        frame = picam2.capture_array()

        # Adjust brightness and zoom
        frame = im.adjust_brightness(frame, brightness)
        frame = im.apply_zoom(frame, zoom_factor)

        # Display the frame
        cv2.imshow('Camera', frame)

        # Check for key press
        key = cv2.waitKey(1)
            
        if key == ord(KEY_TAKE_PICTURE):
            img_ctr += 1
            image_name = f'{IMAGE_FOLDER}/image_{img_ctr}.jpg'
            cv2.imwrite(image_name, frame)
            image_paths.append(image_name)
            print(f"Image captured and saved as '{image_name}'.")
        elif key == ord(KEY_QUIT):
            print("Quitting the program.")
            callback.turn_off_leds()
            break
        
    # Release resources
    cv2.destroyAllWindows()
    picam2.stop()

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
      
def turn_off_leds():
	rw.send_to_arduino(0)

def determine_best_img():
     # Determine the best quality image using both Laplacian variance and Fourier sharpness
    best_laplace_img = None
    best_fourier_img = None

    #init to 0
    best_laplacian_variance = 0
    best_fourier_sharpness = 0

    for image_path in image_paths:
        image = cv2.imread(image_path)
        laplacian_var = prep.laplacian_variance(image)
        fourier_sharp = prep.fourier_sharpness(image)
        print(f"Image: {image_path}, Laplacian Variance: {laplacian_var}, Fourier Sharpness: {fourier_sharp}")

        if laplacian_var > best_laplacian_variance:
            best_laplacian_variance = laplacian_var
            best_laplace_img = image_path

        if fourier_sharp > best_fourier_sharpness:
            best_fourier_sharpness = fourier_sharp
            best_fourier_img = image_path

    #TODO: combine metrics
    print(f"The best quality image is '{best_fourier_img}' with Laplacian Variance of {best_laplacian_variance} and Fourier Sharpness of {best_fourier_sharpness}.")
    print(f"The best quality image is '{best_laplace_img}' with Laplacian Variance of {best_laplacian_variance} and Fourier Sharpness of {best_fourier_sharpness}.")
    
    return best_fourier_img, best_laplace_img
    
#run main
main()