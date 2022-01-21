from turtle import color
import cv2
import numpy as np
import colorsys

def rgbtohsv(r, g, b):
    h, s, v = colorsys.rgb_to_hsv(r, g, b)
    #h, s, v = h*100, s*100, v*100
    return [h, s, v]

[0, 29.4, 100]
[0, 100, 39.2]

lowerBound=np.array([20, 0, 0])
upperBound=np.array([255, 100, 100])

videoStream = cv2.VideoCapture(0)
#tracker = cv2.TrackerCSRT_create()

while True:
    ret, img = videoStream.read()
    #imgRGB = cv2.cvtColor(img, cv2.COLOR_RGB2HSV)
    b_mask = cv2.inRange(src=img, lowerb=lowerBound, upperb=upperBound)
    red = cv2.bitwise_and(img, img, mask=b_mask)
    cv2.imshow("Red Detector", red)
    cv2.imshow("mask", b_mask)
    cv2.imshow("Original", img)
    if cv2.waitKey(1) == 27:
        break

videoStream.release()
cv2.destroyAllWindows()
