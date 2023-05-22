#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QAction>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <memory>

#include "mainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
	//init
	std::shared_ptr<QHBoxLayout> mainHLayout = std::make_shared<QHBoxLayout>(this);
	std::shared_ptr<QHBoxLayout> upperHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> middleHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> lowerHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> micHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> presetUpperHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> presetLowerHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> whiteBalanceHLayout = std::make_shared<QHBoxLayout>();
	std::shared_ptr<QHBoxLayout> abjHLayout = std::make_shared<QHBoxLayout>();

	std::shared_ptr<QVBoxLayout> leftVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> rightVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> displayControlVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> micVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> volumeVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> zoomVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> focusVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> distanceVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> distanceAnotherVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> presetVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> whiteBalanceVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> rgainVLayout = std::make_shared<QVBoxLayout>();
 	std::shared_ptr<QVBoxLayout> bgainVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> abjVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> backlightVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> brightnessVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> presentationVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> videoVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> recordingVLayout = std::make_shared<QVBoxLayout>();
	std::shared_ptr<QVBoxLayout> turnVLayout = std::make_shared<QVBoxLayout>();

	std::shared_ptr<PushButton> turn = std::make_shared<PushButton>("On");
	std::shared_ptr<PushButton> turnOff = std::make_shared<PushButton>("Off");
	std::shared_ptr<PushButton> layout = std::make_shared<PushButton>("Layout");
	std::shared_ptr<PushButton> picture = std::make_shared<PushButton>("P in P");
	std::shared_ptr<PushButton> turnMic = std::make_shared<PushButton>("On");
	std::shared_ptr<PushButton> turnMicOff = std::make_shared<PushButton>("Off");
	std::shared_ptr<PushButton> volumeP = std::make_shared<PushButton>("+");
	std::shared_ptr<PushButton> volumeM = std::make_shared<PushButton>("-");
	std::shared_ptr<PushButton> arrowL = std::make_shared<PushButton>("←");
	std::shared_ptr<PushButton> arrowU = std::make_shared<PushButton>("↑");
	std::shared_ptr<PushButton> arrowR = std::make_shared<PushButton>("→");
	std::shared_ptr<PushButton> arrowD = std::make_shared<PushButton>("↓");
	std::shared_ptr<PushButton> zoomT = std::make_shared<PushButton>("T");
	std::shared_ptr<PushButton> zoomW = std::make_shared<PushButton>("W");
	std::shared_ptr<PushButton> focusP = std::make_shared<PushButton>("+");
	std::shared_ptr<PushButton> focusM = std::make_shared<PushButton>("-");
	std::shared_ptr<PushButton> far = std::make_shared<PushButton>("Far");
	std::shared_ptr<PushButton> near = std::make_shared<PushButton>("Near");
	std::array<std::array<std::shared_ptr<PushButton>, 6>, 2> nums;
	for(uint8_t i = 0; i < 2; ++i)	for(uint8_t j = 0; j < 6; ++j)	nums[i][j] = std::make_shared<PushButton>(QString::number(j + 1));
	std::shared_ptr<PushButton> auto_ = std::make_shared<PushButton>("Auto");
	std::shared_ptr<PushButton> indoor = std::make_shared<PushButton>("Indoor");
	std::shared_ptr<PushButton> outdoor = std::make_shared<PushButton>("Outdoor");
	std::shared_ptr<PushButton> push = std::make_shared<PushButton>("One Push");
	std::shared_ptr<PushButton> rgainP = std::make_shared<PushButton>("+");
	std::shared_ptr<PushButton> rgainM = std::make_shared<PushButton>("-");
	std::shared_ptr<PushButton> bgainP = std::make_shared<PushButton>("+");
	std::shared_ptr<PushButton> bgainM = std::make_shared<PushButton>("-");
	std::shared_ptr<PushButton> turnBacklight = std::make_shared<PushButton>("On");
	std::shared_ptr<PushButton> turnBacklightOff = std::make_shared<PushButton>("Off");
	std::shared_ptr<PushButton> brightnessP = std::make_shared<PushButton>("+");
	std::shared_ptr<PushButton> brightnessM = std::make_shared<PushButton>("-");
	std::shared_ptr<PushButton> turnPresentation = std::make_shared<PushButton>("Start");
	std::shared_ptr<PushButton> turnPresentationOff = std::make_shared<PushButton>("Stop");
	std::shared_ptr<PushButton> input = std::make_shared<PushButton>("Input");
	std::shared_ptr<PushButton> turnRecording = std::make_shared<PushButton>("Start");
	std::shared_ptr<PushButton> turnRecordingOff = std::make_shared<PushButton>("Stop");
	std::shared_ptr<PushButton> addCam = std::make_shared<PushButton>("Add IP");
	std::shared_ptr<PushButton> removeCam = std::make_shared<PushButton>("Remove IP");
		

	std::shared_ptr<QLabel> display_l = std::make_shared<QLabel>("Display Control");
	std::shared_ptr<QLabel> mic_l = std::make_shared<QLabel>("Mic");
	std::shared_ptr<QLabel> volume_l = std::make_shared<QLabel>("Volume");
	std::shared_ptr<QLabel> camCtrl_l = std::make_shared<QLabel>("Control");
	std::shared_ptr<QLabel> zoom_l = std::make_shared<QLabel>("Zoom");
	std::shared_ptr<QLabel> focus_l = std::make_shared<QLabel>("Focus");
	std::shared_ptr<QLabel> distance_l = std::make_shared<QLabel>("Far/Near");
	std::shared_ptr<QLabel> preset_l = std::make_shared<QLabel>("Preset");
	std::shared_ptr<QLabel> load_l = std::make_shared<QLabel>("Load");
	std::shared_ptr<QLabel> save_l = std::make_shared<QLabel>("Save");
	std::shared_ptr<QLabel> balance_l = std::make_shared<QLabel>("White Balance");
	std::shared_ptr<QLabel> rgain_l = std::make_shared<QLabel>("R-GAIN");
	std::shared_ptr<QLabel> bgain_l = std::make_shared<QLabel>("B-GAIN");
	std::shared_ptr<QLabel> adj_l = std::make_shared<QLabel>("Near Camera Abjustment");
	std::shared_ptr<QLabel> bcklght_l = std::make_shared<QLabel>("Backlight");
	std::shared_ptr<QLabel> brightness_l = std::make_shared<QLabel>("Brightness");
	std::shared_ptr<QLabel> prsnt_l = std::make_shared<QLabel>("Presentation");
	std::shared_ptr<QLabel> video_l = std::make_shared<QLabel>("Video");
	std::shared_ptr<QLabel> recording_l = std::make_shared<QLabel>("Recording");



	std::shared_ptr<QLabel> displayControlLabel = std::make_shared<QLabel>("must be funny in a richmen world");

	m_controlGrid_ptr = std::make_shared<QGridLayout>();

	m_mainWndw_ptr = std::make_shared<QMainWindow>();
	m_joystic_interface = std::make_shared<UsbInator>();
