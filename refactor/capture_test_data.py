import cv2
from picamera2 import Picamera2
import time
import imaging as im
import slider_callbacks as callback

# Initial values for brightness and zoom
brightness = 0
zoom_factor = 0
img_ctr = 0

KEY_TAKE_PICTURE = "i"
KEY_QUIT = "q"
KEY_NEXT_FINGER = "j"
KEY_PREV_FINGER = "l"
IMAGE_FOLDER = "img" #TODO: impl image folder

def capture_images_test_data():
    # Initialize Picamera2
    picam2 = Picamera2()
    im.init_cam(picam2)

    FINGER_IDX = 0
    FINGER = ["Right Index", "Right Middle", "Right Ring", "Left Index", "Left Middle", "Left Ring"]
    IMG_PATHS_CONTAINER = [[],[],[],[],[],[]] #has to contain the same amt of listed lists as len(FINGER)

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

        current_finger_name = FINGER[FINGER_IDX]
        current_finger_array = IMG_PATHS_CONTAINER[FINGER_IDX]

        display_on_frame(f"Taking pictures of: {current_finger_name}finger")
            
        if key == ord(KEY_TAKE_PICTURE):
            img_ctr = len(current_finger_array) + 1
            image_name = f'{IMAGE_FOLDER}/{current_finger_name}_{img_ctr}.jpg'
            cv2.imwrite(image_name, frame)
            current_finger_array.append(image_name)
            display_on_frame(f"Image captured and saved as '{image_name}'.")
            time.wait(1) #TODO: delay to see img captured
        elif key == ord(KEY_NEXT_FINGER):
            if not FINGER_IDX >= len(FINGER) - 1:
                FINGER_IDX += 1
        elif key == ord(KEY_PREV_FINGER):
            if not FINGER_IDX == 0:
                FINGER_IDX -= 1
        elif key == ord(KEY_QUIT):
            print("Quitting the program.")
            callback.turn_off_leds()
            break
        
    # Release resources
    cv2.destroyAllWindows()
    picam2.stop()

def display_on_frame(msg: str):
    print(msg) #TODO: draw on frame