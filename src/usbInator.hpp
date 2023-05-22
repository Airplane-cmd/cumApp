#ifndef USBINATOR_HPP
#define USBINATOR_HPP

#include <QSerialPort>
#include <QObject>
#include <QByteArray>

#include <array>

class UsbInator : public QObject
{
Q_OBJECT

public:
    explicit UsbInator(QObject *parent = 0);
    virtual ~UsbInator();

    void openPort(const QString &portName);
    void closePort();


private:
	QSerialPort m_serialPort;
    	std::vector<int8_t> m_data_vctr;
	std::array<bool, 8> m_firstCommand;
	std::array<bool, 8> m_secondCommand;
	uint8_t m_counter;

    	std::array<bool, 8> m_parseCommand(uint8_t);
	void m_printCommand(std::array<bool, 8> &command);

signals:
    	void dataReceived(std::array<bool, 16> &data);
	void leftMove();
private slots:
    void readData();

};

#endif