//	m_networkHandler_ptr = std::make_shared<NetworkInator>();
	m_addWdgt_ptr = std::make_shared<AddCam>();
	m_mainWndw_ptr->setCentralWidget(m_addWdgt_ptr.get());

	m_hbox_ptr_arr = {mainHLayout, upperHLayout, middleHLayout, lowerHLayout, micHLayout, presetUpperHLayout, presetLowerHLayout, whiteBalanceHLayout, abjHLayout};

	m_vbox_ptr_arr = {leftVLayout, rightVLayout, turnVLayout, displayControlVLayout,micVLayout, volumeVLayout, zoomVLayout, focusVLayout, distanceVLayout, distanceAnotherVLayout, presetVLayout, whiteBalanceVLayout, rgainVLayout, bgainVLayout, abjVLayout, backlightVLayout, brightnessVLayout, presentationVLayout, videoVLayout, recordingVLayout};
 
	m_labels_ptr_arr = {display_l, mic_l, volume_l, camCtrl_l, zoom_l, focus_l, distance_l, preset_l, load_l, save_l, balance_l, rgain_l, bgain_l, adj_l, bcklght_l, brightness_l, prsnt_l, video_l, recording_l};

	m_bttns_ptr_arr = {turn, turnOff, layout, picture, turnMic, turnMicOff, volumeP, volumeM, arrowL, arrowU, arrowD, arrowR,  zoomT, zoomW, focusP, focusM, far, near, nums[0][0], nums[1][0], nums[0][1], nums[1][1], nums[0][2], nums[1][2], nums[0][3], nums[1][3], nums[0][4], nums[1][4], nums[0][5], nums[1][5], auto_, indoor, outdoor, push, rgainP, rgainM, bgainP, bgainM, turnBacklight, turnBacklightOff, brightnessP, brightnessM, turnPresentation, turnPresentationOff, input, turnRecording, turnRecordingOff, addCam, removeCam};
	
	m_listWidget_ptr = std::make_shared<QListWidget>();
	
