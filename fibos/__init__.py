import os
import pkgutil
import sys
name_pack = "fibos"

path_pack = pkgutil.get_loader(name_pack).get_filename()

path_pack = os.path.dirname(path_pack)

path_abs = os.path.abspath(path_pack)
sys.path.append(path_abs)

from .manage_os import occluded_surface
from .read_Os import read_prot
from .read_Disp import read_Disp
