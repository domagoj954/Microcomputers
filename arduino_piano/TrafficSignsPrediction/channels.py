import cv2
import numpy as np

img = cv2.imread("pic1.png")

img_np = np.asarray(img)

print("img_np.shape: ", img_np.shape)

#depth
#channels
