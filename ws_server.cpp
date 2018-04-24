#include "client_ws.hpp"
#include "server_ws.hpp"
#include "timing_helper.hpp"
#include <chrono>
#include <vector>

using namespace std::chrono;
using namespace std;

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;
using WsClient = SimpleWeb::SocketClient<SimpleWeb::WS>;

TimingHelper th = TimingHelper();
int transmits_ = 0;

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    // WebSocket (WS)-server at port 8080 using 1 thread
    WsServer server;
    server.config.port = 8080;

    auto &echo = server.endpoint["^/echo/?$"];

    echo.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
        auto message_str = message->string();

        cout << "Server: Message received: \"" << message_str << "\" from " << connection.get() << endl;
        auto send_stream = make_shared<WsServer::SendStream>();

        if(message_str.compare("WebClient started")==0){
            *send_stream << "WebClient connected";
        }
        else if(message_str.compare("ping")==0){
            *send_stream << "pong";
        }
        else{
            th.saveDurationFromGivenStartTillNow(message_str);
            transmits_++;

            if(transmits_ == 10){
                th.printStatistics();
                transmits_ = 0;
                th.clearStatistics();
            }

            string message_ms = TimingHelper::getCurrentTimeInMicroSecAsString();
            *send_stream << message_ms;
        }

        // connection->send is an asynchronous function
        connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
            if(ec) {
                cout << "Server: Error sending message. " <<
                        // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
                        "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });
    };

    echo.on_open = [](shared_ptr<WsServer::Connection> connection) {
        cout << "Server: Opened connection " << connection.get() << endl;
    };

    // See RFC 6455 7.4.1. for status codes
    echo.on_close = [](shared_ptr<WsServer::Connection> connection, int status, const string & /*reason*/) {
        cout << "Server: Closed connection " << connection.get() << " with status code " << status << endl;
    };

    // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
    echo.on_error = [](shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
        cout << "Server: Error in connection " << connection.get() << ". "
             << "Error: " << ec << ", error message: " << ec.message() << endl;
    };

    thread server_thread([&server]() {
        // Start WS-server
        server.start();
    });

    // Wait for server to start so that the client can connect
    this_thread::sleep_for(chrono::seconds(1));

    server_thread.join();
}
