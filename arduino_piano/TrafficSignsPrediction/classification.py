import tkinter as tk
from tkinter import filedialog
from tkinter import *
from PIL import ImageTk, Image
import numpy as np
# load the trained model to classify sign
from keras.models import load_model
import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

model = load_model('newModel.h5')
# dictionary to label all traffic signs class.
classes = {0: 'Speed limit (20km/h)',
           1: 'Speed limit (30km/h)',
           2: 'Speed limit (50km/h)',
           3: 'Speed limit (60km/h)',
           4: 'Speed limit (70km/h)',
           5: 'Speed limit (80km/h)',
           6: 'End of speed limit (80km/h)',
           7: 'Speed limit (100km/h)',
           8: 'Speed limit (120km/h)',
           9: 'No passing',
           10: 'No passing veh over 3.5 tons',
           11: 'Right-of-way at intersection',
           12: 'Priority road',
           13: 'Yield',
           14: 'Stop',
           15: 'No vehicles',
           16: 'Veh > 3.5 tons prohibited',
           17: 'No entry',
           18: 'General caution',
           19: 'Dangerous curve left',
           20: 'Dangerous curve right',
           21: 'Double curve',
           22: 'Bumpy road',
           23: 'Slippery road',
           24: 'Road narrows on the right',
           25: 'Road work',
           26: 'Traffic signals',
           27: 'Pedestrians',
           28: 'Children crossing',
           39: 'Bicycles crossing',
           30: 'Beware of ice/snow',
           31: 'Wild animals crossing',
           32: 'End speed + passing limits',
           33: 'Turn right ahead',
           34: 'Turn left ahead',
           35: 'Ahead only',
           36: 'Go straight or right',
           37: 'Go straight or left',
           38: 'Keep right',
           39: 'Keep left',
           40: 'Roundabout mandatory',
           41: 'End of no passing',
           42: 'End no passing vehicle with a weight greater than 3.5 tons'}
# initialise GUI
top = tk.Tk()
top.geometry('800x600')
top.title('Traffic sign classification')
top.configure(background='#CDCDCD')
label = Label(top, background='#CDCDCD', font=('arial', 15, 'bold'))
sign_image = Label(top)


