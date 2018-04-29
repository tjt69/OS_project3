/*
  Copyright (C) 2012 Joseph J. Pfeiffer, Jr., Ph.D. <pfeiffer@cs.nmsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  There are a couple of symbols that need to be #defined before
  #including all the headers.
*/

#ifndef _PARAMS_H_
#define _PARAMS_H_

// The FUSE API has been changed a number of times.  So, our code
// needs to define the version of the API that we assume.  As of this
// writing, the most current API version is 26
#define FUSE_USE_VERSION 26

// need this to get pwrite().  I have to use setvbuf() instead of
// setlinebuf() later in consequence.
#define _XOPEN_SOURCE 500

// maintain bbfs state in here
#include <limits.h>
#include <stdio.h>
#include <time.h>
struct sfs_state {
    FILE *logfile;
    char *diskfile;
};

char* currDir;

typedef struct i_node {
	int mode;	//Permissions
	int ino;	//node id
	int size;	//size  of file in  bytes 
	time_t atime;	//time of last access
	time_t ctime;	//time created
	time_t mtime;	//time modified
	int gid;	//group id
	int uid;	//onwer id
	int links_count;//Number of hard links to file
	int numBlksAllc;//Number of blocks allocated to this file
	int strBlk;
	char flag;
	char type;	//d = directory, f = file, p = p-node
	int numf;
	char name[32];	//file/directory name
}inode;

typedef struct super_block{
	int num_dbm_blks;
	int num_ibm_blks;
	int num_inodes;		//Number of inodes i.e. files/directories we can support
	int num_datablks;	//Number of data blocks availible 
	int inode_bm_str;
	int data_bm_str;
	int inode_str;
	int data_str;
	int root_node;
}super_blk;

typedef struct _dirEntry{
	char* name;
	int ino;
	//int init;
}dirEntry;


#define SFS_DATA ((struct sfs_state *) fuse_get_context()->private_data)

#endif
