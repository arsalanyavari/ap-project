#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class Warning;
}

class Warning : public QDialog
{
    Q_OBJECT

public:
    explicit Warning(QWidget *parent = nullptr);
    ~Warning();
    void setMessage(QString txt);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Warning *ui;
};

#endif // WARNING_H
