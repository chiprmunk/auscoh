//
//	AUSCoh rewrite for Anarchia Underground Society Coherent386 UNIX
//	written by Wayne a.j. craig (xenon@aus.org/wcraig@ausc.net)\
//	version(#): 1.0 revision(#): 1
//	date: Sept 21,2016
//
//	filename: bbs.h
//

#ifndef BBS_H
#define BBS_H

// File globally defined file pointers
//
FILE *messagefile;
FILE *whoisfile;
FILE *chatroom;

unsigned int ln;

// location definitions
unsigned int location;

#define LOC_MAINMENU	0x01
#define LOC_CHATROOM	0x02
#define LOC_BBSLOGIN	0x03
#define LOC_MSGBASE	0x04
#define LOC_SYSOPMNU	0x05
#define LOC_ASSYSOPMNU	0x06
#define LOC_LOGIN	0x10
#define LOC_LOGOFF	0x11
#define LOC_CONNECT	0x12

typedef struct _msg {
	unsigned char alignchar;	// align char ^Z for log alignment
	unsigned int location;		// LOCATION unsinged int location
	unsigned char username[25];	// user name
	unsigned char userflags[8];	// user flags
	time_t	packet_time;		// time packet was writen
	unsigned long time_limit; // time limit in minutes
	unsigned int msg_type;		// message type - for message passing
	unsigned char mesg[180];	// 180 char mesg data null terminated

} MSG;

#define MAX_LINES	64

typedef struct _whosonline {
	unsigned char alignchar;	// alignment character ^Z
	unsigned int linenumber;	// line number user is on
	unsigned char dev_tty[30];	// tty user is signed in on
	unsigned char host_ip[60];	// host ip address user is comming from
	unsigned int location;		// user is currently located here
} WHOISONLINE;

WHOISONLINE WIO[MAX_LINES];

// chatroom related messsages and structures
//
#define CHAT_MSG	0x01
#define CHAT_PRIVMSG	0x02
#define CHAT_ENTER	0x10
#define CHAT_EXIT	0x11
#define CHAT_KILL	0x20
#define CHAT_SHELL	0x25
#define CHAT_SYSOPMNU	0x26
#define CHAT_ASSISTMNU	0x27
#define CHAT_HIDE	0x30


typedef struct _chatroom {
	unsigned char alignchar;	// alignment character ^Z
	unsigned int message_type;	// MSG_ type definition
	time_t msg_time;		// time message was writen
	unsigned int usernumber;	// user id number for identifying user
	unsigned char username[30];	// users name
	unsigned char message[180];	// message in chatroom
} CHATROOM;


typedef struct _command {
	unsigned int num;		// command int number
	char *cmd;			// command ptr
	char command[30];		// command text
	char arg[180];			// command argments
} CMD;

#define CMD_EXIT	{1,NULL, "exit",NULL }
#define CMD_HElP	{2,NULL, "help",NULL }
#define CMD_CHANNEl	{3,NULL, "channel",NULL }
#define CMD_INVITE	{4,NULL, "invite",NULL }
#define CMD_WHISPER	{5,NULL, "whisper",NULL }
#define CMD_KICK	{10,NULL, "kick",NULL }
#define CMD_SYSOPMNU	{100,NULL, "sysop",NULL }
#define CMD_ASTSYSOP	{101,NULL, "assist",NULL }

#endif

