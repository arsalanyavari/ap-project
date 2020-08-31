#ifndef SUREWARNING_H
#define SUREWARNING_H

#include <QDialog>

namespace Ui {
class SureWarning;
}

class SureWarning : public QDialog
{
    Q_OBJECT

public:
    explicit SureWarning(QWidget *parent = nullptr);
    ~SureWarning();

    int test = -1;
    void setMessage(QString message);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SureWarning *ui;
};

#endif // SUREWARNING_H
