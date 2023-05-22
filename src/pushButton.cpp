#include "pushButton.hpp"
PushButton::PushButton(QString text, int id, QWidget *parent) : QPushButton(text, parent), m_id(id)
{
	connect(this, &QPushButton::clicked, this, &PushButton::s_handleClick);
	connect(this, &QPushButton::pressed, this, &PushButton::s_handlePress);
	connect(this, &QPushButton::released, this, &PushButton::s_handleRelease);

}
int PushButton::getId() const
{
	return m_id;
}
void PushButton::setId(int id)
{
	m_id = id;
}
void PushButton::s_handleClick()
{
	emit sig_clicked(m_id);
}
void PushButton::s_handlePress()
{
	emit sig_pressed(m_id);
}
void PushButton::s_handleRelease()
{
	emit sig_released(m_id);
}
