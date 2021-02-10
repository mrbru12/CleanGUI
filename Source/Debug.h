#ifndef CLEAN_DEBUG_H
#define CLEAN_DEBUG_H

#define CLEAN_INFO(title, msg) { printf("[%s Info]: %s\n", title, msg); }

#define CLEAN_ERROR_VOID(title, msg) { printf("[%s Error]: %s\n", title, msg); return; } 
#define CLEAN_ERROR_INFO_VOID(title, msg, info) { printf("[%s Error]: %s %s\n", title, msg, info); return; }

#define CLEAN_ERROR_VALUE(title, msg, value) { printf("[%s Error]: %s\n", title, msg); return value; }
#define CLEAN_ERROR_INFO_VALUE(title, msg, info, value) { printf("[%s Error]: %s %s\n", title, msg, info); return value; }

#endif