#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include "btserver.h"
#include "btclient.h"
#include "main.h"
#include "logger.h"

void deviceCallback(btDevice *device)
{
  if (device->complete == TRUE)
  {
    g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "Device %s [%s] is available.",
          device->name,
          device->address);
  }
  else
  {
    g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "No device found.");
  }
}

int main(int argc, char const *argv[])
{
  GLogLevelFlags flag = G_LOG_LEVEL_ERROR | G_LOG_LEVEL_WARNING | G_LOG_LEVEL_MESSAGE | G_LOG_LEVEL_CRITICAL;

  set_logger(JSCBT, flag);

  g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "Starting discovery of UUID [%s].", BLUETOOTH_SERVICE_UUID);
  int result = discover_service(deviceCallback, BLUETOOTH_SERVICE_UUID, BLUETOOTH_DISCOVERY_TIMEOUT_SECONDS);
  if (result != RESULT_OK)
  {
    g_log(JSCBT, G_LOG_LEVEL_ERROR, "Error %d occured while searching for device.", result);
  }
  else
  {
    g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "Completed successfully.");
  }
}