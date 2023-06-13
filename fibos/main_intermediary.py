import ctypes as ct
import numpy as np
import os
import main75
import ds75
import surfcal76

def call_main(iresf, iresl, maxres, maxat, meth):
    resnum = (ct.c_int*maxres)()
    x = (ct.c_double*maxat)()
    y = (ct.c_double*maxat)()
    z = (ct.c_double*maxat)()
    natm = np.array([1], dtype=np.int_)
    main75.main(resnum,natm,x,y,z,iresf,iresl)
    for i in range(maxat):
        if x[i]!=0:
            x[i] = round(x[i],3)
        if y[i] != 0:
            y[i] = round(y[i], 3)
        if z[i] != 0:
            z[i] = round(z[i], 3)
    x1 = 0
    for ires in range(iresf, iresl+1):
        main75.main_intermediate(x,y,z,ires,resnum,natm[0])
        main75.main_intermediate01(x,y,z,ires,resnum,natm[0])
        ds75.runsims(meth)
        surfcal76.surfcal()
    os.rename("file.srf","prot.srf")