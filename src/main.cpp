#include <QApplication>
#include "chat_widget.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Chat_Widget chat1;
    Chat_Widget chat2;
    app.connect(&chat1, SIGNAL(msg_sent(QString)), &chat2, SLOT(receive_msg(QString)));
    app.connect(&chat2, SIGNAL(msg_sent(QString)), &chat1, SLOT(receive_msg(QString)));
    app.connect(&chat1, SIGNAL(typing(QString)), &chat2, SLOT(show_typing(QString)));    
    app.connect(&chat2, SIGNAL(typing(QString)), &chat1, SLOT(show_typing(QString)));        
    chat1.show();
    chat2.show();
    return app.exec();
}