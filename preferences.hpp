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

#ifndef PREFERENCES_HPP
#define PREFERENCES_HPP

#include <QDebug>
#include <QSettings>
#include <map>

class Preferences : public QObject
{
    Q_OBJECT
public:
    static Preferences *instance();
    static void deleteInstance();

    QSettings *settings() const { return mSettings; }

    /* Cache Operations */

    QString cacheLookup(const QString& key);
    void cacheStore(const QString& key, const QString& value);
    void cacheRemove(const QString& value);
    void cacheRemoveAll();

    QString turbineName1() const { return mTurbineName1; }
    QString turbineName2() const { return mTurbineName2; }
    QString turbineName3() const { return mTurbineName3; }
    QString turbineName4() const { return mTurbineName4; }
    QString turbineName5() const { return mTurbineName5; }

public slots:
    void setTurbineName1(QString name);
    void setTurbineName2(QString name);
    void setTurbineName3(QString name);
    void setTurbineName4(QString name);
    void setTurbineName5(QString name);

signals:
    void turbineName1Changed(QString name);
    void turbineName2Changed(QString name);
    void turbineName3Changed(QString name);
    void turbineName4Changed(QString name);
    void turbineName5Changed(QString name);


private:
    Preferences();
    ~Preferences();

    QSettings*              mSettings;
    static Preferences*     mInstance;

    QString mTurbineName1;
    QString mTurbineName2;
    QString mTurbineName3;
    QString mTurbineName4;
    QString mTurbineName5;

    /* Cahce Variables */

    typedef std::map<QString, QString> mStringCacheContainer;
    typedef mStringCacheContainer::iterator mStringCahceContainerIter;
    mStringCacheContainer mStringCache;

};

#endif // PREFERENCES_HPP
