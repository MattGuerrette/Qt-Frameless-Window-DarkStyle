/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#include <QStyleOption>
#include <QPainter>
#include "windowdragger.h"

WindowDragger::WindowDragger(QWidget *parent): QWidget(parent)
{
  mousePressed = false;
    setMouseTracking(true);
}

void WindowDragger::mousePressEvent(QMouseEvent *event)
{
  mousePressed = true;
  mousePos = event->globalPos();

  QWidget *parent = parentWidget();
  if (parent)
    parent = parent->parentWidget();

  if (parent)
    wndPos = parent->pos();

  m_nMouseClick_X_Coordinate = event->x();
  m_nMouseClick_Y_Coordinate = event->y();

  QWidget::mousePressEvent(event);
}

void WindowDragger::mouseMoveEvent(QMouseEvent *event)
{
  QWidget *parent = parentWidget();
  if (parent)
    parent = parent->parentWidget();

  if (parent && mousePressed) {
    parent->move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
      //parent->move(wndPos + (event->globalPos() - mousePos));
  }

  QWidget::mouseMoveEvent(event);
}

void WindowDragger::mouseReleaseEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  mousePressed = false;
}

void WindowDragger::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QWidget::paintEvent(event);
//  QStyleOption styleOption;
//  styleOption.init(this);
//  QPainter painter(this);
//  style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
}

void WindowDragger::mouseDoubleClickEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  emit doubleClicked();
}

