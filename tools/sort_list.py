"""
    Usage:
    python3 tools/sort_list.py --dir=images/IMG_2345 -fn images/IMG_2345.txt
"""

import os
import argparse as ap


filelist = []
namelist = []

def rename(path, source):
    for filename in os.listdir(path):
        number = filename.split('.')[0]
        namelist.append(int(number))
        
    namelist.sort()
    for name in namelist:
        file_ext = '%d.bmp' % name
        file = os.path.join(source, file_ext)
        filelist.append(file)

    return filelist


if __name__ == '__main__':
    parser = ap.ArgumentParser()
    parser.add_argument('-dir', '--dir', help="",
                default='')
    parser.add_argument('-path', '--path', help="",
                default='/home/cv/workspace/Tracker/KCFcpp/images/IMG_2345/')
    parser.add_argument('-fn', '--filename', help="",
                default='images.txt')
    args = vars(parser.parse_args())

    filenames = rename(args['dir'], args['path'])

    with open(args['filename'], 'w') as fp:
        for line in filenames:
            fp.write(line + '\n')
