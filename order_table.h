#ifndef ORDER_H
#define ORDER_H
#include <QWidget>
#include <QTableWidget>
#include <QDropEvent>
#include<QDebug>
class order_table :public QTableWidget
{
    Q_OBJECT
public:
    explicit order_table(QWidget *parent=nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
signals:
    void changed();
};

#endif // ORDER_H
