from picamera2 import Picamera2
import cv2
import os
import utils.capture_framework as cf
import utils.preprocess as prep

IMAGE_FOLDER = "img"
img_ctr = 0

#TODO: create image folder that self-cleans each round and stored end results only?
image_paths = []  # List to store paths of captured images

def main():
    picam2 = Picamera2()
    cf.init_cam(picam2)
    cf.capture_images(picam2, capture_multiple)
    best_img_f, best_img_l = determine_best_img()

    #Display the best image
    if best_img_f == best_img_l:
        cf.display_img(best_img_f, "Best Image :)")
    else:
        cf.display_img(best_img_l, "Best Image Laplace")
        cf.display_img(best_img_f, "Best Image Fourier")

def capture_multiple(frame):
    # Check for key press
    key = cv2.waitKey(1)
        
    if key == ord(cf.KEY_TAKE_PICTURE):
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
    elif key == ord(cf.KEY_QUIT):
        cf.turn_off_leds()
        raise Exception("Closing capture!") #FIXME: is there a better way to do this?

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
