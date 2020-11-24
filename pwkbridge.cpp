
#include <QApplication>
#include <QWidget>
#include <QtWebKitWidgets>

#include "JSBridge.h"

int main(int argc, char *argv[])
{
	
	QApplication app(argc, argv);

	// get config
	QSettings my_settings("config.ini", QSettings::IniFormat);
	QString config_url = my_settings.value("url", "").toString();
	bool config_debug = my_settings.value("debug", "").toBool();
	QString config_icon = my_settings.value("icon", "").toString();

	// set icon
	app.setWindowIcon(QIcon(config_icon));


	// run webkit
	JSBridge *jsBridge_ = new JSBridge(config_debug);
	jsBridge_->openUrl(config_url);
	
	return app.exec();
}
