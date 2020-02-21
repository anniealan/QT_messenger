#include "chat_widget.hpp"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include <QDebug>

Chat_Widget::Chat_Widget()
{
    m_layout = new QVBoxLayout(this);
    m_input = new QLineEdit(this);
    m_send_btn = new QPushButton("send", this);
    m_history = new QTextEdit(this); 
    m_typing_msg = new QLabel(this); 
    m_layout->addWidget(m_history);
    m_layout->addWidget(m_input);
    m_layout->addWidget(m_typing_msg);
    m_layout->addWidget(m_send_btn);
    setLayout(m_layout);
    connect(m_send_btn, &QPushButton::clicked, this, &Chat_Widget::m_send_msg);
    connect(m_input, &QLineEdit::textChanged, [this](const QString& txt){
        emit typing(txt);
    });
}
Chat_Widget::~Chat_Widget()
{
    qDebug() << "Bye!";
}
void Chat_Widget::receive_msg(QString msg)
{
    if (msg.trimmed().isEmpty()){
        return;
    }
    m_history->setAlignment(Qt::AlignRight);
    m_history->setTextColor(Qt::red);
    m_history->setFontWeight(QFont::Bold);
    m_history->append("Sender :");
    m_history->setTextColor(Qt::black);
    m_history->setFontWeight(QFont::Normal);
    m_history->append(msg + "\n");
}

void Chat_Widget::show_typing(QString txt)
{
    m_typing_msg->setText(txt);
}

void Chat_Widget::m_send_msg() 
{
    QString msg = m_input->text();
    if (msg.trimmed().isEmpty()){
        return;
    }
    m_history->setAlignment(Qt::AlignLeft);
    m_history->setTextColor(Qt::blue);
    m_history->setFontWeight(QFont::Bold);
    m_history->append("You: ");
    m_history->setTextColor(Qt::black);
    m_history->setFontWeight(QFont::Normal);
    m_history->append(msg + "\n");
    emit msg_sent(msg);
    m_input->setText("");
}



