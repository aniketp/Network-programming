import os


def get_whois(url):
    command = 'whois ' + str(url)
    process = os.popen(command)
    result = str(process.read())
    return result
