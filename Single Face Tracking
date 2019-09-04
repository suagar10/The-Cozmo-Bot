import serial
import cv2

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
font = cv2.FONT_HERSHEY_SIMPLEX

center=(0,0)

def detectCoordinates(grs, org):
    centre_pt=()
    faces=face_cascade.detectMultiScale(grs, 1.3, 5)
    for(x, y, h, w) in faces:
        cv2.rectangle(org, (x,y), (x+h,y+h), (34, 34, 178), 2)
        centre_pt=(x+w/2, y+h/2)
    return centre_pt
def detect(grs, org):
    faces=face_cascade.detectMultiScale(grs, 1.3, 5)
    for (x, y, w, h) in faces:
        cv2.circle(org,(320,240), 50, (0,255,0), 1)
        cv2.rectangle(org, (x,y), (x+w,y+h), (34,34,178), 2)
        cv2.putText(org,'face', (x+w-32,y+h+15), font, 0.5, (255,255,255), 1, cv2.LINE_AA)
    return org

video = cv2.VideoCapture(0)

while True:
    _,org = video.read()
    grs = cv2.cvtColor(org, cv2.COLOR_BGR2GRAY)
    center = detectCoordinates(grs, org)
    canvas = detect(grs,org)
    cv2.imshow('Video', canvas)
    if center:
        xx = center[0]
        yy = center[1]
        feild_of_vision = xx**2 + yy**2 - 640*xx - 480*yy + 157500
        if(xx>320 and feild_of_vision>0):
            print('Move head towards Right')
            #print(feild_of_vision)
        if(xx<320 and feild_of_vision>0):
            print('Move head towards Left')
            #print(feild_of_vision)
        if(yy<240 and feild_of_vision>0):
            print('Move head Upwards')
            #print(feild_of_vision)
        if(yy>240 and feild_of_vision>0):
            print('Move head Downwards')
            #print(feild_of_vision)
    if cv2.waitKey(1) & 0xff==ord('q'):
        break
    
video.release()
cv2.destroyAllWindows()
