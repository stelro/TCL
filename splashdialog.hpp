#ifndef SPLASHDIALOG_HPP
#define SPLASHDIALOG_HPP

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>

class MainWindow;

namespace Ui {
class SplashDialog;
}

class SplashDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SplashDialog(QWidget *parent = 0);
    ~SplashDialog();

private:
    Ui::SplashDialog *ui;
    QList<QSerialPortInfo> mAvaliableSPorts;
    MainWindow *mMainWindow;

private slots:
    void showMainWindow();
    void updateSerialValue(const QString& value);
    void updateDialog();
};

#endif // SPLASHDIALOG_HPP
