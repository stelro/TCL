#include "titlebar.hpp"
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>

TitleBar::TitleBar(QWidget *parent)
    : mParent(parent)
{
    this->setStyleSheet("background-color: #595656");
    QLabel *label = new QLabel( parent->windowTitle() );


    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( label, 1, Qt::AlignLeft );
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        mParent->move(mParent->pos() + (event->pos() - mLastMousePosition));
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
