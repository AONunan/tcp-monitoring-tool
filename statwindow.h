#ifndef STATWINDOW_H
#define STATWINDOW_H

#include <QDialog>

namespace Ui {
class StatWindow;
}

class StatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatWindow(QWidget *parent = 0);
    ~StatWindow();

private:
    Ui::StatWindow *ui;
};

#endif // STATWINDOW_H