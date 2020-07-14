
#include "JSBridge.h"

JSBridge::JSBridge(bool debug)
{
	JSBridge::_debug = debug;

	JSBridge::_view = new QWebView();

	JSBridge::_view->resize(300, 200);
	
	QObject::connect(JSBridge::_view, SIGNAL(loadFinished(bool)), SLOT(_finishLoading(bool)));

	if(JSBridge::_debug) {
		JSBridge::_view->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
	}

	// view->setWindowFlags(Qt::Drawer);
}

void JSBridge::_finishLoading(bool)
{
	JSBridge::_view->page()->mainFrame()->addToJavaScriptWindowObject("PWKBridge", this);
}

void JSBridge::messageBox(const QString &message)
{
	QMessageBox msgBox;
	msgBox.setText(message);
	msgBox.exec();
}

void JSBridge::resize(int width, int height)
{
	JSBridge::_view->resize(width, height);
}

void JSBridge::setFixedSize(int width, int height)
{
	JSBridge::_view->setFixedSize(width, height);
}

void JSBridge::show()
{
	JSBridge::_view->show();
}

void JSBridge::close()
{
	JSBridge::_view->close();
}

void JSBridge::newWindow(const QString &url)
{
	JSBridge *jsBridge_ = new JSBridge(JSBridge::_debug);

	jsBridge_->openUrl(url);
}

void JSBridge::openUrl(const QString &url) 
{
	JSBridge::_view->setUrl(QUrl::fromUserInput(url));
}