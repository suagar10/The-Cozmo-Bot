#importing the libraries
import cv2
#load cascades
face_cascade=cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade=cv2.CascadeClassifier('haarcascade_eye.xml')

font = cv2.FONT_HERSHEY_SIMPLEX

#detector function
def detect(grs, org):
    faces=face_cascade.detectMultiScale(grs, 1.3, 5)
    for (x, y, w, h) in faces:
        cv2.rectangle(org, (x,y), (x+w,y+h), (34,34,178), 2)
        roi_grs = grs[y:y+h, x:x+w]
        roi_org = org[y:y+h, x:x+w]
        eyes=eye_cascade.detectMultiScale(roi_grs, 1.1, 22)
        cv2.putText(org,'face',(x+w-32,y+h+15), font, 0.5,(255,255,255),1,cv2.LINE_AA)
        for(ex, ey, ew, eh) in eyes:
            cv2.rectangle(roi_org, (ex,ey), (ex+ew, ey+eh), (55, 175, 212), 2)
            cv2.putText(roi_org,'eyes',(ex+ew-32,ey+eh+15), font, 0.5,(255,255,255),1,cv2.LINE_AA)
    return org
video=cv2.VideoCapture(0)
while True:
    _, org=video.read()
    grs=cv2.cvtColor(org, cv2.COLOR_BGR2GRAY)
    canvas = detect(grs, org)
    cv2.imshow('Video', canvas)
    if cv2.waitKey(1) & 0xff==ord('q'):
        break
video.release()
cv2.destroyAllWindows()
