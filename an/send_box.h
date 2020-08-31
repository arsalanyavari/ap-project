#ifndef SEND_BOX_H
#define SEND_BOX_H

#include <QDialog>

namespace Ui {
class send_box;
}

class send_box : public QDialog
{
    Q_OBJECT

public:
    explicit send_box(QWidget *parent = nullptr);
    ~send_box();

private slots:
    void on_select_clicked();

    void on_exit_clicked();

signals:
    void send_message(QString);

private:
    Ui::send_box *ui;
};

#endif // SEND_BOX_H
