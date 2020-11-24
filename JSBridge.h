#ifndef JSBRIDGE_H
#define JSBRIDGE_H

#include <QObject>
#include <QMessageBox>
#include <QWebView>
#include <QtWebKitWidgets>

class JSBridge : public QObject
{
	Q_OBJECT

	private:
		QWebView *_view;
		bool _debug;

	private slots:
		void _finishLoading(bool);
		void _report(QNetworkReply*reply);

	public slots:
		void messageBox(const QString &message);
		void resize(int width, int height);
		void setFixedSize(int width, int height);
		void show();
		void close();
		QString pos();
		void maximize();
		void move(int x, int y);
		void newWindow(const QString &url);
		void openUrl(const QString &url);

	 public:
		explicit JSBridge(bool = false);
};

#endif