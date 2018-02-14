

#ifndef THUMBBUTTON_H
#define THUMBBUTTON_H

#include <QToolButton>

class ThumbButton : public QToolButton
{
    Q_OBJECT
public:
    ThumbButton( QWidget *parent );

protected:
    void paintEvent( QPaintEvent* );
};

#endif // THUMBBUTTON_H
