import os
import pkgutil
import sys
import platform
name_pack = "fibos"

path_pack = pkgutil.get_loader(name_pack).get_filename()

path_pack = os.path.dirname(path_pack)

path_abs = os.path.abspath(path_pack)

if(platform.system() == "Windows"):
    path_abs = path_abs+"\.libs"

sys.path.append(path_abs)

from .manage_os import occluded_surface
from .read_Os import read_prot
from .read_Disp import read_Disp
