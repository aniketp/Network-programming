from domain import get_domain_name
from general import create_directory, write_file
from ip_address import get_ip_address
from nmap import get_nmap
from robots_txt import get_robots_txt
from whois import get_whois
from website import websites


# Create a Root Directory to store all the results
# Not to mess up with the source code
ROOT_DIRS = 'websites'
create_directory(ROOT_DIRS)


def gather_info(name, url):
    print("Scanning " + url + '\n')

    print("Getting Domain Name...")
    domain_name = get_domain_name(url)
    print("Done\n")

    print("Getting the IP Address...")
    ip_address = get_ip_address(domain_name)
    print("Done\n")

    print("Running Nmap Scan...")
    nmap = get_nmap('-F', ip_address)
    print("Done\n")

    print("Fetching robots.txt...")
    robots_txt = get_robots_txt(url)
    print("Done\n")

    print("Extracting whois details...")
    whois = get_whois(domain_name)
    print("Done\n")

    # Create Final Report in a file
    create_report(name, url, domain_name, nmap, robots_txt, whois)
    print("Information for " + name + " saved in Websites/" + name + " Folder\n")


def create_report(name, full_url, domain_name, nmap, robots_txt, whois):
    project_dir = ROOT_DIRS + '/' + name
    create_directory(project_dir)
    write_file(project_dir + '/full-url.txt', full_url)
    write_file(project_dir + '/domain-name.txt', domain_name)
    write_file(project_dir + '/nmap.txt', nmap)
    write_file(project_dir + '/robots-txt.txt', robots_txt)
    write_file(project_dir + '/whois.txt', whois)


# print("Enter the name of project")
# name = input()
# print("\nEnter the full URL")
# url = input()

# gather_info(name, url)

for web in websites:
    gather_info(web[0], web[1])
