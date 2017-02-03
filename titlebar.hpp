#ifndef TITLEBAR_HPP
#define TITLEBAR_HPP

#include <QWidget>
#include <QPoint>

class TitleBar : public QWidget
{
public:
    TitleBar(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);


private:
    QWidget *mParent;
    QPoint mCursor;
    QPoint mLastMousePosition;
        bool mMoving;
};

#endif // TITLEBAR_HPP