//	m_label_ptr->setText("must be funny in a richmen world");
//	m_hbox_ptr_arr[0]->addWidget(m_labels_ptr_arr[0].get());

//	leftVLayout-
	//create widget
	mainHLayout->addLayout(leftVLayout.get());
	mainHLayout->addLayout(rightVLayout.get());

	leftVLayout->addWidget(m_listWidget_ptr.get());
	leftVLayout->addWidget(addCam.get());
	leftVLayout->addWidget(removeCam.get());

	rightVLayout->addLayout(upperHLayout.get());
	rightVLayout->addLayout(middleHLayout.get());
	rightVLayout->addLayout(lowerHLayout.get());

	upperHLayout->addLayout(turnVLayout.get());
	upperHLayout->addLayout(displayControlVLayout.get());
	upperHLayout->addLayout(micVLayout.get());
	upperHLayout->addLayout(volumeVLayout.get());
	upperHLayout->addLayout(zoomVLayout.get());
	upperHLayout->addLayout(focusVLayout.get());
	upperHLayout->addLayout(distanceAnotherVLayout.get());

	turnVLayout->addWidget(turn.get());
	turnVLayout->addWidget(turnOff.get());

	displayControlVLayout->addWidget(display_l.get());
	displayControlVLayout->addWidget(layout.get());
	displayControlVLayout->addWidget(picture.get());
	
	micVLayout->addWidget(mic_l.get());
	micVLayout->addWidget(turnMic.get());
	micVLayout->addWidget(turnMicOff.get());

	volumeVLayout->addWidget(volume_l.get());
	volumeVLayout->addWidget(volumeP.get());
	volumeVLayout->addWidget(volumeM.get());

	zoomVLayout->addWidget(zoom_l.get());
	zoomVLayout->addWidget(zoomT.get());
	zoomVLayout->addWidget(zoomW.get());

	focusVLayout->addWidget(focus_l.get());
	focusVLayout->addWidget(focusP.get());
	focusVLayout->addWidget(focusM.get());

	middleHLayout->addLayout(distanceVLayout.get());
	middleHLayout->addLayout(presetVLayout.get());
	middleHLayout->addLayout(whiteBalanceVLayout.get());
	middleHLayout->addLayout(rgainVLayout.get());
	middleHLayout->addLayout(bgainVLayout.get());
	
	distanceVLayout->addWidget(distance_l.get());
	distanceVLayout->addWidget(far.get());
	distanceVLayout->addWidget(near.get());

	presetVLayout->addWidget(preset_l.get());
	presetVLayout->addWidget(load_l.get());
	presetVLayout->addLayout(presetUpperHLayout.get());
	presetVLayout->addWidget(save_l.get());
	presetVLayout->addLayout(presetLowerHLayout.get());

	for(uint8_t i = 0; i < 6; ++i)
	{
		for(uint8_t j = 0; j < 2; ++j)
		{
			if(j == 0)	presetUpperHLayout->addWidget(nums[j][i].get());
			else		presetLowerHLayout->addWidget(nums[j][i].get());
		}
	}

	whiteBalanceHLayout->addWidget(balance_l.get());
	whiteBalanceHLayout->addWidget(auto_.get());
	whiteBalanceHLayout->addWidget(indoor.get());
	whiteBalanceHLayout->addWidget(outdoor.get());
	whiteBalanceHLayout->addWidget(push.get());

	rgainVLayout->addWidget(rgain_l.get());
	rgainVLayout->addWidget(rgainP.get());
	rgainVLayout->addWidget(rgainM.get());

	bgainVLayout->addWidget(bgain_l.get());
	bgainVLayout->addWidget(bgainP.get());
	bgainVLayout->addWidget(bgainM.get());

	lowerHLayout->addLayout(abjHLayout.get());
	lowerHLayout->addLayout(presentationVLayout.get());
	lowerHLayout->addLayout(videoVLayout.get());
	lowerHLayout->addLayout(recordingVLayout.get());

	abjHLayout->addLayout(backlightVLayout.get());
	abjHLayout->addLayout(brightnessVLayout.get());

	backlightVLayout->addWidget(bcklght_l.get());
	backlightVLayout->addWidget(turnBacklight.get());
	backlightVLayout->addWidget(turnBacklightOff.get());

	brightnessVLayout->addWidget(brightness_l.get());
	brightnessVLayout->addWidget(brightnessP.get());
	brightnessVLayout->addWidget(brightnessM.get());

	presentationVLayout->addWidget(prsnt_l.get());
	presentationVLayout->addWidget(turnPresentation.get());
	presentationVLayout->addWidget(turnPresentationOff.get());

	videoVLayout->addWidget(video_l.get());
	videoVLayout->addWidget(input.get());

	recordingVLayout->addWidget(recording_l.get());
	recordingVLayout->addWidget(turnRecording.get());
	recordingVLayout->addWidget(turnRecordingOff.get());

	distanceAnotherVLayout->addWidget(camCtrl_l.get());
	distanceAnotherVLayout->addLayout(m_controlGrid_ptr.get());
	m_controlGrid_ptr->addWidget(arrowU.get(), 0, 1);
	m_controlGrid_ptr->addWidget(arrowL.get(), 1, 0);
	m_controlGrid_ptr->addWidget(arrowR.get(), 1, 2);
	m_controlGrid_ptr->addWidget(arrowD.get(), 2, 1);

	
	
	//connections
	connect(addCam.get(), &QPushButton::clicked, this, &MainWindow::s_onAdd);
	connect(removeCam.get(), &QPushButton::clicked, this, &MainWindow::s_onRemove);
	connect(m_addWdgt_ptr.get(), &AddCam::sig_onApply, this, &MainWindow::s_onAddApply);
	connect(m_addWdgt_ptr.get(), &AddCam::sig_onCancel, this, &MainWindow::s_onCancel);

	connect(m_listWidget_ptr.get(), &QListWidget::itemActivated, this, &MainWindow::s_onItemActivated);
	connect(turn.get(), &QPushButton::clicked, this, &MainWindow::s_onTurnOn);
	connect(turnOff.get(), &QPushButton::clicked, this, &MainWindow::s_onTurnOff);
	
	connect(this, &MainWindow::sig_setCamData, &m_networkHandler_ptr, &NetworkInator::s_connectToIp);
	connect(this, &MainWindow::sig_release, &m_networkHandler_ptr, &NetworkInator::s_release);
	for(uint8_t i = 0; i < m_bttns_ptr_arr.size(); ++i)
	{
		if(i < 16)	m_joystickData_arr[i] = 0;
		m_bttns_ptr_arr[i]->setId(i);
		qDebug() << i << ": " << m_bttns_ptr_arr[i]->text() << '\n';
//		connect(m_bttns_ptr_arr[i].get(), &PushButton::sig_clicked, this, &MainWindow::s_sendRequest);
		connect(m_bttns_ptr_arr[i].get(), &PushButton::sig_released, &m_networkHandler_ptr, &NetworkInator::s_release);//
		connect(m_bttns_ptr_arr[i].get(), &PushButton::sig_pressed, this, &MainWindow::s_sendRequest);


	}
	connect(this, &MainWindow::sig_sendRequest, &m_networkHandler_ptr, &NetworkInator::s_sendRequest);
	connect(m_joystic_interface.get(), &UsbInator::dataReceived, this, &MainWindow::s_processJoystickData);
	qDebug() << "connections made\n";



}
MainWindow::~MainWindow()
{

}
void MainWindow::s_onAdd()
{
	m_mainWndw_ptr->show();
}
void MainWindow::s_onRemove()
{
	std::shared_ptr<QListWidgetItem> item{m_listWidget_ptr->currentItem()};
	if(item != 0)	m_listWidget_ptr->takeItem(m_listWidget_ptr->row(item.get()));
}
void MainWindow::s_onAddApply(const std::array<QString, 3> &data)
{
	for(QString it : data)	qDebug() << it << '\n';//db
	if(data[0] != "")	
	{
		m_listWidget_ptr->addItem(data[0] + " D");
		m_camsData_vctr.push_back(data);	
		m_listWidget_ptr->setCurrentItem(m_listWidget_ptr->item(m_listWidget_ptr->count() - 1));
//		m_item = std::make_shared<QListWidgetItem>(*m_listWidget_ptr->currentItem());
		emit sig_setCamData(m_camsData_vctr[m_listWidget_ptr->row(m_listWidget_ptr->item(m_listWidget_ptr->count() - 1))]);

		qDebug() << m_listWidget_ptr->row(m_listWidget_ptr->item(m_listWidget_ptr->count() - 1)) << '\n';

	}
}
void MainWindow::s_onCancel()
{
	m_mainWndw_ptr->close();
}
void MainWindow::s_onItemActivated(QListWidgetItem *item_r)
{
//	m_item = std::make_shared<QListWidgetItem>(*item_r);
	emit sig_setCamData(m_camsData_vctr[m_listWidget_ptr->row(item_r)]);
	qDebug() << m_listWidget_ptr->row(item_r) << '\n';

}

