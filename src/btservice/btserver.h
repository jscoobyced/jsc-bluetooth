#include <glib-object.h>
#include <gio/gio.h>

typedef struct ServerUserData
{
  GMainLoop *loop;
} serverUserData;

typedef void (*BluetoothMessageCallback)(char *message);

typedef struct ServerConnectionData
{
  char *service_path;
  char *service_name;
  int service_channel;
  char *service_uuid;
  BluetoothMessageCallback messageCallback;
} serverConnectionData;

typedef void (*BluetoothConnectCallback)(GObject *, GAsyncResult *, gpointer);

int register_service(serverConnectionData *data,
                     GLogLevelFlags flag);
