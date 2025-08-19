from keras.models import load_model  # TensorFlow is required for Keras to work
import cv2  # Install opencv-python
import numpy as np
import os
from cvzone.SerialModule import SerialObject
import time
#arduino declaration

arduino = SerialObject('COM3')

# Disable scientific notation for clarity
np.set_printoptions(suppress=True)

# Load the model
model = load_model("C:\\Users\\ranja\\Desktop\\classification\\keras_model.h5", compile=False)

# Load the labels
class_names = open("c:\\Users\\ranja\\Desktop\\classification\\labels.txt", "r").readlines()


while True:
    
    all_files = os.listdir(r'C:\\Users\\ranja\\Desktop\\Pics')
    

    img_path = r'C:\\Users\\ranja\\Desktop\\Pics'+all_files[-1]
    
    print(img_path)
    image = cv2.imread(img_path)

    # Resize the raw image into (224-height,224-width) pixels
    # image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)

    # Show the image in a window
    # cv2.imshow("Image", image)

    # Make the image a numpy array and reshape it to the models input shape.
    # image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)

    # Normalize the image array
    # image = (image / 127.5) - 1

    # Predicts the model
    prediction = model.predict(image)
    index = np.argmax(prediction)
    class_name = class_names[index]
    confidence_score = prediction[0][index]
    if class_name[2:] == 'elephant':
        arduino.sendData([0])
    else:
        arduino.sendData([1])
    # Print prediction and confidence score
    print("Class:", class_name[2:], end="")
    print("Confidence Score:", str(np.round(confidence_score * 100))[:-2], "%")
    time.sleep(1)
    # Listen to the keyboard for presses.
    keyboard_input = cv2.waitKey(1)
    # 27 is the ASCII for the esc key on your keyboard.
    if keyboard_input == 27:
        break
    

# camera.release()
cv2.destroyAllWindows()
