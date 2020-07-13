
#include <QApplication>
#include <QWidget>
#include <QtWebKitWidgets>

#include "JSBridge.h"

int main(int argc, char *argv[])
{
	
	QApplication app(argc, argv);

	JSBridge *jsBridge_ = new JSBridge(true);
	jsBridge_->openUrl("file:///home/scorninpc/Desktop/Bruno/pwkbridge/qt/autobackup.html");
	
	return app.exec();
}
