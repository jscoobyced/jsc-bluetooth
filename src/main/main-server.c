#include <stdio.h>
#include <glib.h>
#include <gio/gio.h>
#include "btserver.h"
#include "btclient.h"
#include "main.h"
#include "logger.h"

void messageCallback(char *message)
{
  g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "%s", message);
}

int main(int argc, char const *argv[])
{
  GLogLevelFlags flag = G_LOG_LEVEL_ERROR | G_LOG_LEVEL_WARNING | G_LOG_LEVEL_MESSAGE | G_LOG_LEVEL_CRITICAL;
  g_log(JSCBT, G_LOG_LEVEL_MESSAGE, "Starting service \"%s\".", BLUETOOTH_SERVICE_NAME);

  serverConnectionData *data = malloc(sizeof(serverConnectionData));
  data->service_channel = BLUETOOTH_SERVICE_CHANNEL;
  data->service_name = BLUETOOTH_SERVICE_NAME;
  data->service_path = BLUETOOTH_SERVICE_PATH;
  data->service_uuid = BLUETOOTH_SERVICE_UUID;
  data->messageCallback = messageCallback;

  int result = register_service(data, flag);
  if (result != RESULT_OK)
  {
    g_log(JSCBT, G_LOG_LEVEL_ERROR, "Error %d occured while registering.", result);
  }
}