void MainWindow::s_onTurnOn()
{
	QString text = m_listWidget_ptr->currentItem()->text();
	if(text != "")
	{
		text[text.size() - 1] = 'E';
		uint8_t row = m_listWidget_ptr->row(m_listWidget_ptr->currentItem());
		m_listWidget_ptr->takeItem(row);
		m_listWidget_ptr->insertItem(row, text);
//		m_item = std::make_shared<QListWidgetItem>(*(m_listWidget_ptr->item(row)));
		m_listWidget_ptr->setCurrentRow(row);
	}
}
void MainWindow::s_onTurnOff()
{
	QString text = m_listWidget_ptr->currentItem()->text();
	if(text != "")
	{
		text[text.size() - 1] = 'D';
		uint8_t row = m_listWidget_ptr->row(m_listWidget_ptr->currentItem());
		m_listWidget_ptr->takeItem(row);
		m_listWidget_ptr->insertItem(row, text);
//		m_item = std::make_shared<QListWidgetItem>(*(m_listWidget_ptr->item(row)));
		m_listWidget_ptr->setCurrentRow(row);
	}
}
void MainWindow::s_sendRequest(int id)
{
	qDebug() << id << '\n';
	emit sig_sendRequest(id);
}
void MainWindow::s_processJoystickData(std::array<bool, 16> &data)
{
	int num = 0;
	for(uint8_t i = 0; i < 16; ++i)
	{
		switch(i)
		{
			case(0):
				num = 17;
				break;
			case(9):
				num = 11;
				break;
			case(10):
				num = 8;
				break;
			case(11):
				num = 9;
				break;
			case(12):
				num = 10;
				break;
			case(13):
				num = 12;
				break;
			case(14):
				num = 13;
				break;
			case(15):
				num = 16;
				break;
		
		}
		if(data[i] != m_joystickData_arr[i])
		{
			if(m_joystickData_arr[i])	emit sig_release(num);//networkinator
			else				emit sig_sendRequest(num);
		}
	}		
	m_joystickData_arr = data;	
}
