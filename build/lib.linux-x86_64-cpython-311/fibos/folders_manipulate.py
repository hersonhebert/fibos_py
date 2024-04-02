import os
import shutil
def create_folder(pdb):
    if ((os.path.exists("fibos_files") == False) and (os.path.basename(os.getcwd())!= "fibos_files")):
        os.mkdir("fibos_files")
        if pdb.endswith(".pdb"):
            shutil.copy(pdb,"fibos_files")
        os.chdir("fibos_files")
    elif((os.path.basename(os.getcwd())!= "fibos_files")):
        if pdb.endswith(".pdb"):
            shutil.copy(pdb,"fibos_files")
        os.chdir("fibos_files")

def rename_file(pdb_name):
    if(os.path.exists("prot.srf")):
        if(".pdb" in pdb_name):
            pdb_name = pdb_name.replace(".pdb","")
        name_prot = "prot_"+pdb_name+".srf"
        name_raydist = "raydist_"+pdb_name+".lst"
        os.rename("prot.srf",name_prot)
        os.rename("raydist.lst", name_raydist)
    return (pdb_name)