
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "logger.h"

struct log_info {
	char *color;
	char *error;
};

struct log_info log_info[] = {
	[ESMA_LOG_DBG] = {
		.color = "\x1B[94m",	/* light blue	*/
		.error = "DBG: ",
	},
	[ESMA_LOG_WRN] = {
		.color = "\x1B[33m",	/* yellow	*/
		.error = "WRN: ",
	},
	[ESMA_LOG_ERR] = {
		.color = "\x1B[91m",	/* light red	*/
		.error = "ERR: ",
	},
	[ESMA_LOG_SYS] = {
		.color = "\x1B[95m",	/* ligh magenta	*/
		.error = "SYS: ",
	},
	[ESMA_LOG_INF] = {
		.color = "\x1B[32m",	/* green	*/
		.error = "INF: ",
	},
	[ESMA_LOG_FTL] = {
		.color = "\x1B[31m",	/* red		*/
		.error = "FTL: ",
	},
	[ESMA_LOG_NRM] = {
		.color = "\x1B[0m",	/* normal color	*/
		.error = "NRM: ",
	},
};

u32 log_level = ESMA_LOG_FTL;
u32 log_flags = 0;

void logger_set_log_level(u32 level)
{
	log_level = level;
}

void logger_set_log_flags(u32 flags)
{
	log_flags = flags;
}

void console_log(int flags, int level, char *fmt, ...)
{
	va_list args;

	char report_str[ESMA_MAX_REPORT_STR];
	char *p;

	if (0 == (flags & log_flags))
		return;

	if (level < log_level || level > ESMA_LOG_NRM)
		return;

	va_start(args, fmt);

	p = report_str;

	sprintf(p, "%s", log_info[level].color);
	p += strlen(log_info[level].color);

	sprintf(p, "%s", log_info[level].error);
	p += 5;	/* All msg - ect "DBG: " - has lenght equal 5 */
	
	p += vsnprintf(p, ESMA_MAX_REPORT_STR, fmt, args);
	
	sprintf(p, "%s", log_info[ESMA_LOG_NRM].color);

	printf("%s", report_str);
	fflush(stdout);
}
