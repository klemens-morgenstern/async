//
// Copyright (c) 2022 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASYNC_IO_IMPL_READ_UNTIL_IPP
#define BOOST_ASYNC_IO_IMPL_READ_UNTIL_IPP

#include <boost/async/io/read_until.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/beast/core/buffer_ref.hpp>
#include <boost/regex.hpp>

namespace boost::async::io::detail
{

void read_until_impl(concepts::read_stream & stream, flat_static_buffer_base &buffer,    match_condition<flat_static_buffer_base> cond, read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_static_buffer_base &buffer,    char delim,                                    read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_static_buffer_base &buffer,    asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_static_buffer_base &buffer,    const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, static_buffer_base &buffer,         match_condition<static_buffer_base> cond,      read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, static_buffer_base &buffer,         char delim,                                    read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, static_buffer_base &buffer,         asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, static_buffer_base &buffer,         const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_buffer &buffer,                match_condition<flat_buffer> cond,             read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_buffer &buffer,                char delim,                                    read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_buffer &buffer,                asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, flat_buffer &buffer,                const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, multi_buffer &buffer,               match_condition<multi_buffer> cond,            read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, multi_buffer &buffer,               char delim,                                    read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, multi_buffer &buffer,               asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, multi_buffer &buffer,               const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, beast::buffer_ref(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::string &buffer,
                     match_condition<asio::dynamic_string_buffer<char, std::char_traits<char>, std::allocator<char>>> cond,             read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::string &buffer,                char delim,                                    read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::string &buffer,                asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::string &buffer,                const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::vector<unsigned char> &buffer,
                     match_condition<asio::dynamic_vector_buffer<unsigned char, std::allocator<unsigned char>>> cond,                   read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::vector<unsigned char> &buffer, char delim,                                    read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::vector<unsigned char> &buffer, asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, std::vector<unsigned char> &buffer, const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, asio::dynamic_buffer(buffer), expr,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, streambuf &buffer,                  match_condition<streambuf>   cond,             read_handler rh) { return asio::async_read_until(stream, buffer, cond,  std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, streambuf &buffer,                  char delim,                                    read_handler rh) { return asio::async_read_until(stream, buffer, delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, streambuf &buffer,                  asio::string_view delim,                       read_handler rh) { return asio::async_read_until(stream, buffer, delim, std::move(rh)); }
void read_until_impl(concepts::read_stream & stream, streambuf &buffer,                  const boost::regex & expr,                     read_handler rh) { return asio::async_read_until(stream, buffer, expr,  std::move(rh)); }

}

#endif //BOOST_ASYNC_IO_IMPL_READ_UNTIL_IPP
