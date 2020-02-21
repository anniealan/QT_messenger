#ifndef CHAT_WIDGET_H
#define CHAT_WIDGET_H

#include<QWidget>

class QVBoxLayout;
class QLineEdit;
class QPushButton;
class QLabel;
class QString;
class QTextEdit;

class Chat_Widget : public QWidget
{
    Q_OBJECT
    public:
       Chat_Widget();
       ~Chat_Widget();
    private:
        void m_send_msg();
    private:
        QVBoxLayout *m_layout;
        QLineEdit* m_input;
        QPushButton* m_send_btn;
        QTextEdit* m_history;
        QLabel* m_typing_msg;
    signals:
        void msg_sent(QString txt);
        void typing(QString txt);
    public slots:
        void receive_msg(QString txt);
        void show_typing(QString txt);
};

#endif // CHAT_WIDGET_H