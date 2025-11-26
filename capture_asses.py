import cv2
from picamera2 import Picamera2
import os
import utils.imaging as im
import utils.preprocess as prep
import utils.read_write as rw

KEY_TAKE_PICTURE = "i"
KEY_QUIT = "q"
IMAGE_FOLDER = "./img" #TODO: impl image folder

# Initial values for brightness and zoom
brightness = 0
zoom_factor = 1
pwm_val = 0

img_ctr = 0  # Counter for images
#TODO: create image folder that self-cleans each round and stored end results only?
image_paths = []  # List to store paths of captured images

def main():
    capture_images()
    best_img_f, best_img_l = determine_best_img()

    #Display the best image
    if best_img_f == best_img_l:
        im.display_img(best_img_f, "Best Image :)")
    else:
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
            global img_ctr
            img_ctr += 1
            if not os.path.exists(f"{IMAGE_FOLDER}"):
                raise Exception(f"There is no folder called '{IMAGE_FOLDER}' in the current directory!")
                #TODO: create folder for them?
            #TODO: empty image folder?
            image_name = f'{IMAGE_FOLDER}/image_{img_ctr}.jpg'
            cv2.imwrite(image_name, frame)
            image_paths.append(image_name)
            print(f"Image captured and saved as '{image_name}'.")
        elif key == ord(KEY_QUIT):
            print("Quitting the program.")
            turn_off_leds()
            break
        
    # Release resources
    cv2.destroyAllWindows()
    picam2.stop()
      
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

    #TODO: combine metrics in a better way
    print(f"Best quality fourier: '{best_fourier_img}' with value {best_fourier_sharpness}.")
    print(f"Best quality laplace: '{best_laplace_img} with value {best_laplacian_variance}.") 
    
    return best_fourier_img, best_laplace_img
    
#run main
main()