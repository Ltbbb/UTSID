import read_write as rw

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
	global pwm_values
	pwm_value= val*10
	print(f"PWM factor changed to: {pwm_value}")
	rw.send_to_arduino(pwm_value)
      
def turn_off_leds():
	rw.send_to_arduino(0)