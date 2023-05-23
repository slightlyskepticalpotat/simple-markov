import logging
import secrets
import sys

logging.basicConfig(level = logging.DEBUG, filename = "/home/chenanthony365/chenanthony-markov/application.log")
sys.path.insert(0,"/home/chenanthony365/chenanthony-markov/")

from app import app as application
