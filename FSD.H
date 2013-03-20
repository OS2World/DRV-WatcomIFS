#define FSA_REMOTE 1L
#define FSA_UNC    2L
#define FSA_LOCK   4L
#define FSA_CASE   8L
/*------------------------------------------------------------*/
/*                     Volume Parameters                      */
/*------------------------------------------------------------*/

/* File System Independent */
typedef struct vpfsi {
   unsigned long  vpi_vid;       /* 32-bit volume id        */
   unsigned long  vpi_hDEV;      /* handle to device driver */
   unsigned short vpi_bsize;     /* sector size in bytes    */
   unsigned long  vpi_totsec;    /* total number of sectors */
   unsigned short vpi_trksec;    /* sectors per track       */
   unsigned short vpi_nhead;     /* number of heads         */
   char           vpi_text[12];  /* volume name             */
} VPFSI, far *PVPFSI;

/* File System Dependent */
typedef struct vpfsd {
   char           vpi_work[36];  /* work area               */
} VPFSD, far *PVPFSD;


/*------------------------------------------------------------*/
/*                    Current Directories                     */
/*------------------------------------------------------------*/

/* File System Independent */
typedef struct cdfsi {
   unsigned short cdi_hvpb;          /* VPB handle for device     */
   unsigned short cdi_end;           /* offset to root of path    */
   char           cdi_flags;         /* fs independent flags      */
   char           cdi_curdir[CCHMAXPATH]; /* text of current directory */
} CDFSI, far *PCDFSI;

/* File System Dependent */
typedef struct cdfsd {
   char           cdd_work[8];     /* work area                 */
} CDFSD, far *PCDFSD;


/*------------------------------------------------------------*/
/*                       File Instance                        */
/*------------------------------------------------------------*/

/* File System Independent */
typedef struct sffsi {
   unsigned long  sfi_mode;     /* access/sharing mode                 */
   unsigned short sfi_hvpb;     /* volume info.                        */
   FTIME          sfi_ctime;    /* file creation time                  */
   FDATE          sfi_cdate;    /* file creation date                  */
   FTIME          sfi_atime;    /* file access time                    */
   FDATE          sfi_adate;    /* file access date                    */
   FTIME          sfi_mtime;    /* file modification time              */
   FDATE          sfi_mdate;    /* file modification date              */
   unsigned long  sfi_size;     /* size of file                        */
   unsigned long  sfi_position; /* read/write pointer                  */

   /* the following may be of use in sharing checks */

   unsigned short sfi_uid;      /* user ID of initial opener           */
   unsigned short sfi_pid;      /* process ID of initial opener        */
   unsigned short sfi_pdb;      /* PDB (in 3x box) of initial opener   */
   unsigned short sfi_selfsfn;  /* system file number of file instance */
   unsigned char  sfi_tstamp;   /* time stamps flag                    */
   unsigned short sfi_type;     /* type of object opened               */
} SFFSI, far *PSFFSI;

/* File System Dependent */
typedef struct sffsd {
   char           sfd_work[30]; /* work area                           */
} SFFSD, far *PSFFSD;


/*------------------------------------------------------------*/
/*                        File Search                         */
/*------------------------------------------------------------*/

/* File System Independent */
typedef struct fsfsi {
   unsigned short fsi_hvpb;         /* volume info */
} FSFSI, far *PFSFSI;


/* File System Dependent */
typedef struct fsfsd {
   char           fsd_work[24];     /* work area   */
} FSFSD, far *PFSFSD;

