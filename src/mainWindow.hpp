#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
//#include <QStringStream>
#include <QKeyEvent>
#include <QAction>
#include <QToolBar>
#include <QMenu>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>

#include <memory>
#include <array>
#include <vector>

#include "addIP.hpp"
#include "usbInator.hpp"
#include "networkInator.hpp"
#include "pushButton.hpp"
class MainWindow : public QWidget
{
Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
protected:

private:
//	std::shared_ptr<QLabel> m_label_ptr;
	std::array<std::shared_ptr<QHBoxLayout>, 9> m_hbox_ptr_arr;
	std::array<std::shared_ptr<QVBoxLayout>, 20> m_vbox_ptr_arr;
	std::array<std::shared_ptr<QLabel>, 20> m_labels_ptr_arr;
	std::array<std::shared_ptr<PushButton>, 49> m_bttns_ptr_arr;
	std::shared_ptr<QListWidget> m_listWidget_ptr;
	std::shared_ptr<QGridLayout> m_controlGrid_ptr;
	std::shared_ptr<AddCam> m_addWdgt_ptr;
	std::shared_ptr<QMainWindow> m_mainWndw_ptr;
	std::vector<std::array<QString, 3>> m_camsData_vctr;
	std::shared_ptr<QListWidgetItem> m_item; 
	std::shared_ptr<UsbInator> m_joystic_interface;
	std::array<bool, 16> m_joystickData_arr;
//	std::shared_ptr<NetworkInator> m_networkHandler_ptr;
	NetworkInator m_networkHandler_ptr;
public slots:
	void s_onAddApply(const std::array<QString, 3>&);
	void s_onCancel();
	void s_onAdd();
	void s_onRemove();

	void s_onItemActivated(QListWidgetItem *);
	void s_onTurnOn();
	void s_onTurnOff();
	void s_sendRequest(int);

	void s_processJoystickData(std::array<bool, 16> &data);
signals:
	void sig_setCamData(const std::array<QString, 3>&);
	void sig_sendRequest(int);
	void sig_buttonReleased();
	void sig_release(uint8_t);
	
};
#endif
