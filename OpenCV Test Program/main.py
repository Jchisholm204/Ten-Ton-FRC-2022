import cv2
import sys

tracker = cv2.TrackerCSRT_create()
videoStream = cv2.VideoCapture(0)

if not videoStream.isOpened():
    print("Could not open Video Stream")
    sys.exit()

kk, frame = videoStream.read()

if not kk:
    print("Cannot read video file")
    sys.exit()

boundingBox = (287, 23, 86, 320)

boundingBox = cv2.selectROI(img=frame)

ok = tracker.init(frame, boundingBox)

while True:
     # Read a new frame
     ok, frame = videoStream.read()
     if not ok:
         break
      
     # Start timer
     timer = cv2.getTickCount()

     # Update tracker
     ok, bbox = tracker.update(frame)

     # Calculate Frames per second (FPS)
     fps = cv2.getTickFrequency() / (cv2.getTickCount() - timer)

     # Draw bounding box
     if ok:
         # Tracking success
         p1 = (int(bbox[0]), int(bbox[1]))
         p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
         cv2.rectangle(frame, p1, p2, (255,0,0), 2, 1)
     else :
         # Tracking failure
         cv2.putText(frame, "Tracking failure detected", (100,80), cv2.FONT_HERSHEY_SIMPLEX, 0.75,(0,0,255),2)

  
     # Display FPS on frame
     cv2.putText(frame, "FPS : " + str(int(fps)), (100,50), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50), 2)
     # Display result
     cv2.imshow("Tracking", frame)

     # Exit if ESC pressed
     if cv2.waitKey(1) & 0xFF == ord('q'): # if press SPACE bar
         break

videoStream.release()
cv2.destroyAllWindows()