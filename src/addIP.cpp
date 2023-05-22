#include "addIP.hpp"
AddCam::AddCam(QWidget *parent)
{
	m_applyBttn_ptr = std::make_shared<QPushButton>("Apply");
	m_cancelBttn_ptr = std::make_shared<QPushButton>("Cancel");
//	m_qle_ptr = std::make_shared<QLineEdit>();
	m_vbox_ptr = std::make_shared<QVBoxLayout>(this);
	m_hbox_ptr = std::make_shared<QHBoxLayout>();
	m_labels_arr[0] = std::make_shared<QLabel>("IP:");
	m_labels_arr[1] = std::make_shared<QLabel>("Login:");
	m_labels_arr[2] = std::make_shared<QLabel>("Password:");
	for(uint8_t i = 0; i < 3; ++i)
	{
		m_qle_arr[i] = std::make_shared<QLineEdit>();
		m_vbox_ptr->addWidget(m_labels_arr[i].get());
		m_vbox_ptr->addWidget(m_qle_arr[i].get());
	}
	m_vbox_ptr->addLayout(m_hbox_ptr.get());
	m_hbox_ptr->addWidget(m_applyBttn_ptr.get());
	m_hbox_ptr->addWidget(m_cancelBttn_ptr.get());

	connect(m_applyBttn_ptr.get(), &QPushButton::clicked, this, &AddCam::s_onApply);
	connect(m_cancelBttn_ptr.get(), &QPushButton::clicked, this, &AddCam::s_onCancel);

}
void AddCam::s_onApply()
{
//	std::array<QString, 3> data;
	for(uint8_t i = 0; i < 3; ++i)
	{
		m_data_arr[i] = m_qle_arr[i]->text();
	}
	emit sig_onApply(m_data_arr);
	m_qle_arr[0]->setText("");
}
void AddCam::s_onCancel()
{
	m_qle_arr[0]->setText("");
	emit sig_onCancel();
}
