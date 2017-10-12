#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QObject>
#include <QTimer>
#include <QPainter>

class Message : public QObject
{
    Q_OBJECT
public:
    Message();
    void display(QPainter *painter, int x, int y) const;
    void setText(const QString &text);

private:
    QString text;
    QTimer duration;

private slots:
    void emptyText();
};

#endif // MESSAGE_HPP
