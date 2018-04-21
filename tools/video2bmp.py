# -*- coding: utf-8 -*-  

import cv2  
import os


source_path = '/home/cv/workspace/Tracker/Quadcopter/'
dest_paths = ['./images/IMG_2345', './images/IMG_2348']
files = ['IMG_2345.mp4', 'IMG_2348.mp4']


def vide2bmp(filename, dest_path):
    cap = cv2.VideoCapture(filename)  
    ret, frame = cap.read() 
    index = 1
    while(ret):
        ret, frame = cap.read()
        print(ret)
        save_filename = os.path.join(dest_path, "%d.bmp" % index)
        print(save_filename)
        cv2.imwrite(save_filename, frame)
        index = index + 1

    print("Finished %s" % filename)

if __name__ == "__main__":
    for index, file in enumerate(files):
        filename = os.path.join(source_path, file)
        vide2bmp(filename, dest_paths[index])
