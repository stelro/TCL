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

#include "turbinewidget.hpp"

TurbineWidget::TurbineWidget(QWidget *parent)
    : QcGaugeWidget(parent)
{
    addBackground(20);
    QcBackgroundItem *bkg1 = addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,QColor(182,181,176));
    bkg1->addColor(1.0,QColor(182,181,176));

    QcBackgroundItem *bkg2 = addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,QColor(50,78,92));
    bkg2->addColor(1.0,QColor(83,105,118));

    //the dots values , not the numbers
    addArc(55);
    addDegrees(65)->setValueRange(0,10);
    addColorBand(50);

    addValues(80)->setValueRange(0,10);

    addLabel(70)->setText("RPM");
    QcLabelItem *lab = addLabel(40);
    lab->setText("0");

    //Needle height
    mNeedle = addNeedle(60);
    mNeedle->setLabel(lab);
    mNeedle->setColor(QColor(249,89,75));
    mNeedle->setValueRange(0,10000);
    addBackground(7);
}

TurbineWidget::~TurbineWidget()
{
    //Empty
}

void TurbineWidget::setValue(int value)
{
    mNeedle->setCurrentValue(value);
}
