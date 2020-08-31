#ifndef SUGGESTIONSLIST_H
#define SUGGESTIONSLIST_H

#include <QDialog>

#include "QFile"
#include "QDebug"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"

namespace Ui {
class SuggestionsList;
}

class SuggestionsList : public QDialog
{
    Q_OBJECT

public:
    explicit SuggestionsList(QWidget *parent = nullptr);
    ~SuggestionsList();

    void setValues();

private slots:
    void on_exit_clicked();

private:
    Ui::SuggestionsList *ui;
};

#endif // SUGGESTIONSLIST_H
