import urllib.request
import io


def get_robots_txt(url):
    # Check for a forward-slash
    if url.endswith('/'):
        path = url
    else:
        path = url + '/'

    # Request for robots.txt
    request = urllib.request.urlopen(path + 'robots.txt', data=None)
    data = io.TextIOWrapper(request, encoding='utf-8')
    return data.read()
