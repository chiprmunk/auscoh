//
//	userdata.h - Anarchia Underground Society - Coherent 386 UNIX (auscoh)
//	written by wayne a.j. craig
//	sept 21,2016
//	version 1.0r0
//
//


#define DEFAULT_TIMELIMIT	60
#define NO_TIMELIMIT		0

#define FLAG_SYSOPMNU		0x01
#define FLAG_ASSISTSYSOPMNU	0x02
#define FLAG_NOTIMELIMIT	0x04
#define FLAG_AMATURERADIOUSER	0x08
#define FLAG_HIDDENUSER		0x0f
#define FLAG_flag6		0x1f
#define FLAG_flag7		0x2f
#define FLAG_flag8		0x4f

#define DEFAULT_ACSLVL		10

#define CHATFLAGS_1		"X-------"	// 0x01
#define	CHATFLAGS_2		"-X------"	// 0x02
#define CHATFLAGS_3		"--X-----"	// 0x04
#define CHATFLAGS_4		"---X----"	// 0x08
#define CHATFLAGS_5		"----X---"	// 0x1f
#define CHATFLAGS_6		"-----X--"	// 0x2f
#define CHATFLAGS_7		"------X-"	// 0x4f
#define CHATFLAGS_8		"-------X"	// 0x8f

typedef struct _userinfo {
	char username[60];	// username
	unsigned int acslvl;	// user access lvl 0-64000 typically 64000=sysop
	unsigned int flags;	// bitdefined flags
	char userflags[8];	// user defined flags
	time_t	lasttimeon;	// last date-time online
	long timelimit;		// time limit in minutes 0 = unlimited
	char firstname[16];	// users first name
	char lastname[16];	// users last name
	char emailaddress[50];	// users email address
	char chatroomflags[8];	// chatroom flags for user
	unsigned long numlogins;// number of times connected -incremented
	char phonenum[30];	// users phone number -optional
	char callsign[10];	// users amature radio callsign -optional
        char website[180];	// url for website -optional
	char nickname[20];	// users nickname/alias different from login username

} USERINFO;



