#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

enum GuiErrorMessage{None, CreatingRoomExists, CantCreateRoom};

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    enum Keys{
        //Buttons
        ConnectRoom,
        CreateRoom
    };
    enum Types{
        Clicked,
        Pressed,
        Released
    };

signals:

public slots:
};

#endif // SETTINGS_H
