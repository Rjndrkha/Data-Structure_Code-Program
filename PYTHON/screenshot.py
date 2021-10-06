import pyscreenshot as ImageGrab
import os

dirname = os.path.dirname(__file__)
#change this if you are using windows



def take_full_screenshot():
	# fullscreen
	im=ImageGrab.grab()
	im.show()
	return True
	
def take_screenshot_to_file():
	# to file
	ImageGrab.grab_to_file('im.png')
	im.show()
	return True

def take_part_screenshot():
	# part of the screen
	im=ImageGrab.grab(bbox=(10,10,500,500))
	im.show()
	return True
	
 
