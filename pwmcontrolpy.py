import smbus
import time
import struct

ARDUINO_I2C_ADDRESS = 0x08
NUM_CHANNELS = 4

# Define the struct format for sending and receiving data
# '4B' for 4 uint8_t values followed by '4H' for 4 uint16_t values
# '<' indicates little-endian byte order
STRUCT_FORMAT = '<' + 'B' * NUM_CHANNELS + 'H' * NUM_CHANNELS

# Function to write data to Arduino
def write_data(data):
    try:
        bus = smbus.SMBus(1)
        bus.write_i2c_block_data(ARDUINO_I2C_ADDRESS, 0, list(data))
        time.sleep(0.2)  # Sleep to allow Arduino to process the data
        return True
    except Exception as e:
        print(f"Error writing data to Arduino: {e}")
        return False

# Function to read data from Arduino
def read_data():
    try:
        bus = smbus.SMBus(1)
        data = bus.read_i2c_block_data(ARDUINO_I2C_ADDRESS, 0, struct.calcsize(STRUCT_FORMAT))
        return struct.unpack(STRUCT_FORMAT, bytes(data))
    except Exception as e:
        print(f"Error reading data from Arduino: {e}")
        return None

# Main function
def main():
    # Prepare data to send
    channels = [i + 1 for i in range(NUM_CHANNELS)]  # Example channel values
    pwm_values = [1500 + i for i in range(NUM_CHANNELS)]  # Example PWM values
    pwm_bytes=[pwm.to_bytes(2, byteorder='little') for pwm in pwm_values]
    data_to_send = bytes(channels) + b''.join(pwm_bytes)
    #data_to_send=channels+pwm_bytes
    print("data to send: ", list(data_to_send))

    # Write data to Arduino
    if write_data(data_to_send):
        print("Data sent successfully.")

        # Read back data from Arduino
        received_data = read_data()
        if received_data:
            print("Received data from Arduino:")
            print("Channels:", received_data[:NUM_CHANNELS])
            print("PWM Values:", received_data[NUM_CHANNELS:])
    else:
        print("Failed to send data.")

if __name__ == "__main__":
    main()
