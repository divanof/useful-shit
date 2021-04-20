
#ifndef ESMA_LOGGER_H
#define ESMA_LOGGER_H

#include "numeric_types.h"

#define ESMA_LOG_DBG	0
#define ESMA_LOG_WRN	1
#define ESMA_LOG_ERR	2
#define ESMA_LOG_SYS	3
#define ESMA_LOG_INF	4
#define ESMA_LOG_FTL	5
#define ESMA_LOG_NRM	6

#define ESMA_LOG_USER		0x01
#define ESMA_LOG_CORE		0x02

#define ESMA_MAX_REPORT_STR	2048

extern u32 log_level;
extern u32 log_flags;

void logger_set_log_level(u32 level);
void logger_set_log_flags(u32 flags);

#define user_log_nrm(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_NRM, fmt, __VA_ARGS__)
#define user_log_dbg(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_DBG, fmt, __VA_ARGS__)
#define user_log_wrn(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_WRN, fmt, __VA_ARGS__)
#define user_log_err(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_ERR, fmt, __VA_ARGS__)
#define user_log_sys(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_SYS, fmt, __VA_ARGS__)
#define user_log_inf(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_INF, fmt, __VA_ARGS__)
#define user_log_ftl(fmt, ...)		console_log(ESMA_LOG_USER, ESMA_LOG_FTL, fmt, __VA_ARGS__)

#define core_log_nrm(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_NRM, fmt, __VA_ARGS__)
#define core_log_dbg(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_DBG, fmt, __VA_ARGS__)
#define core_log_wrn(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_WRN, fmt, __VA_ARGS__)
#define core_log_err(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_ERR, fmt, __VA_ARGS__)
#define core_log_sys(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_SYS, fmt, __VA_ARGS__)
#define core_log_inf(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_INF, fmt, __VA_ARGS__)
#define core_log_ftl(fmt, ...)		console_log(ESMA_LOG_CORE, ESMA_LOG_FTL, fmt, __VA_ARGS__)

void console_log(int flags, int level, char *fmt, ...);

#endif
