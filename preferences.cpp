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

#include "preferences.hpp"

Preferences *Preferences::mInstance;

Preferences* Preferences::instance() {

    if ( !mInstance )
        mInstance = new Preferences;
    return mInstance;
}

QString Preferences::cacheLookup(const QString &key)
{
    auto it = mStringCache.find(key);
    if (it != mStringCache.end()) {
        return it->second;
    }

    return QString("");
}

void Preferences::cacheStore(const QString &key, const QString& value)
{
    if (key == "")
        return ;
    mStringCache[key] = value;
}

void Preferences::cacheRemove(const QString &value)
{
    auto it = mStringCache.begin();
    while ( it != mStringCache.end()) {
        if (it->second == value)
            break;
        ++it;
    }

    if (it != mStringCache.end()) {
        mStringCache.erase(it);
    }
}

void Preferences::cacheRemoveAll()
{
    auto it = mStringCache.begin();
    while (it != mStringCache.end()) {
        cacheRemove(it->second);
        it = mStringCache.begin();
    }
}

void Preferences::setTurbineName1(QString name)
{
    mTurbineName1 = name;
    emit turbineName1Changed(name);
}

void Preferences::setTurbineName2(QString name)
{
    mTurbineName2 = name;
    emit turbineName2Changed(name);
}

void Preferences::setTurbineName3(QString name)
{
    mTurbineName3 = name;
    emit turbineName3Changed(name);
}

void Preferences::setTurbineName4(QString name)
{
    mTurbineName4 = name;
    emit turbineName4Changed(name);
}

void Preferences::setTurbineName5(QString name)
{
    mTurbineName5 = name;
    emit turbineName5Changed(name);
}


void Preferences::deleteInstance()
{
    if (mInstance) {
        delete mInstance;
        mInstance = nullptr;
    }
}

Preferences::Preferences()
    : mSettings(new QSettings(this))
    , mTurbineName1("TURBINE 1")
    , mTurbineName2("TURBINE 2")
    , mTurbineName3("TURBINE 3")
    , mTurbineName4("TURBINE 4")
    , mTurbineName5("TURBINE 5")
{

}

Preferences::~Preferences() {
    //Empty
}
