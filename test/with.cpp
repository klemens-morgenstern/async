//
// Copyright (c) 2022 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "boost/async/promise.hpp"
#include <boost/async/with.hpp>

#include "doctest.h"
#include "test.hpp"

TEST_SUITE_BEGIN("with");

namespace asio = boost::asio;

struct finalizer_test
{
    asio::any_io_executor exec;
    using executor_type = asio::any_io_executor;
    executor_type get_executor()
    {
        return exec;
    }

    bool enter_called = false, exit_called = false;
    std::exception_ptr e;

    auto enter()
    {
        enter_called = true;
        return asio::post(exec, asio::deferred);
    }

    auto exit(std::exception_ptr ee)
    {
        exit_called = true;
        e = ee;
        return asio::post(exec, asio::deferred);
    }
};

auto tag_invoke(const boost::async::with_enter_tag & , finalizer_test & ft)
{
    return ft.enter();
}

auto tag_invoke(const boost::async::with_exit_tag & wet , finalizer_test & ft)
{

    return ft.exit(wet.e);
}

auto ft_test(finalizer_test & ft) -> boost::async::promise<void>
{
    co_return ;
}

auto ft_test2(finalizer_test & ft) -> boost::async::promise<void> { throw std::runtime_error("foobar") ; }

CO_TEST_CASE("finalizer")
{
    co_await
            boost::async::with(finalizer_test{co_await asio::this_coro::executor}, &ft_test);

    finalizer_test f1{co_await asio::this_coro::executor};
    co_await boost::async::with(f1, ft_test);
    CHECK(f1.enter_called);
    CHECK(f1.exit_called);

    CHECK(f1.e == nullptr);


    finalizer_test f2{co_await asio::this_coro::executor};

    auto ft2 = +[](finalizer_test & ft) -> boost::async::promise<void> { throw std::runtime_error("foobar") ; };

    try
    {
        co_await boost::async::with(f2, &ft_test2);
    }
    catch (std::runtime_error & re)
    {
        CHECK(re.what() == std::string("foobar"));
    }
    CHECK(f2.enter_called);
    CHECK(f2.exit_called);
    CHECK(f2.e != nullptr);

}


TEST_SUITE_END();