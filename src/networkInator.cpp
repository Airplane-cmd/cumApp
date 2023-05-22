#include "networkInator.hpp"
#include <QNetworkRequest>
#include <QList>
NetworkInator::NetworkInator(QObject *parent) : QObject(parent)
{
	m_movementActive_f = 0;
//	m_manager_ptr = new QNetworkAccessManager();
	m_manager_ptr = std::make_shared<QNetworkAccessManager>();
	m_movementTimer_ptr = std::make_shared<QTimer>();
//	m_auth_ptr = std::make_shared<QAuthenticator>();
	connect(m_movementTimer_ptr.get(), &QTimer::timeout, this, &NetworkInator::s_stopMovement);
	connect(this, &NetworkInator::sig_sendRequest, this, &NetworkInator::s_sendRequest);
	m_authStrings_arr[0].first = "Digest realm";
	m_authStrings_arr[1].first = "nonce";
}
NetworkInator::~NetworkInator()
{
	delete m_reply_ptr;
}
void NetworkInator::s_connectToIp(const std::array<QString, 3> &data)
{
	m_ip_qstr = data[0];
	m_login_qstr = data[1];
	m_password_qstr = data[2];
	
	qDebug() << "cam data was set in networInator\n"; //db


	qDebug() << "header was inited\n";	
	for(uint8_t i = 0; i < 16; ++i)
	{
		m_commands_arr[i] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=0&button=%2").arg(m_ip_qstr).arg(i));
	}
	qDebug() << "first loop\n";
	uint8_t ctr = 0;
	for(uint8_t i = 0; i < 6; ++i)
	{
		for(uint8_t j = 0; j < 2; ++j)
		{
				
			m_commands_arr[16 + ctr++] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=%2&button=%3").arg(m_ip_qstr).arg(j + 1).arg(i + 1));
			qDebug() << ctr << '\n';
		}
	}
	qDebug() << "second loop\n";

	m_commands_arr[28] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=0&button=28").arg(m_ip_qstr));
	for(uint8_t i = 29; i < 32; ++i)
	{
		m_commands_arr[i] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=0&button=%2").arg(m_ip_qstr).arg(i + 21));
	}
	qDebug() << "third loop\n";

	int8_t shift = -1;
	for(uint8_t i = 32; i < 45; ++i)
	{
		m_commands_arr[i] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=0&button=%2").arg(m_ip_qstr).arg(i + shift));
		if(i == 35)	shift = 0;
		if(i == 42)	shift = 2;
		qDebug() << i << '\n';
	}
	for(uint8_t i = 45; i < 50; ++i)
	{
		m_commands_arr[i] = std::make_shared<QUrl>(QString("http://%1/cgi-bin/qcs_webcgi.cgi?cgipage=cgi_ctrl2&kind=0&button=%2").arg(m_ip_qstr).arg(i));
	}

	qDebug() << "forth loop\n";
	m_connected_f = 1;
	for(std::shared_ptr<QUrl> it : m_commands_arr)
	{
//		qDebug() << it->toString() << '\n';
	}
	connect(m_manager_ptr.get(), &QNetworkAccessManager::authenticationRequired, [&](QNetworkReply*,QAuthenticator*authenticator){
        authenticator->setUser(m_login_qstr.toUtf8());
        authenticator->setPassword(m_password_qstr.toUtf8());  // Set the password
    });
	qDebug() << "connected to new cam\n";
}
void NetworkInator::s_sendRequest(uint8_t commandIndex)
{
	m_relized_f = 0;
	if(commandIndex > 0) --commandIndex;
	if(commandIndex > 3) --commandIndex;
//	switch(commandIndex)
//	{
//		case(47):
//			commandIndex = 14;
//			break;
//	}
	if(commandIndex >= 4 && commandIndex <= 13)// || (commandIndex ))	
	{
		m_movementActive_f = 1;
		if(m_relized_f)
		{
			m_movementTimer_ptr->start(2000);
		}
	}
	if(m_connected_f && commandIndex < m_commands_arr.size() && m_commands_arr[commandIndex])
	{
		m_uri_qstr = m_commands_arr[commandIndex]->toString().mid(20, m_commands_arr[commandIndex]->toString().size() - 1);
		if(m_gotAuthData_f && m_md5_f)
		{
//			m_header_ptr = QByteArray(QString("Digest username=\"%1\", realm=\"%2\", nonce=\"%3\", uri=\"%4\", algorithm=\"MD5\", response=\"%5\"").arg(m_login_qstr).arg(m_authStrings_arr[0].second).arg(m_authStrings_arr[1].second).arg(m_uri_qstr).arg(m_response_qstr).toUtf8());
		
		}
		qDebug() << m_header_ptr << '\n';
		qDebug() << m_commands_arr[commandIndex]->toString() << '\n';
		qDebug() << "index: " << commandIndex << '\n';
		if(!m_commands_arr[commandIndex])	qDebug() << "please, die already\n";
		QNetworkRequest request(*m_commands_arr[commandIndex]);
		qDebug() << "request created\n";
		request.setRawHeader("Authorization", m_header_ptr);
		qDebug() << "header was set\n";
		m_reply_ptr = m_manager_ptr->get(request);
		qDebug() << "reques was sent\n";
		connect(m_reply_ptr, &QNetworkReply::finished, this, &NetworkInator::s_handleReply);
		qDebug() << "connection on rply slot was maden\n";
	}
}
void NetworkInator::s_handleReply()
{
	m_dataReply_ptr = std::make_shared<QByteArray>(m_reply_ptr->readAll());
	QList<QByteArray> headerList = m_reply_ptr->rawHeaderList();
	
	for(std::pair<QString, QString>& it : m_authStrings_arr)	m_gotAuthData_f = (m_setAuthString(it, headerList) == 0)?1:0;
	m_response_qstr = QString(m_calculateResponse().toHex());
	for(const QByteArray &header : headerList)
	{
		qDebug() << "Header: " << header << ", Value:" << m_reply_ptr->rawHeader(header);
	}
	qDebug() << *m_dataReply_ptr << '\n';
	emit sig_receivedData(*m_dataReply_ptr);
	m_reply_ptr->deleteLater();
}
int NetworkInator::m_setAuthString(std::pair<QString, QString> &value, QList<QByteArray> &list)
{
	qDebug() << "list size = " << list.size() << '\n';
	for(const QByteArray& header : list)
	{
		QString header_qstr(m_reply_ptr->rawHeader(header));
		qDebug() << "Header to search: " << header_qstr << '\n';
		int index = header_qstr.indexOf(value.first);
		if(index == -1)
		{
			qDebug() << "not found " << value.first << '\n';
//			if(&header == list.end())	return -1; 
			continue;
		}
		else
		{
			int startIndex = index + value.first.length() + 2;
			int endIndex = header_qstr.indexOf('"', startIndex);
			if(endIndex != -1)
			{
				value.second = header_qstr.mid(startIndex, endIndex - startIndex);
				qDebug() << value.first << ": " << value.second << '\n';
			}
			else
			{
				qDebug() << "End qutation mark couldn't be found\n";
				break;
			}
		}
		return 0;
	}
}
QByteArray NetworkInator::m_MD5(QString &str)
{
	QCryptographicHash hash(QCryptographicHash::Md5);
	hash.addData(str.toUtf8());//convert 
	return hash.result();
}
QByteArray NetworkInator::m_calculateResponse()
{
	QString HA1_qstr = m_login_qstr + ':' + m_authStrings_arr[0].second + ':' + m_password_qstr;
	QString HA2_qstr = QString("GET") + ':' + m_uri_qstr;
	qDebug() << "HA1: " << HA1_qstr << '\n';
	qDebug() << "HA2: " << HA2_qstr << '\n';

	m_md5_f = 1;
	QString response_qstr = QString(m_MD5(HA1_qstr).toHex()) + ':' + m_authStrings_arr[1].second + ":auth:" + QString(m_MD5(HA2_qstr).toHex());
	qDebug() << response_qstr << '\n';
	return m_MD5(response_qstr); 
}
void NetworkInator::s_stopMovement()
{
	if(m_movementActive_f)
	{
		m_movementTimer_ptr->stop();
		uint block = 0;
		if(m_lastReleased >= 8 && m_lastReleased <= 11) block = 49;
		if(m_lastReleased >= 12 && m_lastReleased <= 13) block = 50;
		if(m_lastReleased >= 14 && m_lastReleased <= 15) block = 51;


		emit sig_sendRequest(block);
		m_movementActive_f = 0;
	}
}
void NetworkInator::s_release(uint id)//to hendle release event
{
	m_relized_f = 1;
	qDebug() << "Released\n";
	m_movementTimer_ptr->start(500);
	m_lastReleased = id;
//	emit sig_sendRequest(49);

}
