import smbus
import time
import struct


ARDUINO_I2C_ADDRESS = 0x08
ARDUINO_I2C_ADDRESS2= 0x09
NUM_CHANNELS = 8
# Define the struct format for sending and receiving data
# '4B' for 4 uint8_t values followed by '4H' for 4 uint16_t values
# '<' indicates little-endian byte order
STRUCT_FORMAT = '<' + 'B' * NUM_CHANNELS + 'H' * NUM_CHANNELS

# Function to write data to Arduino
def write_data(data,addr):
    print("ovde sam")
    try:
        bus = smbus.SMBus(1)
        print("ovde sam 2")
        bus.write_i2c_block_data(addr, 0, list(data))
        print("ovde sam 3")
        time.sleep(0.2)  # Sleep to allow Arduino to process the data
        return True
    except Exception as e:
        print(f"Error writing data to Arduino: {e}")
        return False
    
# Function to read data from Arduino
def read_data(addr):
    try:
        bus = smbus.SMBus(1)
        data = bus.read_i2c_block_data(addr, 0, struct.calcsize(STRUCT_FORMAT))
        return struct.unpack(STRUCT_FORMAT, bytes(data))
    except Exception as e:
        print(f"Error reading data from Arduino: {e}")
        return None
    
#send the pwm values and channels
# Prepare data to send
def send_to_arduino(pwm):
	channels = [i  for i in range(NUM_CHANNELS)]  # Example channel values
	#8led cnfiguration
	#pwm_values = [pwm] * NUM_CHANNELS  # Example PWM values
	#4led cnfiguration - every second led on
	pwm_values = [pwm,0,pwm,0,pwm,0,pwm,0]
	pwm_bytes=[pwm.to_bytes(2, byteorder='little') for pwm in pwm_values]
	data_to_send = bytes(channels) + b''.join(pwm_bytes)
	#data_to_send=channels+pwm_bytes
	print("data to send: ", list(data_to_send))
	# Write data to Arduino
	if write_data(data_to_send,ARDUINO_I2C_ADDRESS):
		print("Data sent successfully.")

		# Read back data from Arduino
		received_data = read_data(ARDUINO_I2C_ADDRESS)
		if received_data:
			print("Received data from Arduino pcb:")
			print("Channels:", received_data[:NUM_CHANNELS])
			print("PWM Values:", received_data[NUM_CHANNELS:])
	if write_data(data_to_send,ARDUINO_I2C_ADDRESS2):
		print("Data sent successfully.")

		# Read back data from Arduino
		received_data = read_data(ARDUINO_I2C_ADDRESS2)
		if received_data:
			print("Received data from Arduino on board:")
			print("Channels:", received_data[:NUM_CHANNELS])
			print("PWM Values:", received_data[NUM_CHANNELS:])
	else:
		print("Failed to send data2.")