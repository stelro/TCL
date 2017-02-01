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


void Preferences::deleteInstance()
{
    if (mInstance) {
        delete mInstance;
        mInstance = nullptr;
    }
}

Preferences::Preferences()
    : mSettings(new QSettings(this))
{

}

Preferences::~Preferences() {
    //Empty
}
