#ifndef TRANSFERFORM_H
#define TRANSFERFORM_H

#include <QMainWindow>

namespace Ui {
class TransferForm;
}

class TransferForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit TransferForm(QWidget *parent = nullptr);
    ~TransferForm();

private:
    Ui::TransferForm *ui;
};

#endif // TRANSFERFORM_H
