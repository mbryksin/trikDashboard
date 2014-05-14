#pragma once
#include <QString>
#include <QKeySequence>
#include <QSize>

//sensors
QString const ACCELEROMETER_NAME = "Accelerometer";
QString const GYROSCOPE_NAME = "Gyroscope";

//numbers
int const SENSORS_DATA_UPDATE_PERIOD = 10;
int const WAITING_RESPONSE_TIME = 5000;
int const TOOLBAR_WIDTH = 120;
QSize const PANEL_START_SIZE = QSize(800, 600);
QSize const PANEL_MIN_SIZE = QSize(640, 480);

//wi-fi
QString const START_IP_STRING = "192.168.1.36";
QString const START_PORT_STRING = "1221";
int const START_PORT_INT = 1221;

//shortcuts
QKeySequence const SHOW_HIDE_SHORTCUT = Qt::CTRL|Qt::Key_Q;

//commands
QString const SUBSCRIBE_STRING = "subscribe:";
QString const UNSUBSCRIBE_STRING = "unsubscribe:";

//user messages
QString const SHOW_HIDE_TEXT = "Use Ctrl+Q for show/hide menu";
QString const WAITING_RESPONSE_MESSAGE = "Connection to TRIK: waiting responce...";
QString const NOCONNECTION_MESSAGE = "No connection: try to connect again";
QString const SEND_MESSAGE = "Dashboard connected";
QString const SEND_FROM_DAEMON_MESSAGE = "TRIK connected";