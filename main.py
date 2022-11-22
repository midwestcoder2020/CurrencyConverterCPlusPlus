import re
import sys

def getRate(c):
    from urllib.request import urlopen
    with urlopen("https://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml?") as response:
        data = response.read().decode()
    # data = requests.get("https://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml?").text
    data = re.findall(r"<Cube currency.*.>",data)
    # c = "USD"
    for d in data:
        if c in d:
            print(d.split("' ")[1].replace("rate='","").replace("'/>",""))

if __name__ == '__main__':
    args = sys.argv

    if len(args)>1:
        getRate(args[1])
