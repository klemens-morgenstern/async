//
// Copyright (c) 2022 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_ASYNC_IMPL_CONCURRENT_HANNEL_IPP
#define BOOST_ASYNC_IMPL_CONCURRENT_HANNEL_IPP

#include <boost/async/concurrent_channel.hpp>

namespace boost::async
{

bool concurrent_channel<void>::  try_receive(std::optional<std::tuple<system::error_code>> & result)
{
  return impl_.try_receive([&](system::error_code ec) { result.emplace(ec);});
}

void concurrent_channel<void>::async_receive(boost::async::detail::completion_handler<system::error_code> h)
{
  impl_.async_receive(std::move(h));
}

bool concurrent_channel<void>::  try_send()
{
  return impl_.try_send(system::error_code());
}

void concurrent_channel<void>::async_send(boost::async::detail::completion_handler<system::error_code> h)
{
  impl_.async_send(system::error_code(), std::move(h));
}


}

#endif //BOOST_ASYNC_IMPL_CONCURRENT_HANNEL_IPP
