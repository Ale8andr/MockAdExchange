#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/array.hpp>

namespace services {

    class dsp {
    public:
        dsp(boost::asio::io_service &io_service, unsigned short port);

    private:
        void start_signal_wait();

        void handle_signal_wait();

        void start_accept();

        void handle_accept(const boost::system::error_code &ec);

        void start_read();

        void handle_read(const boost::system::error_code &ec, std::size_t length);

        void start_write(std::size_t length);

        void handle_write(const boost::system::error_code &ec);

        boost::asio::io_service &io_service_;
        boost::asio::signal_set signal_;
        boost::asio::ip::tcp::acceptor acceptor_;
        boost::asio::ip::tcp::socket socket_;
        boost::array<char, 1024> data_;
    };
}
