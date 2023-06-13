import os
import pkgutil
import sys
name_pack = "fibos"

path_pack = pkgutil.get_loader(name_pack).get_filename()

path_pack = os.path.dirname(path_pack)

path_abs = os.path.abspath(path_pack)
sys.path.append(path_abs)

from .cleaner import get_file
from .manage_os import occluded_surface
from .respak import respak