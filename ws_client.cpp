#include "client_ws.hpp"
#include "server_ws.hpp"
#include "timing_helper.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

using WsClient = SimpleWeb::SocketClient<SimpleWeb::WS>;

const int NUM_TRANSMITS = 10;
int transmits = 0;
TimingHelper th = TimingHelper();
microseconds last_msg_send_time_;

microseconds getCurrentTimeForSending(){
    last_msg_send_time_ = duration_cast< microseconds >(
                system_clock::now().time_since_epoch()
                );
    return last_msg_send_time_;
}

int main() {

    WsClient client("localhost:8080/echo");
    client.on_message = [](shared_ptr<WsClient::Connection> connection, shared_ptr<WsClient::Message> message) {

        microseconds rtt = duration_cast< microseconds >( system_clock::now().time_since_epoch() ) - last_msg_send_time_;
        cout << "Client: Message received: rtt: \"" << rtt.count() << " [µs]\"" << endl;

        auto message_str = message->string();

        th.saveDurationFromGivenStartTillNow(message_str);

        if(transmits >= NUM_TRANSMITS){
            cout << "Client: Sending close connection, transmits: " << transmits << endl;
            connection->send_close(1000);
        }

        string message_out = TimingHelper::getCurrentTimeInMicroSecAsString();
        //cout << "Client: Sending message: \"" << message_out << "\"" << endl;

        getCurrentTimeForSending();
        auto send_stream = make_shared<WsClient::SendStream>();
        *send_stream << message_out;
        connection->send(send_stream);
        transmits++;
    };

    client.on_open = [](shared_ptr<WsClient::Connection> connection) {

        cout << "Client: Opened connection" << endl;

        microseconds ms = getCurrentTimeForSending();
        //std::cout << "now: " << ms.count() << std::endl;

        string message = std::to_string(ms.count());
        //cout << "Client: Sending on_open message: \"" << message << "\"" << endl;

        auto send_stream = make_shared<WsClient::SendStream>();
        *send_stream << message;
        connection->send(send_stream);
    };

    client.on_close = [](shared_ptr<WsClient::Connection> /*connection*/, int status, const string & /*reason*/) {
        cout << "Client: Closed connection with status code " << status << endl;
        th.printStatistics();
    };

    // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
    client.on_error = [](shared_ptr<WsClient::Connection> /*connection*/, const SimpleWeb::error_code &ec) {
        cout << "Client: Error: " << ec << ", error message: " << ec.message() << endl;
    };

    client.start();
}
