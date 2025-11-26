import cv2
import time
import numpy as np
from picamera2 import Picamera2

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

# Function to calculate the Laplacian variance of an image
def laplacian_variance(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    laplacian = cv2.Laplacian(gray, cv2.CV_64F)
    variance = laplacian.var()
    return variance

# Function to calculate the sum of the magnitude spectrum from the Fourier Transform
def fourier_sharpness(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    dft = cv2.dft(np.float32(gray), flags=cv2.DFT_COMPLEX_OUTPUT)
    dft_shift = np.fft.fftshift(dft)
    magnitude_spectrum = cv2.magnitude(dft_shift[:, :, 0], dft_shift[:, :, 1])
    sharpness = np.sum(magnitude_spectrum)
    return sharpness

# Initialize Picamera2
picam2 = Picamera2()
config = picam2.create_still_configuration()  # Use still configuration
picam2.configure(config)
picam2.start()

# Give some time to the camera to start
time.sleep(2)

# Initial values for brightness and zoom
brightness = 0
zoom_factor = 1.0
image_counter = 0  # Counter for images
image_paths = []  # List to store paths of captured images

cv2.namedWindow('Camera')

# Callback functions for trackbars
def on_brightness_change(val):
    global brightness
    brightness = val - 50
    print(f"Brightness changed to: {brightness}")

def on_zoom_change(val):
    global zoom_factor
    zoom_factor = 1 + val / 10
    print(f"Zoom factor changed to: {zoom_factor}")

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
    if key == ord('i'):
        image_counter += 1
        image_name = f'image_{image_counter}.jpg'
        cv2.imwrite(image_name, frame)
        image_paths.append(image_name)
        print(f"Image captured and saved as '{image_name}'.")
    elif key == ord('q'):
        print("Quitting the program.")
        break

# Release resources
cv2.destroyAllWindows()
picam2.stop()

# Determine the best quality image using both Laplacian variance and Fourier sharpness
best_image_l = None
best_image_f = None
best_laplacian_variance = 0
best_fourier_sharpness = 0

for image_path in image_paths:
    image = cv2.imread(image_path)
    laplacian_var = laplacian_variance(image)
    fourier_sharp = fourier_sharpness(image)
    print(f"Image: {image_path}, Laplacian Variance: {laplacian_var}, Fourier Sharpness: {fourier_sharp}")

    if laplacian_var > best_laplacian_variance:
        best_laplacian_variance = laplacian_var
        best_image_l = image_path

    if fourier_sharp > best_fourier_sharpness:
        best_fourier_sharpness = fourier_sharp
        best_image_f = image_path

print(f"The best quality image is '{best_image_l}' with Laplacian Variance of {best_laplacian_variance} and Fourier Sharpness of {best_fourier_sharpness}.")
print(f"The best quality image is '{best_image_f}' with Laplacian Variance of {best_laplacian_variance} and Fourier Sharpness of {best_fourier_sharpness}.")
# Optionally display the best image
if best_image_l is not None:
    if best_image_f is not None:
        best_img = cv2.imread(best_image_l)
        cv2.imshow('Best Image Laplace', best_img)
        best_img2 = cv2.imread(best_image_f)
        cv2.imshow('Best Image Fourier', best_img2)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    
#if best_image_f is not None:
    #best_img2 = cv2.imread(best_image_f)
    #cv2.imshow('Best Image Fourier', best_img2)
    #cv2.waitKey(0)
    #cv2.destroyAllWindows()
