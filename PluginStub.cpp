/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2011, Dominik Schmidt <domme@tomahawk-player.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#include "PluginStub.h"

#include <utils/Logger.h>

Tomahawk::InfoSystem::StubPlugin::StubPlugin()
{
    tDebug() << Q_FUNC_INFO;
}


Tomahawk::InfoSystem::StubPlugin::~StubPlugin()
{
    tDebug() << Q_FUNC_INFO;
}


#include <ViewPage.h>
#include <ViewManager.h>
#include <QLabel>

class StubWidget : public Tomahawk::ViewPage
{
public:
    StubWidget(QObject* parent)
//         : ViewPage(parent)
    {
        m_widget = (QWidget*) (new QLabel("Plugin Foobar"));
    }

    virtual QWidget* widget() { return m_widget; }
    virtual Tomahawk::playlistinterface_ptr playlistInterface() const { return Tomahawk::playlistinterface_ptr(); }
    virtual QString title() const { return QString("Great title from Plugin"); }
    virtual QString description() const { return QString("Great description from Plugin"); }
    virtual bool jumpToCurrentTrack() { return false; }

private:
    QWidget* m_widget;
};

void
Tomahawk::InfoSystem::StubPlugin::init()
{
    tDebug() << Q_FUNC_INFO;
    QMetaObject::invokeMethod( ViewManager::instance(), "addDynamicPage", Qt::QueuedConnection, Q_ARG( QString, "pluginStubPage" ), Q_ARG( ViewPage*, new StubWidget( 0 ) ) );
}


void
Tomahawk::InfoSystem::StubPlugin::getInfo( Tomahawk::InfoSystem::InfoRequestData requestData )
{
    tDebug() << Q_FUNC_INFO;
}


void
Tomahawk::InfoSystem::StubPlugin::notInCacheSlot( Tomahawk::InfoSystem::InfoStringHash criteria, Tomahawk::InfoSystem::InfoRequestData requestData )
{
    tDebug() << Q_FUNC_INFO;
}


void
Tomahawk::InfoSystem::StubPlugin::pushInfo( Tomahawk::InfoSystem::InfoPushData pushData )
{
    tDebug() << Q_FUNC_INFO;
}


Q_EXPORT_PLUGIN2( Tomahawk::InfoSystem::InfoPlugin, Tomahawk::InfoSystem::StubPlugin )
