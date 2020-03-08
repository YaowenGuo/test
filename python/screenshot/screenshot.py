from selenium import webdriver
import time
from random import randint

links = ['http://3.230.161.38/Inbox_31364049-1', 'http://3.230.161.38/Inbox_2227898-3', 'http://3.230.161.38/Junk_30379138-2']


with webdriver.Chrome("/usr/local/bin/chromedriver") as driver:
    for link in links:
        mobile = {'output': str(link) + '-mobile.png', 'width': 500, 'height': 900}
        driver.set_window_size(mobile['width'], mobile['height']) # takes two arguments, width and height of the browser and it has to be called before using get()
        driver.get(link) # takes one argument, which is the url of the website you want to open
        driver.save_screenshot(str(randint(1, 100000000000)) + '.png') # this 

