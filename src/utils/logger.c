#include <glib.h>
#include <time.h>
#include <stdarg.h>
#include "logger.h"

#define TIME_BUF_LEN 256

static void log_handler(const gchar *log_domain,
                        GLogLevelFlags log_level,
                        const gchar *message,
                        gpointer user_data)
{
  if (log_level == G_LOG_LEVEL_DEBUG)
  {
    g_print("%s", message);
    return;
  }
  time_t now = time(NULL);
  struct tm *ptm = localtime(&now);
  char time_display[TIME_BUF_LEN] = {0};
  strftime(time_display, TIME_BUF_LEN, "%Y-%m-%d %H:%M:%S", ptm);
  g_print("%s - %s - %s\n", time_display, log_domain, message);
}

void set_logger(const gchar *domain, GLogLevelFlags flag)
{
  g_log_set_handler(domain, flag, log_handler, NULL);
}