#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include <QPushButton>
#include <QString>
class PushButton : public QPushButton
{
Q_OBJECT
public:
	explicit PushButton(QString text = "", int id = -1, QWidget *parent = 0);
	int getId() const;
	void setId(int);
private:
	int m_id;
private slots:
	void s_handleClick();
	void s_handlePress();
	void s_handleRelease();

signals:
	void sig_clicked(int);
	void sig_pressed(int);
	void sig_released(int);

	
};
#endif
