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
