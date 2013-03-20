#define INCL_DOSINFOSEG
#define INCL_DOSERRORS
#define INCL_DOSFILEMGR

#include <os2.h>
typedef PVOID *PPVOID;
#include <dhcalls.h>
#include <fsd.h>
#include <fsh.h>

PFN pfnDevHelp;

/*
 *** Globals which fsd's must export
 */

ULONG pascal FS_ATTRIBUTE = FSA_REMOTE;
CHAR  pascal FS_NAME[] = "SAMPLE";

static char hello_msg[] = "\r\nSample IFS Driver\r\nProvided by: P. Ingle [patrick_ingle@yahoo.com]\r\n\r\n";


/***    FS_AllocatePageSpace - Adjust the size of the paging file
 *
 *      ENTRY   psffsi      = File System Independent portion of SFT
 *              psffsd      = File System Dependent portion of SFT
 *              lSize       = new size ,(in bytes)
 *              lWantContig = minimum contiguity requirement (in bytes)
 *
 *      EXIT  Returns 0 if OK
 *
 *            Returns non-zero error code if error
 ***/

int EXPENTRY FS_AllocatePageSpace (
                      struct sffsi far *    psffsi,
                      struct sffsd far *    psffsd,
                      ULONG                 lSize,
                      ULONG                 lWantContig)

{
    int RetCode = ERROR_NOT_SUPPORTED;

    return RetCode;


}   /* FS_AllocatePageSpace */


/* put stand-alone fs_xxx functions in separate code segment */


