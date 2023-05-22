#ifndef ADDCAM_HPP
#define ADDCAM_HPP
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include <array>
#include <memory>

class AddCam : public QWidget
{
Q_OBJECT
public:
	AddCam(QWidget *parent = 0);
private:
	std::shared_ptr<QPushButton> m_applyBttn_ptr;
	std::shared_ptr<QPushButton> m_cancelBttn_ptr;
	std::array<std::shared_ptr<QLineEdit>, 3> m_qle_arr;
	std::array<std::shared_ptr<QLabel>, 3> m_labels_arr;
	std::shared_ptr<QHBoxLayout> m_hbox_ptr;
	std::shared_ptr<QVBoxLayout> m_vbox_ptr;
	std::array<QString, 3> m_data_arr;
private slots:
	void s_onApply();
	void s_onCancel();
signals:
	void sig_onApply(const std::array<QString, 3>&);
	void sig_onCancel();
};
#endif
