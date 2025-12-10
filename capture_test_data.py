import cv2
from picamera2 import Picamera2
import time
import utils.capture_framework as cf

KEY_NEXT_FINGER = "j"
KEY_PREV_FINGER = "l"
IMAGE_FOLDER = "img" 
img_ctr = 0

FINGER_IDX = 0
FINGER = ["Right Index", "Right Middle", "Right Ring", "Left Index", "Left Middle", "Left Ring"]
IMG_PATHS_CONTAINER = [[],[],[],[],[],[]] #NOTE! has to contain the same amt of listed lists as len(FINGER)

def main():
    picam2 = Picamera2()
    cf.init_cam(picam2)
    cf.capture_images(picam2, capture_test_data)
    # best_img_f, best_img_l = determine_best_img()

    # #Display the best image
    # if best_img_f == best_img_l:
    #     display_img(best_img_f, "Best Image :)")
    # else:
    #     display_img(best_img_l, "Best Image Laplace")
    #     display_img(best_img_f, "Best Image Fourier")

def capture_test_data(frame):
    global FINGER_IDX

    current_finger_name = FINGER[FINGER_IDX]
    current_finger_array = IMG_PATHS_CONTAINER[FINGER_IDX]

    cf.display_on_frame(f"Taking pictures of: {current_finger_name}finger")

    key = cv2.waitKey(1)    

    if key == ord(cf.KEY_TAKE_PICTURE):
        img_ctr = len(current_finger_array) + 1
        image_name = f'{IMAGE_FOLDER}/{current_finger_name}_{img_ctr}.jpg'
        cv2.imwrite(image_name, frame)
        current_finger_array.append(image_name)
        cf.display_on_frame(f"Image captured and saved as '{image_name}'.")
        time.sleep(1) #TODO: delay to see img captured
    elif key == ord(KEY_NEXT_FINGER):
        if not FINGER_IDX >= len(FINGER) - 1:
            FINGER_IDX += 1
    elif key == ord(KEY_PREV_FINGER):
        if not FINGER_IDX == 0:
            FINGER_IDX -= 1
    elif key == ord(cf.KEY_QUIT):
        cf.turn_off_leds()
        raise Exception("Closing capture!")

#run main
main()

