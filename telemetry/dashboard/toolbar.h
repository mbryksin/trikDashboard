#pragma once
#include "../telemetry_const.h"

#include <QToolBar>
#include <QLineEdit>
#include <QToolBox>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <controlpanel.h>

class ToolBar : public QToolBar
{
    Q_OBJECT

public:
    ToolBar(ControlPanel* panel);
    QToolBox* menuBox;

signals:
    void setConnection(QString ip, int port);

protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

public slots:
    void insertTelemetry();
    void deleteTelemetry();

private slots:
    void retranslateUi();
    void setLanguage(int lang);
    void insertToolBox();
    void connectButtonPressed();

private:
    QLineEdit* portTextEdit;
    QLineEdit* ipTextEdit;
    QLabel* ipLabel;
    QLabel* portLabel;
    QCheckBox* logging;
    QPushButton* connectButton;
    QToolBox* telemetry;
    ControlPanel* panel;

};
