try:
    from googlesearch import search
except ImportError:
    print("unable to import file !")

query = "research papers on self Attention"

for results in search(query, tld="co.in", num=10, stop=10, pause=2):
    print(results)