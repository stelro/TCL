/*
 * Copyright (C) 2016
 * Author: Stelmach Rostislav <stelmach.ro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TURBINEWIDGET_HPP
#define TURBINEWIDGET_HPP

#include "qcgaugewidget.hpp"

class TurbineWidget : public QcGaugeWidget
{
public:
    TurbineWidget(QWidget *parent = 0);
    ~TurbineWidget();
    void setValue(int value);
    QcNeedleItem* getNeedle() const { return mNeedle; }

private:
    QcNeedleItem *mNeedle;
};

#endif // TURBINEWIDGET_HPP
