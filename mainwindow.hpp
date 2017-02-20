#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class QListWidgetItem;
class QWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   void tabBarItemClicked(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;

    QWidget *turbinePage;
    QWidget *chartPage;
};

#endif // MAINWINDOW_HPP