def classify(file_path):
    global label_packed
    image = Image.open(file_path)
    image = image.resize((30, 30))
    image = np.expand_dims(image, axis=0)
    image = np.array(image)
    pred = model.predict([image])[0]
    sign = np.argmax(pred, axis=-1)
    print(sign)

    if (sign == 0):
        sign_name = 'Speed limit (20km/h)'
        print(sign_name)

    elif (sign == 1):
        sign_name = 'Speed limit (30km/h)'
        print(sign_name)

    elif (sign == 2):
        sign_name = 'Speed limit (50km/h)'
        print(sign_name)

    elif (sign == 3):
        sign_name = 'Speed limit (60km/h)'
        print(sign_name)

    elif (sign == 4):
        sign_name = 'Speed limit (70km/h)'
        print(sign_name)

    elif (sign == 5):
        sign_name = 'Speed limit (80km/h)'
        print(sign_name)

    elif (sign == 6):
        sign_name = 'End of speed limit (80km/h)'
        print(sign_name)

    elif (sign == 7):
        sign_name = 'Speed limit (100km/h)'
        print(sign_name)

    elif (sign == 8):
        sign_name = 'Speed limit (120km/h)'
        print(sign_name)

    elif (sign == 9):
        sign_name = 'No passing'
        print(sign_name)

    elif (sign == 10):
        sign_name = 'No passing veh over 3.5 tons'
        print(sign_name)

    elif (sign == 11):
        sign_name = 'Right-of-way at intersection'
        print(sign_name)

    elif (sign == 12):
        sign_name = 'Priority road'
        print(sign_name)

    elif (sign == 13):
        sign_name = 'Yield'
        print(sign_name)

    elif (sign == 14):
        sign_name = 'Stop'
        print(sign_name)

    elif (sign == 15):
        sign_name = 'No vehicles'
        print(sign_name)

    elif (sign == 16):
        sign_name = 'Veh > 3.5 tons prohibited'
        print(sign_name)

    elif (sign == 17):
        sign_name = 'No entry'
        print(sign_name)

    elif (sign == 18):
        sign_name = 'General caution'
        print(sign_name)

    elif (sign == 19):
        sign_name = 'Dangerous curve left'
        print(sign_name)

    elif (sign == 20):
        sign_name = 'Dangerous curve right'
        print(sign_name)

    elif (sign == 21):
        sign_name = 'Double curve'
        print(sign_name)

    elif (sign == 22):
        sign_name = 'Bumpy road'
        print(sign_name)

    elif (sign == 23):
        sign_name = 'Slippery road'
        print(sign_name)

    elif (sign == 24):
        sign_name = 'Road narrows on the right'
        print(sign_name)

    elif (sign == 25):
        sign_name = 'Road work'
        print(sign_name)

    elif (sign == 26):
        sign_name = 'Traffic signals'
        print(sign_name)

    elif (sign == 27):
        sign_name = 'Pedestrians'
        print(sign_name)

    elif (sign == 28):
        sign_name = 'Children crossing'
        print(sign_name)

    elif (sign == 29):
        sign_name = 'Bicycles crossing'
        print(sign_name)

    elif (sign == 30):
        sign_name = 'Beware of ice/snow'
        print(sign_name)

    elif (sign == 31):
        sign_name = 'Wild animals crossing'
        print(sign_name)

    elif (sign == 32):
        sign_name = 'End speed + passing limits'
        print(sign_name)

    elif (sign == 33):
        sign_name = 'Turn right ahead'
        print(sign_name)

    elif (sign == 34):
        sign_name = 'Turn left ahead'
        print(sign_name)

    elif (sign == 35):
        sign_name = 'Ahead only'
        print(sign_name)

    elif (sign == 36):
        sign_name = 'Go straight or right'
        print(sign_name)

    elif (sign == 37):
        sign_name = 'Go straight or left'
        print(sign_name)

    elif (sign == 38):
        sign_name = 'Keep right'
        print(sign_name)

    elif (sign == 39):
        sign_name = 'Keep left'
        print(sign_name)

    elif (sign == 40):
        sign_name = 'Roundabout mandatory'
        print(sign_name)

    elif (sign == 41):
        sign_name = 'End of no passing'
        print(sign_name)

    elif (sign == 42):
        sign_name = 'End no passing vehicle with a weight greater than 3.5 tons'
        print(sign_name)



    label.configure(foreground='#011638', text=sign_name)




def show_classify_button(file_path):
    classify_b = Button(top, text="Classify Image", command=lambda: classify(file_path), padx=10, pady=5)
    classify_b.configure(background='#364156', foreground='white', font=('arial', 10, 'bold'))
    classify_b.place(relx=0.79, rely=0.46)


def upload_image():
    try:
        file_path = filedialog.askopenfilename()
        uploaded = Image.open(file_path)
        uploaded.thumbnail(((top.winfo_width() / 2.25), (top.winfo_height() / 2.25)))
        im = ImageTk.PhotoImage(uploaded)
        sign_image.configure(image=im)
        sign_image.image = im
        label.configure(text='')
        show_classify_button(file_path)
    except:
        pass


upload = Button(top, text="Upload an image", command=upload_image, padx=10, pady=5)
upload.configure(background='#364156', foreground='white', font=('arial', 10, 'bold'))
upload.pack(side=BOTTOM, pady=50)
sign_image.pack(side=BOTTOM, expand=True)
label.pack(side=BOTTOM, expand=True)
heading = Label(top, text="check traffic sign", pady=20, font=('arial', 20, 'bold'))
heading.configure(background='#CDCDCD', foreground='#364156')
heading.pack()
top.mainloop()
