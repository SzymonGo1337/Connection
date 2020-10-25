#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

int main() {
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectType, mode;
    char buffer[2000];
    std::size_t received;

    std::string text = "Connected to >> ";

    std::cout << "(S) For Server | (C) For Client" << "\n";
    std::cin >> connectType;
    if(connectType == 's' || connectType == 'S') {
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
        text += "Server";
        mode = 'S';

    } else if(connectType == 'c' || connectType == 'C') {
        socket.connect(ip, 2000);
        text += "Client";
        mode = 'R';

    } else {
        std::cout << "Error" << "\n";
        exit(EXIT_FAILURE);
    }

    socket.send(text.c_str(), text.length() + 1);

    socket.receive(buffer, sizeof(buffer), received);

    std::cout << buffer << "\n";

    bool done = false;

    while(!done) {
        if(mode == 'S') {
            std::getline(std::cin, text);
            socket.send(text.c_str(), text.length() + 1);
            mode = 'R';

        } else if(mode == 'R') {
            socket.receive(buffer, sizeof(buffer), received);
            if(received > 0) {
                std::cout << "Received >> " << buffer << "\n";
                mode = 'S';
            }

        } else {
            std::cout << "Error" << "\n";
            exit(EXIT_FAILURE);
        }
    }


    int pause;
    std::cin >> pause;

    /* sf::RenderWindow window(sf::VideoMode(1280, 720), "Sockets", sf::Style::Titlebar | sf::Style::Close);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();

        window.display();
    }

    return 0; */
}
