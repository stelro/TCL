#ifndef CHARTTABPAGE_HPP
#define CHARTTABPAGE_HPP

#include <QWidget>
#include <QTimer>

class QCustomPlot;

class ChartTabPage : public QWidget
{
    Q_OBJECT
public:
    ChartTabPage();

private slots:
    void realTimeDataSlot();
    void yAxisRangeMinSet(int min);
    void yAxisRangeMaxSet(int max);
    void xAxisSpeedSet(int speed);
    void xAxisTickSet(int ticks);

private:
    QCustomPlot* mPlot;
    QTimer dataTimer;
    int yAxisLowerRange;
    int yAxisUpperRange;
    int xAxisSpeed;
    int xAxisTicks;
};

#endif // CHARTTABPAGE_HPP
