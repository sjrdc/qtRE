#include <QDate>
#include <QDebug>

#include <iostream>

int main( int argc, char **argv )
{
    // QDate QDate::fromString(const QString &string, const QString &format)
    // QTime QTime::fromString(const QString &string, const QString &format)

    QString datestring = "2016-12-06";
    QDate date = QDate::fromString(datestring, "yyyy-MM-dd");
    qDebug() << datestring << date;

    QString timestring = "14:42:43.44";
    QTime time = QTime::fromString(timestring + "0", "hh:mm:ss.zzz");
    qDebug() << timestring << time;

    return 0;
}
