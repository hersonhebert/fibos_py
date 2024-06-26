C     -*- fortran -*-
C     This file is autogenerated with f2py (version:1.26.4)
C     It contains Fortran 77 wrappers to fortran functions.

      subroutine f2pyinitresids(setupfunc)
      external setupfunc
      integer nseg
      character*3 secnm(2000)
      integer secsq(2000)
      character*4 atnm(20000)
      integer iats(2000)
      integer iate(2000)
      integer seqcd(2000)
      integer natom
      common /resids/ nseg,secnm,secsq,atnm,iats,iate,seqcd,natom
      call setupfunc(nseg,secnm,secsq,atnm,iats,iate,seqcd,natom)
      end

      subroutine f2pyinitcoord(setupfunc)
      external setupfunc
      real cr(20000,3)
      character*1 secsqe(2000)
      character*1 rescid(2000)
      common /coord/ cr,secsqe,rescid
      call setupfunc(cr,secsqe,rescid)
      end

      subroutine f2pyinitanput(setupfunc)
      external setupfunc
      character*13 resinf(5)
      character*13 residen
      common /anput/ resinf,residen
      call setupfunc(resinf,residen)
      end

      subroutine f2pyinitvdw(setupfunc)
      external setupfunc
      real vdwrad(20000)
      integer inter
      integer icter
      common /vdw/ vdwrad,inter,icter
      call setupfunc(vdwrad,inter,icter)
      end


