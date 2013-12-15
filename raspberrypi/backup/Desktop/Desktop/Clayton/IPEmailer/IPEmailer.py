# Clayton Salinger Ketner - October 21, 2013
# Sends an email each time the IP address changes
# Email: CSCI445.team13.rpi@gmail.com
# Pass: CS445t13

import subprocess # For executing terminal commands
import smtplib # For connecting to the email server
import string


# This is the shell command to get the current IP address
ip_cmd = "/sbin/ifconfig wlan0 | grep 'inet addr:' | cut -d: -f2 | awk '{ print $1}' > ~/Desktop/Clayton/IPEmailer/current_ip.txt"

# Read in what the IP address used to be from the text file
currentIPFile = file('current_ip.txt', 'r')
fileIP = currentIPFile.next()
currentIPFile.close()

# Write the current IP to it using the shell command
subprocess.call(ip_cmd, shell=True)
currentIPFile = file('current_ip.txt', 'r')
currentIP = currentIPFile.next();
currentIPFile.close()

# Check if they're the same
if (fileIP != currentIP):
	MESSAGE = 'The new IP is ' + currentIP
	SUBJECT = 'CSCI 445 Raspberry Pi IP address'
	TO = 'cketner@usc.edu'
	FROM = 'CSCI445.team13.rpi@gmail.com'
	server = smtplib.SMTP('smtp.gmail.com', 587)
	server.starttls()
	server.login("CSCI445.team13.rpi@gmail.com", "CS445t13")
	server.sendmail(FROM, [TO], MESSAGE)
	server.quit()
