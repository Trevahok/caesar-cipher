import time
t=lambda: str(int(round(time.time()*1000)))


plain=list(raw_input('enter the plain text:'))
plain=[ord(x) for x in plain]
key=list(t()*len(plain))[:len(plain)]
key=[int(x) for x in key]
plain=[y+x for x,y in zip(plain,key)]



