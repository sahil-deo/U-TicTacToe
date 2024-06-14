#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void checkWin();

    void AImove();

    void on_four_clicked();

    void on_NewGame_clicked();

    void on_two_clicked();

    void on_one_clicked();

    void on_three_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
