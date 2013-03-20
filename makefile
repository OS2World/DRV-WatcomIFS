#
# Auto-dependency information
#
OS21_H   = $(%WATCOM)\h\os21x;.\
C16FLAGS = -i=$(OS21_H) -bt=os2 -ms -s -zdp -zff -zgf -zu -zl -zq -wx
WC16     = wcl $(C16FLAGS)

.SUFFIXES:
.SUFFIXES: .obj .c
.c.obj: .AUTODEPEND
        $(WC16) $*.c

all: .SYMBOLIC sample.ifs
        @echo All done!

OBJS = sample.obj

sample.ifs: $(OBJS)
        @%create sample.lnk
        @%append sample.lnk name sample.ifs
        @%append sample.lnk sys os2 dll
        @%append sample.lnk option protmode
        @%append sample.lnk option map
        @%append sample.lnk option quiet
        @%append sample.lnk option stack=0
        @%append sample.lnk lib os2
        @%append sample.lnk lib fshelper.lib
        @%append sample.lnk lib dhcalls.lib
        @%append sample.lnk import DOSWRITE DOSCALLS.138
        @%append sample.lnk import DOS32FLATDS DOSCALLS.370
        @for %f in ($(OBJS)) do @%append sample.lnk file %f
        @%append sample.lnk segment '_TEXT' PRELOAD EXECUTEREAD NONSHARED
        @%append sample.lnk segment type DATA PRELOAD NONSHARED
        @%append sample.lnk export FS_ALLOCATEPAGESPACE
        @%append sample.lnk export FS_ATTRIBUTE
        @%append sample.lnk export FS_NAME
        @%append sample.lnk export FS_ATTACH
        @%append sample.lnk export FS_CHDIR
        @%append sample.lnk export FS_CHGFILEPTR
        @%append sample.lnk export FS_CLOSE
        @%append sample.lnk export FS_COMMIT
        @%append sample.lnk export FS_COPY
        @%append sample.lnk export FS_DELETE
        @%append sample.lnk export FS_EXIT
        @%append sample.lnk export FS_FILEATTRIBUTE
        @%append sample.lnk export FS_FILEINFO
        @%append sample.lnk export FS_FILELOCKS
        @%append sample.lnk export FS_FINDCLOSE
        @%append sample.lnk export FS_FINDFIRST
        @%append sample.lnk export FS_FINDFROMNAME
        @%append sample.lnk export FS_FINDNEXT
        @%append sample.lnk export FS_FINDNOTIFYCLOSE
        @%append sample.lnk export FS_FINDNOTIFYFIRST
        @%append sample.lnk export FS_FINDNOTIFYNEXT
        @%append sample.lnk export FS_FLUSHBUF
        @%append sample.lnk export FS_FSCTL
        @%append sample.lnk export FS_FSINFO
        @%append sample.lnk export FS_INIT
        @%append sample.lnk export FS_IOCTL
        @%append sample.lnk export FS_MKDIR
        @%append sample.lnk export FS_MOUNT
        @%append sample.lnk export FS_MOVE
        @%append sample.lnk export FS_NEWSIZE
        @%append sample.lnk export FS_NMPIPE
        @%append sample.lnk export FS_OPENCREATE
        @%append sample.lnk export FS_PATHINFO
        @%append sample.lnk export FS_PROCESSNAME
        @%append sample.lnk export FS_READ
        @%append sample.lnk export FS_RMDIR
        @%append sample.lnk export FS_SETSWAP
        @%append sample.lnk export FS_SHUTDOWN
        @%append sample.lnk export FS_WRITE
        @%append sample.lnk export FS_DOPAGEIO
        @%append sample.lnk export FS_OPENPAGEFILE
        @%append sample.lnk export FS_CANCELLOCKREQUEST
        @%append sample.lnk export FS_FILEIO
        wlink @sample.lnk

clean: .SYMBOLIC
        @if exist *.obj del *.obj
        @if exist *.exe del *.exe
        @if exist *.ifs del *.ifs
        @if exist *.err del *.err
        @if exist *.map del *.map
        @if exist *.lnk del *.lnk

