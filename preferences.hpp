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

private:
    Preferences();
    ~Preferences();

    QSettings*              mSettings;
    static Preferences*     mInstance;

    /* Cahce Variables */

    typedef std::map<QString, QString> mStringCacheContainer;
    typedef mStringCacheContainer::iterator mStringCahceContainerIter;
    mStringCacheContainer mStringCache;

};

#endif // PREFERENCES_HPP
