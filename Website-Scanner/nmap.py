import os


def get_nmap(option, ip):
    command = 'nmap ' + str(option) + ' ' + str(ip)
    process = os.popen(command)
    result = str(process.read())
    return result
