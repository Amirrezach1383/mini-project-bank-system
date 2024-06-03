#ifndef NEWACCOUNTFORM_H
#define NEWACCOUNTFORM_H

#include <QWidget>

namespace Ui {
class NewAccountForm;
}

class NewAccountForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewAccountForm(QWidget *parent = nullptr);
    ~NewAccountForm();

private:
    Ui::NewAccountForm *ui;
};

#endif // NEWACCOUNTFORM_H
