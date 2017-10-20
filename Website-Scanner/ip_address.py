import os


def get_ip_address(domain):
    command = "host " + str(domain)

    # Running the process
    process = os.popen(command)

    # Getting the IP from the output
    result = str(process.read())
    marker = result.find("has address") + 12
    return result[marker:].splitlines()[0]

