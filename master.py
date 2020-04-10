import speech_recognition as sr
import serial
from time import sleep
from pygame import mixer
ser=serial.Serial('/dev/ttyACM0', 9600)
r = sr.Recognizer()
x=1
while x==1:
    with sr.Microphone() as source:
        print("Say something!")
        audio = r.listen(source)
    try:
        response = r.recognize_google(audio)
        text=str(response)
        if 'hello' in text:
            ser.write(b'10')
            import SingleFaceTracking
            tracking_op=SingleFaceTracking.track()
            while (tracking_op<='o'):
                ser.write(tracking_op)
        elif 'forward' in text:
            ser.write(b'5')
        elif 'backward' in text:
            ser.write(b'6')
        elif 'left' in text:
            ser.write(b'7')
        elif 'right' in text:
            ser.write(b'8')
        elif 'hand' in text:
            if 'left' in text:
                ser.write(b'1')
            else:
                ser.write(b'2')
        elif 'nod' in text:
            ser.write(b'4')
        elif 'pan' in text:
            ser.write(b'3')
        sleep(5)
        if stop in text:
            x=2
    except sr.UnknownValueError:
        print("Sphinx could not understand audio")
  
    except sr.RequestError as e:
        print("Sphinx error; {0}".format(e))