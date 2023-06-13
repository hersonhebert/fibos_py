import respak75
import os
import shutil

def respak(file):
    if not(os.path.exists(file)):
        print("Prot File not found!")
    else:
        if(file!="prot.srf"):
            shutil.copy(file,"prot.srf")
        respak75.respak()
        if(file!="prot.srf"):
            os.remove("prot.srf")
    