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

lowerBound=np.array([0, 1, 0.392])
upperBound=np.array([0, 0.412, 1])

videoStream = cv2.VideoCapture(2)
#tracker = cv2.TrackerCSRT_create()

while True:
    ret, img = videoStream.read()
    im2 = img #cv2.cvtColor(img, cv2.COLOR_RGB2HSV)
    b_mask = cv2.inRange(src=im2, lowerb=np.array([0, 0, 100]), upperb=np.array([100, 100, 255]))
    red = cv2.bitwise_and(im2, im2, mask=b_mask)

    m2 = cv2.inRange(src=red, lowerb=np.array([0, 0, 100]), upperb=np.array([100, 100, 255]))
    cv2.imshow("Red Detector", red)
    cv2.imshow("mask", m2)
    cv2.imshow("Original", im2)
    if cv2.waitKey(1) == 27:
        break

videoStream.release()
cv2.destroyAllWindows()
