#include <QDebug>
#include "usbInator.hpp"
UsbInator::UsbInator(QObject *parent) : QObject(parent)
{
    // connect the readData() slot to the readyRead() signal of the serial port
    connect(&m_serialPort, &QSerialPort::readyRead, this, &UsbInator::readData);
    openPort("/dev/ttyUSB0");
    m_counter = 0;
}

UsbInator::~UsbInator()
{
    // close the serial port if it's still open
    if (m_serialPort.isOpen()) {
        m_serialPort.close();
    }
}

void UsbInator::openPort(const QString &portName)
{
    // if the serial port is already open, close it first
    if (m_serialPort.isOpen()) {
        m_serialPort.close();
    }

    // set the parameters of the serial port
    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(QSerialPort::Baud2400);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setStopBits(QSerialPort::OneStop);

    // open the serial port in read-only mode
    if (m_serialPort.open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port" << portName << "opened successfully\n";
    } else {
        qDebug() << "Failed to open serial port" << portName << ":" << m_serialPort.errorString() << '\n';
    }
}

void UsbInator::closePort()
{
    // close the serial port if it's still open
    if (m_serialPort.isOpen()) {
        m_serialPort.close();
    }
}
std::array<bool, 8> UsbInator::m_parseCommand(uint8_t data)
{
	std::array<bool, 8> arr;
	for(uint8_t i = 0; i < 8; ++i)
	{
		arr[i] = (data & (1 << i)) >> i;
	}
	return arr;

}
void UsbInator::m_printCommand(std::array<bool, 8> &command)
{
	for(bool it : command)	qDebug() << it << ' ';
}
void UsbInator::readData()
{
    // read data from the serial port and emit the dataReceived() signal
    	m_data_vctr.clear();
	QByteArray data = m_serialPort.readAll();
	for(auto it : data)
	{
		if(uint8_t(it) == 0xff)	m_counter = 0;
		m_data_vctr.push_back(uint8_t(it));
//		qDebug() << Qt::hex << uint8_t(it);		
	}
	for(uint8_t it : m_data_vctr)
	{	
//		qDebug() << Qt::hex << m_counter << ": " << it;// << " != " << uint8_t0xffff;
		switch(m_counter)
		{
			case(1):
				qDebug() << "Camera Address: " << it << '\n';
				break;
			case(2):
				m_firstCommand = m_parseCommand(it);
				qDebug() << "Command 1: ";
				m_printCommand(m_firstCommand);
				qDebug() << '\n';
				break;
			case(3):
				m_secondCommand = m_parseCommand(it);
				qDebug() << "Command 2: ";
				m_printCommand(m_secondCommand);
				qDebug() << '\n';
				break;
			case(4):
				qDebug() << "Pan speed: " << it	<< '\n';
				break;
			case(5):
				qDebug() << "Tilt speed: " << it << '\n';
				break;
		}
		++m_counter;

		if(m_counter == 7)
		{
//			m_counter = 0;
			qDebug() << '\n';
		}
	}
//	qDebug() << '\n';
	std::array<bool, 16> arr;
	for(uint8_t i = 0; i < 16; ++i)
	{
		if(i < 8)	arr[i] = m_firstCommand[i];
		else 		arr[i] = m_secondCommand[i - 8];
	}

	    emit dataReceived(arr);
}
