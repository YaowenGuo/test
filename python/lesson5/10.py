def importAs(modul_name):
    return __import__(modul_name)


rInt = importAs("random")

print rInt.randint(1,99)