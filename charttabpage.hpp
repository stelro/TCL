#ifndef CHARTTABPAGE_HPP
#define CHARTTABPAGE_HPP

#include <QWidget>
#include <QTimer>

class QCustomPlot;
class QLabel;

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

    void cColorSet1(bool);
    void cColorSet2(bool);
    void cColorSet3(bool);
    void cColorSet4(bool);
    void cColorSet5(bool);

    void cColorSet6(bool);
    void cColorSet7(bool);
    void cColorSet8(bool);
    void cColorSet9(bool);
    void cColorSet10(bool);

    void cColorSet11(bool);
    void cColorSet12(bool);
    void cColorSet13(bool);
    void cColorSet14(bool);
    void cColorSet15(bool);

    void mPlotSet1(bool value) { mPlotEnabled1 = value; }
    void mPlotSet2(bool value) { mPlotEnabled2 = value; }
    void mPlotSet3(bool value) { mPlotEnabled3 = value; }
    void mPlotSet4(bool value) { mPlotEnabled4 = value; }
    void mPlotSet5(bool value) { mPlotEnabled5 = value; }

    void mPlotSet6(bool value) { mPlotEnabled6 = value; }
    void mPlotSet7(bool value) { mPlotEnabled7 = value; }
    void mPlotSet8(bool value) { mPlotEnabled8 = value; }
    void mPlotSet9(bool value) { mPlotEnabled9 = value; }
    void mPlotSet10(bool value) { mPlotEnabled10 = value; }

    void mPlotSet11(bool value) { mPlotEnabled11 = value; }
    void mPlotSet12(bool value) { mPlotEnabled12 = value; }
    void mPlotSet13(bool value) { mPlotEnabled13 = value; }
    void mPlotSet14(bool value) { mPlotEnabled14 = value; }
    void mPlotSet15(bool value) { mPlotEnabled15 = value; }

signals:
    void cColor1Changed(QColor color);
    void cColor2Changed(QColor color);
    void cColor3Changed(QColor color);
    void cColor4Changed(QColor color);
    void cColor5Changed(QColor color);

    void cColor6Changed(QColor color);
    void cColor7Changed(QColor color);
    void cColor8Changed(QColor color);
    void cColor9Changed(QColor color);
    void cColor10Changed(QColor color);

    void cColor11Changed(QColor color);
    void cColor12Changed(QColor color);
    void cColor13Changed(QColor color);
    void cColor14Changed(QColor color);
    void cColor15Changed(QColor color);

private:
    QCustomPlot* mPlot;
    QTimer dataTimer;
    int yAxisLowerRange;
    int yAxisUpperRange;
    int xAxisSpeed;
    int xAxisTicks;

    QColor ccolor1;
    QColor ccolor2;
    QColor ccolor3;
    QColor ccolor4;
    QColor ccolor5;
    QColor ccolor6;
    QColor ccolor7;
    QColor ccolor8;
    QColor ccolor9;
    QColor ccolor10;
    QColor ccolor11;
    QColor ccolor12;
    QColor ccolor13;
    QColor ccolor14;
    QColor ccolor15;

    bool mPlotEnabled1;
    bool mPlotEnabled2;
    bool mPlotEnabled3;
    bool mPlotEnabled4;
    bool mPlotEnabled5;
    bool mPlotEnabled6;
    bool mPlotEnabled7;
    bool mPlotEnabled8;
    bool mPlotEnabled9;
    bool mPlotEnabled10;
    bool mPlotEnabled11;
    bool mPlotEnabled12;
    bool mPlotEnabled13;
    bool mPlotEnabled14;
    bool mPlotEnabled15;

};

#endif // CHARTTABPAGE_HPP
