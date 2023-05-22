#ifndef NETWORKINATOR_HPP
#define NETWORKINATOR_HPP
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QString>
#include <QObject>
#include <QByteArray>
#include <QAuthenticator>
#include <QList>
#include <array>
#include <memory>
#include <utility>
#include <QTimer>
class NetworkInator : public QObject
{
Q_OBJECT
public:
	explicit NetworkInator(QObject *parent = 0);
	virtual ~NetworkInator();
private:
	bool m_connected_f;
	bool m_gotAuthData_f;
	bool m_md5_f;
	bool m_movementActive_f;
	bool m_relized_f;
	int m_lastReleased;
	QString m_ip_qstr;
	QString m_login_qstr;
	QString m_password_qstr;
	QString m_uri_qstr;
	QString m_response_qstr;
	std::shared_ptr<QTimer> m_movementTimer_ptr;
//	QString m_nonce_qstr;
	QByteArray m_header_ptr;
	std::array<std::shared_ptr<QUrl>, 50> m_commands_arr;
	std::array<std::pair<QString, QString>, 2> m_authStrings_arr;
//	std::array<QString, 2> m_authVal
	std::shared_ptr<QNetworkAccessManager> m_manager_ptr;
//	std::shared_ptr<QAuthenticator> m_auth_ptr;
//	QNetworkAccessManager m_manager_ptr;
//	QNetworkAccessManager *m_manager_ptr;
//	std::shared_ptr<QNetworkReply> m_reply_ptr;
	QNetworkReply *m_reply_ptr;
	std::shared_ptr<QByteArray> m_dataReply_ptr;
	QByteArray m_MD5(QString&);
	QByteArray m_calculateResponse();
	int m_setAuthString(std::pair<QString, QString>&, QList<QByteArray> &);

//	QNetworkRequest m_request;
	
public slots:
	void s_sendRequest(uint8_t);
//	void s_sendCommand();
	void s_connectToIp(const std::array<QString, 3>&);
	void s_handleReply();
	void s_release(uint);
private slots:
	void s_stopMovement();

//	QByteArray m_MD5(QString&);

signals:
	void sig_receivedData(QByteArray&);
	void sig_stopMovement();
	void sig_sendRequest(uint8_t);
};	

	
#endif