int EXPENTRY FS_ATTACH(
           USHORT               flag,
           PCHAR                pDev,
           PVOID                pvpfsd,
           PVOID                pcdfsd,
           PCHAR                pParm,
           PUSHORT              pLen)
{
        return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_CHGFILEPTR(
               struct sffsi far * psffsi,
               struct sffsd far * psffsd,
               LONG offlSeek,
               USHORT type,
               USHORT IOflag)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_CHDIR(
     USHORT                  flag,
     struct cdfsi far *      pcdfsi,
     struct cdfsd far *      pcdfsd,
     CHAR far *              pDir,
     USHORT                  iCurDirEnd)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_CLOSE(
          USHORT            type,
          USHORT            IOflag,
          struct sffsi far *psffsi,
          struct sffsd far *psffsd)
{
    USHORT erc = ERROR_NOT_SUPPORTED;
    return erc;

}

int EXPENTRY FS_COMMIT(
           USHORT type,
           USHORT IOflag,
           struct sffsi far *psffsi,
           struct sffsd far *psffsd)
{
    return ERROR_NOT_SUPPORTED;

}

/*
 ***    FS_COPY - Not supported (yet) for HPFS (Pinball)
 *
 */

/* put stand-alone fs_xxx functions in separate code segment */

int EXPENTRY FS_COPY(
         USHORT Flag,
         struct cdfsi far * pcdfsi,
         struct cdfsd far * pcdfsd,
         PCHAR  pSrc,
         USHORT iSrcCurDirEnd,
         PCHAR  pDst,
         USHORT iDstCurDirEnd,
         USHORT nameType)
{
        return (ERROR_CANNOT_COPY);

}

int EXPENTRY FS_DELETE(
    struct cdfsi far *      pcdfsi,
    struct cdfsd far *      pcdfsd,
    char far *              pFile,
    USHORT                  iCurDirEnd)
{

        return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_DOPAGEIO(
             struct sffsi far *        psffsi,
             struct sffsd far *        psffsd,
             struct PageCmdHeader far *pList)

{

    return ERROR_NOT_SUPPORTED;


}   /* FS_DoPageIO */

int EXPENTRY FS_EXIT(
         USHORT uid,
         USHORT pid,
         USHORT pdb)
{

        return 0;
}

int EXPENTRY FS_FILEATTRIBUTE(
    USHORT                  flag,
    struct cdfsi far *      pcdfsi,
    struct cdfsd far *      pcdfsd,
    char far *              pName,
    USHORT                  iCurDirEnd,
    PUSHORT                 pAttr)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_CANCELLOCKREQUEST(
           struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           struct filelock far * pLockRange)
{
        return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_FINDCLOSE(
       struct fsfsi far * pfsfsi,
       struct fsfsd far * pfsfsd)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_FINDFROMNAME (
    struct fsfsi far *  pfsfsi,
    struct fsfsd far *  pfsfsd,
    PCHAR               pbData,     /* ptr to data buffer */
    USHORT              cbData,     /* size of data buffer */
    PUSHORT             pcMatch,    /* number of matching entries returned */
    USHORT              usLevel,    /* level of info returned */
    ULONG               ulPos,      /* unused by Pinball */
    PCHAR               pbName,
    USHORT              usFlags)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_FINDFIRST (
    struct cdfsi far *      pcdfsi,
    struct cdfsd far *      pcdfsd,
    CHAR far *              pchName,    /* search pattern (including path) */
    USHORT                  usCurDirEnd,
    USHORT                  usAttr,     /* search attrib (hidden/system/dir) */
    struct fsfsi far *      pfsfsi,
    struct fsfsd far *      pfsfsd,
    CHAR far *              pbData,     /* ptr to data buffer */
    USHORT                  cbData,     /* size of data buffer */
    USHORT far *            pcMatch,    /* # of matching entries returned */
    USHORT                  usLevel,    /* level of info returned */
    USHORT                  usFlags
)
{

    return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_FILEINFO(
    USHORT                  flag,
    struct sffsi far *      psffsi,
    struct sffsd far *      psffsd,
    USHORT                  level,
    char far *              pData,
    USHORT                  cbData,
    USHORT                  IOflag)
{

    return ERROR_NOT_SUPPORTED;

}

/* put stand-alone fs_xxx functions in separate code segment */


int EXPENTRY FS_FILEIO (struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           PCHAR              pcCmdList,
           USHORT             pusCmdLen,
           PUSHORT            pusError,
           USHORT             IOflag)
{
        return ERROR_NOT_SUPPORTED;

}

int EXPENTRY FS_FLUSHBUF(
    USHORT  hVPB,
    USHORT  usFlag)         /* FLUSH_RETAIN cache data or FLUSH_DISCARD it */
{

    return ERROR_NOT_SUPPORTED;
}



int EXPENTRY FS_FINDNEXT (
    struct fsfsi far *  pfsfsi,
    struct fsfsd far *  pfsfsd,
    PCHAR               pbData,     /* ptr to data buffer */
    USHORT              cbData,     /* size of data buffer */
    PUSHORT             pcMatch,     /* number of matching entries returned */
    USHORT              usLevel,
    USHORT              usFlags
    )
{

    return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_FSCTL (union argdat far * pArgDat,
          USHORT        usArgType,
          USHORT        usFunc,
          PCHAR         pcParm,
          USHORT        usLenParm,
          PUSHORT       pusLenParmOut,  /* len of data returned in pcParm */
          PCHAR         pcData,
          USHORT        usLenData,
          PUSHORT       pusLenDataOut)  /* len of data returned in pcData */
{
    USHORT usRet = NO_ERROR;
    return (usRet);
}

int EXPENTRY FS_FILELOCKS (struct sffsi far * psffsi,
           struct sffsd far * psffsd,
           struct filelock far * pUnLockRange,
           struct filelock far * pLockRange,
           ULONG far * pEventSemHandle,
           ULONG              flags,
           ULONG        far * pPostCt)
{
        return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_FSINFO(
    USHORT          flag,
    USHORT          hVPB,
    CHAR far *      p,
    USHORT          cbData,
    USHORT          level)
{

    return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_INIT (
         PCHAR pcParm,   /* passed in from config.sys line */
         ULONG DevHelp,
         ULONG far *pMiniFSD)
{
    USHORT wlen;

    pfnDevHelp = (PFN)DevHelp;

    DosWrite(1, hello_msg, sizeof(hello_msg)-1, &wlen);

    return NO_ERROR;
}

int EXPENTRY FS_IOCTL (struct sffsi far * psffsi,
          struct sffsd far * psffsd,
          USHORT             cat,
          USHORT             func,
          PCHAR              pParm,
          USHORT             lenMaxParm,
          PUSHORT            plenInOutParm,
          PCHAR              pData,
          USHORT             lenMaxData,
          PUSHORT            plenInOutData)
{

        return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_MKDIR (struct cdfsi far *pcdfsi,
          struct cdfsd far *pcdfsd,
          char far *        pName,
          unsigned short    iCurDirEnd,
          char far *        pEABuf,
          unsigned short    flags)
{

    return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_MOUNT (USHORT            fsOper, /* operation requested */
          struct vpfsi far *pvpfsi, /* ptr to file sys indep part of VPB */
          struct vpfsd far *pvpfsd, /* ptr to file sys dependent part of VPB */
          SHANDLE           hVPB,   /* volume handle */
          PCHAR             pBoot)  /* pointer to sector 0 */
{
    return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_MOVE (struct cdfsi far *pcdfsi,
         struct cdfsd far *pcdfsd,
         PCHAR             pSrc,
         USHORT            iSrcCurDirEnd,
         PCHAR             pDst,
         USHORT            iDstCurDirEnd,
         USHORT            flags)
{

        return ERROR_NOT_SUPPORTED;
}

/*
 ***    FS_NMPIPE -
 *
 */

/* put stand-alone fs_xxx functions in separate code segment */

int EXPENTRY FS_NMPIPE (struct sffsi far *  pfsfsi,
           struct sffsd far *  pfsfsd,
           USHORT              OpType,
           union npoper far *  pOpRec,
           PCHAR               pData,
           PCHAR               pName)
{
        return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_NEWSIZE(
    struct sffsi far *      psffsi,
    struct sffsd far *      psffsd,
    ULONG                   len,
    USHORT                  IOflag)
{

    return ERROR_NOT_SUPPORTED;
}
/*
 ***    fs_notfy.c - FS_FINDNOTIFY routines
 *
 *      Copyright Microsoft, 1988.
 */

int EXPENTRY FS_FINDNOTIFYCLOSE(USHORT handle)
{

    return ERROR_NOT_SUPPORTED;
}

int EXPENTRY FS_FINDNOTIFYFIRST(struct cdfsi far *pcdfsi,
                   struct cdfsd far *pcdfsd,
                   PCHAR  pName,
                   USHORT iCurDirEnd,
                   USHORT attr,
                   USHORT far *pHandle,
                   PCHAR  pData,
                   USHORT cbData,
                   USHORT far *pcMatch,
                   USHORT level,
                   ULONG timeout)
{

    return ERROR_NOT_SUPPORTED;
}


int EXPENTRY FS_FINDNOTIFYNEXT(USHORT handle,
                  PCHAR  pData,
                  USHORT cbData,
                  USHORT far *pcMatch,
                  USHORT level,
                  ULONG  timeout)
{
    INT iRet = ERROR_NOT_SUPPORTED;

    return iRet;
}

int EXPENTRY FS_OPENCREATE(
     struct cdfsi far *      pcdfsi,         /* File system indep. directory */
     struct cdfsd far *      pcdfsd,         /* file system dep. directory   */
     PCHAR                   pcName,         /* canonicalized file name      */
     USHORT                  usCurDirEnd,    /* index of end of cur dir in pcName */
     struct sffsi far *      psffsi,         /* file sys indep open file     */
     struct sffsd far *      psffsd,         /* file sys depend open file    */
     ULONG                   ulOpenMode,     /* sharing and access mode      */
     USHORT                  usOpenFlag,     /* action if present or absent  */
     PUSHORT                 pusRetAction,   /* return for action code       */
     USHORT                  usAttr,         /* file attributes              */
     PCHAR                   pcEABuf,        /* Extended Attribute buffer    */
     PUSHORT                 pfGenFlag)      /* return for Need eas bit      */
{
        return ERROR_NOT_SUPPORTED;
}


int EXPENTRY FS_OPENPAGEFILE (PULONG             pFlags,     /* FirstOpen, Phys/Virt-Addr */
                 PULONG             pcMaxReq,   /* returned max req list len */
                 PCHAR              pName,      /* Name of page file */
                 struct sffsi far * psffsi,     /* sft - fs independent */
                 struct sffsd far * psffsd,     /* sft - fs dependent */
                 USHORT             OpenMode,   /* for open/create */
                 USHORT             OpenFlag,   /* for open/create */
                 USHORT             Attr,       /* for open/create */
                 ULONG              Reserved)



{
    return ERROR_NOT_SUPPORTED;
}   /* FS_OPENPAGEFILE */

/*
 ***    FS_PROCESSNAME - Process the filename to be Pinball Legal
 *
 *      This routine allows the FSD to enforce a different
 *      naming convention than OS/2.
 *
 *      ENTRY   pNameBuf = pointer to ASCIIA pathname.
 *
 *      EXIT    Returns NO_ERROR
 */

int EXPENTRY FS_PROCESSNAME (PCHAR pNameBuf)   /* Path string to be processed */
{
        /*
         * Since Pinball is a true OS/2 file system, we don't need
         * to change anything.
         */
        return (NO_ERROR);
}

int EXPENTRY FS_PATHINFO(
    USHORT                  flag,
    struct cdfsi far *      pcdfsi,
    struct cdfsd far *      pcdfsd,
    PCHAR                   pName,
    USHORT                  iCurDirEnd,
    USHORT                  level,
    PCHAR                   pData,
    USHORT                  cbData)
{
    USHORT erc = ERROR_NOT_SUPPORTED;

    return erc;
}


int EXPENTRY FS_READ(
    struct sffsi far        *psffsi,
    struct sffsd far        *psffsd,
    CHAR far                *pcData,
    USHORT far              *pusLen,
    USHORT                  IOflag)
{
        USHORT usRet = ERROR_NOT_SUPPORTED;

        return (usRet);
}

int EXPENTRY FS_RMDIR(
     struct cdfsi far *      pcdfsi,
     struct cdfsd far *      pcdfsd,
     char far *              pName,
     unsigned short          iCurDirEnd)
{
        USHORT usRet = ERROR_NOT_SUPPORTED;


        return (usRet);
}

/* put stand-alone fs_xxx functions in separate code segment */

int EXPENTRY FS_SETSWAP (struct sffsi far * psffsi,
            struct sffsd far * psffsd)
{

    /*
     * Just return no error.  Since we always mark pinball segments
     * non-swappable, we don't need to do anything here.
     */
    return (NO_ERROR);
}

int EXPENTRY FS_SHUTDOWN(
    USHORT usType,
    ULONG ulReserved)
{
    INT iRet = ERROR_NOT_SUPPORTED;


    return (iRet);
}

int EXPENTRY FS_WRITE(
    struct sffsi far *      psffsi,
    struct sffsd far *      psffsd,
    CHAR far *              pcData,
    USHORT far *            pusLen,
    USHORT IOflag)
{

        return ERROR_NOT_SUPPORTED;
}
